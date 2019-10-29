#pragma once

#include "../d3d11/d3d11_texture.h"

typedef *OBJECT_ATTRIBUTES;

namespace dxvk {
  using NTSTATUS = LONG;

  bool OpenSharedResourceInfo(BOOL bWrite, BOOL bNTHandle, HANDLE hHandle, D3D11_COMMON_TEXTURE_DESC* pDesc);
  // Only does anything when using the win32 path
  void CleanupSharedResourceInfo(BOOL bNtHandle, HANDLE hHandle);

  using __wine_open_gpu_resource_Type = NTSTATUS(CDECL*) (HANDLE, OBJECT_ATTRIBUTES*, DWORD, HANDLE*);
  NTSTATUS __wine_open_gpu_resource(HANDLE kmtHandle, OBJECT_ATTRIBUTES* attr, DWORD access, HANDLE* handle);

  using __wine_get_gpu_resource_info_Type = NTSTATUS(CDECL*) (HANDLE, HANDLE*, void*, unsigned int*);
  NTSTATUS __wine_get_gpu_resource_info(HANDLE handle, HANDLE* kmtHandle, void* userDataBuf, unsigned int* userDataLen);

  using __wine_set_gpu_resource_userdata_Type = NTSTATUS(CDECL*) (HANDLE, void*, unsigned int);
  NTSTATUS __wine_set_gpu_resource_userdata(HANDLE handle, void* userData, unsigned int userDataLen);

}