#include "util_shared_resources.h"

#include <string>
#include <iostream>

#include "util_string.h"

namespace dxvk {
  static const char* baseDirectory = "DXVK_SharedResources";

  std::string DetermineSharedResourceFileName(BOOL bNTHandle, HANDLE hHandle) {
    const char* prefix = bNTHandle ? "NT" : "KMT";
    return str::format(baseDirectory, "\\", prefix, "_HandleId_", hHandle);
  }

  // This will fall apart if they use NT handles (ie. D3D11.1's OpenSharedResource1/CreateSharedHandle) and they duplicate the handles...
  // I do not have a solution for this at the moment.
  bool OpenSharedResourceInfo_Win32Path(BOOL bWrite, BOOL bNTHandle, HANDLE hHandle, D3D11_COMMON_TEXTURE_DESC* pDesc) {
    DWORD mapFlags = bWrite ? GENERIC_WRITE : GENERIC_READ;

    CreateDirectoryA(baseDirectory, nullptr);

    std::string name = DetermineSharedResourceFileName(bNTHandle, hHandle);
    HANDLE file = CreateFileA(name.c_str(), mapFlags, 0, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (file == INVALID_HANDLE_VALUE) {
      Logger::warn(str::format("ReadSharedResource: Failed to open file ", name));
      return false;
    }

    DWORD byteIOCount = 0;
    
    if (bWrite) {
      if (!WriteFile(file, pDesc, sizeof(D3D11_COMMON_TEXTURE_DESC), &byteIOCount, nullptr)) {
        Logger::warn(str::format("ReadSharedResource: Failed to write file ", name));
        CloseHandle(file);
        return false;
      }
    } else{
      if (!ReadFile (file, pDesc, sizeof(D3D11_COMMON_TEXTURE_DESC), &byteIOCount, nullptr)) {
        Logger::warn(str::format("ReadSharedResource: Failed to read file ",  name));
        CloseHandle(file);
        return false;
      }
    }

    CloseHandle(file);

    return true;
  }

  HMODULE GetNTDLLModule() {
    static HMODULE ntdll = LoadLibraryA("ntdll.dll");
    return ntdll;
  }

  using __wine_open_gpu_resource_Type = NTSTATUS(CDECL*)(HANDLE, OBJECT_ATTRIBUTES*, DWORD, HANDLE*);

  NTSTATUS __wine_open_gpu_resource(HANDLE kmtHandle, OBJECT_ATTRIBUTES* attr, DWORD access, HANDLE* handle) {
    static auto func = (__wine_open_gpu_resource_Type)
      GetProcAddress(GetNTDLLModule(), "__wine_open_gpu_resource");

    if (func != nullptr)
      return func(kmtHandle, attr, access, handle);

    throw DxvkError("procedure not found");
  }

  using __wine_get_gpu_resource_info_Type = NTSTATUS(CDECL*)(HANDLE, HANDLE*, void*, unsigned int*);

  NTSTATUS __wine_get_gpu_resource_info(HANDLE handle, HANDLE* kmtHandle, void* userDataBuf, unsigned int* userDataLen) {
    static auto func = (__wine_get_gpu_resource_info_Type)
      GetProcAddress(GetNTDLLModule(), "__wine_get_gpu_resource_info");

    if (func != nullptr)
      return func(handle, kmtHandle, userDataBuf, userDataLen);

    throw DxvkError("procedure not found");
  }

  using __wine_set_gpu_resource_userdata_Type = NTSTATUS(CDECL*)(HANDLE, void*, unsigned int);

  NTSTATUS __wine_set_gpu_resource_userdata(HANDLE handle, void* userData, unsigned int userDataLen) {
    static auto func = (__wine_set_gpu_resource_userdata_Type)
      GetProcAddress(GetNTDLLModule(), "__wine_set_gpu_resource_userdata");

    if (func != nullptr)
      return func(handle, userData, userDataLen);

    throw DxvkError("procedure not found");
  }

  bool OpenSharedResourceInfo_WinePath(BOOL bWrite, BOOL bNTHandle, HANDLE hHandle, D3D11_COMMON_TEXTURE_DESC* pDesc) {
    HANDLE resourceHandle = INVALID_HANDLE_VALUE;
    bool ret = true;

    if (!bNTHandle) {
      if (__wine_open_gpu_resource(hHandle, nullptr, DXGI_SHARED_RESOURCE_READ|DXGI_SHARED_RESOURCE_WRITE, &resourceHandle) < 0) {
        Logger::err("Failed to open handle to resource from KMT handle");
        return false;
      }
    } else {
      resourceHandle = hHandle;
    }

    if (bWrite) {
      ret = __wine_set_gpu_resource_userdata(resourceHandle, pDesc, sizeof(*pDesc)) >= 0;
      if (!ret) Logger::err("Failed to set resource userdata");
    } else {
      unsigned int descLen = sizeof(*pDesc);
      ret = __wine_get_gpu_resource_info(resourceHandle, nullptr, pDesc, &descLen) >= 0 && descLen == sizeof(*pDesc);
      if (!ret) Logger::err("Failed to retrieve resource userdata");
    }

    if (!bNTHandle)
      CloseHandle(resourceHandle);
    return ret;
  }

  bool OpenSharedResourceInfo(BOOL bWrite, BOOL bNTHandle, HANDLE hHandle, D3D11_COMMON_TEXTURE_DESC* pDesc) {
    try
    {
      return OpenSharedResourceInfo_WinePath(bWrite, bNTHandle, hHandle, pDesc);
    }
    catch(const DxvkError& e)
    {
      Logger::warn("Wine helpers for shared resources not found, falling back to less accurate version.");
      return OpenSharedResourceInfo_Win32Path(bWrite, bNTHandle, hHandle, pDesc);
    }
  }

  void CleanupSharedResourceInfo(BOOL bNtHandle, HANDLE hHandle)
  {
    std::string name = DetermineSharedResourceFileName(bNtHandle, hHandle);
    DeleteFileA(name.c_str());
  }
}