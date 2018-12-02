#include "dxgi_factory.h"
#include "dxgi_include.h"

#include <csignal>

namespace dxvk {
  
#ifdef DXVK_NATIVE
    void error_callback(int code, const char* description)
    {
      Logger::err( str::format("GLFW3 error.  code=", code, " description=", description));

      std::raise(SIGINT);
    }
#endif

  Logger Logger::s_instance("dxgi.log");
  
  HRESULT createDxgiFactory(UINT Flags, REFIID riid, void **ppFactory) {
    #ifdef DXVK_NATIVE
      glfwSetErrorCallback(error_callback);
    #endif
    
    Com<DxgiFactory> factory = new DxgiFactory(Flags);
    HRESULT hr = factory->QueryInterface(riid, ppFactory);

    if (FAILED(hr))
      return DXGI_ERROR_UNSUPPORTED;
    
    return S_OK;
  }
}

#ifndef DXVK_NATIVE
extern "C" {
#endif
  DLLEXPORT HRESULT __stdcall CreateDXGIFactory2(UINT Flags, REFIID riid, void **ppFactory) {
    dxvk::Logger::warn("CreateDXGIFactory2: Ignoring flags");
    return dxvk::createDxgiFactory(Flags, riid, ppFactory);
  }

  DLLEXPORT HRESULT __stdcall CreateDXGIFactory1(REFIID riid, void **ppFactory) {
    return dxvk::createDxgiFactory(0, riid, ppFactory);
  }
  
  DLLEXPORT HRESULT __stdcall CreateDXGIFactory(REFIID riid, void **ppFactory) {
    return dxvk::createDxgiFactory(0, riid, ppFactory);
  }
#ifndef DXVK_NATIVE
}
#endif