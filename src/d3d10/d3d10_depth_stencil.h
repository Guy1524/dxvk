#pragma once

#include "d3d10_util.h"

namespace dxvk {

  class D3D11DepthStencilState;
  class D3D11Device;

  class D3D10DepthStencilState : public ID3D10DepthStencilState {

  public:

    D3D10DepthStencilState(D3D11DepthStencilState* pParent)
    : m_d3d11(pParent) { }

    HRESULT STDMETHODCALLTYPE QueryInterface(
            REFIID                    riid,
            void**                    ppvObject) FAKE;

    ULONG STDMETHODCALLTYPE AddRef() FAKE;

    ULONG STDMETHODCALLTYPE Release() FAKE;

    void STDMETHODCALLTYPE GetDevice(
            ID3D10Device**            ppDevice) FAKE;

    HRESULT STDMETHODCALLTYPE GetPrivateData(
            REFGUID                   guid,
            UINT*                     pDataSize,
            void*                     pData) FAKE;

    HRESULT STDMETHODCALLTYPE SetPrivateData(
            REFGUID                   guid,
            UINT                      DataSize,
      const void*                     pData) FAKE;

    HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
            REFGUID                   guid,
      const IUnknown*                 pData) FAKE;
    
    void STDMETHODCALLTYPE GetDesc(
            D3D10_DEPTH_STENCIL_DESC* pDesc) FAKE;

    D3D11DepthStencilState* GetD3D11Iface() {
      return m_d3d11;
    }
    
  private:

    D3D11DepthStencilState* m_d3d11;

  };

}