#include "util_env.h"
#include <vector>

#ifdef DXVK_NATIVE
#include <cstdlib>

#include <sys/prctl.h>

extern const char *__progname;
#endif

#include "./com/com_include.h"

namespace dxvk::env {

  std::string getEnvVar(const std::string& name) {
#ifndef DXVK_NATIVE
    int nameLen = ::MultiByteToWideChar(CP_ACP, 0, name.c_str(), name.length() + 1, nullptr, 0);

    std::vector<WCHAR> wideName(nameLen);

    ::MultiByteToWideChar(CP_ACP, 0, name.c_str(), name.length() + 1, wideName.data(), nameLen);

    DWORD len = ::GetEnvironmentVariableW(wideName.data(), nullptr, 0);
    
    std::vector<WCHAR> result;
    
    while (len > result.size()) {
      result.resize(len);
      len = ::GetEnvironmentVariableW(
        wideName.data(), result.data(), result.size());
    }
    
    result.resize(len);
    return str::fromws(result.data());
#else
    const char *result = std::getenv(name.c_str());
    if(!result) return "";
    return std::string(result);
#endif
  }
  
  
  std::string getExeName() {
#ifndef DXVK_NATIVE
    std::vector<WCHAR> exePath;
    exePath.resize(MAX_PATH + 1);
    
    DWORD len = ::GetModuleFileNameW(NULL, exePath.data(), MAX_PATH);
    exePath.resize(len);
    
    std::string fullPath = str::fromws(exePath.data());
    auto n = fullPath.find_last_of('\\');
    
    return (n != std::string::npos)
      ? fullPath.substr(n + 1)
      : fullPath;
#else
    return std::string(__progname);
#endif
  }
  
  
  void setThreadName(const std::string& name) {
#ifndef DXVK_NATIVE
    int nameLen = ::MultiByteToWideChar(CP_ACP, 0, name.c_str(), name.length() + 1, nullptr, 0);
    std::vector<WCHAR> wideName(nameLen);
    ::MultiByteToWideChar(CP_ACP, 0, name.c_str(), name.length() + 1, wideName.data(), nameLen);

    using SetThreadDescriptionProc = void (WINAPI *) (HANDLE, PCWSTR);

    HMODULE module = ::GetModuleHandleW(L"kernel32.dll");

    if (module == nullptr)
      return;

    auto proc = reinterpret_cast<SetThreadDescriptionProc>(
      ::GetProcAddress(module, "SetThreadDescription"));

    if (proc != nullptr)
      (*proc)(::GetCurrentThread(), wideName.data());
#else
    prctl( PR_SET_NAME, name.c_str() );
#endif
  }
  
}
