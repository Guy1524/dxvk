#pragma once

#include "d3d10_util.h"

namespace dxvk {

  class D3D11Buffer;
  class D3D11Device;
  class D3D10Device;

  class D3D10Buffer : public ID3D10Buffer {

  public:

    D3D10Buffer(D3D11Buffer* pParent, D3D10Device* pDevice)
    : m_device(pDevice), m_d3d11(pParent) { }

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

    void STDMETHODCALLTYPE GetType(
            D3D10_RESOURCE_DIMENSION* rType) FAKE;

    void STDMETHODCALLTYPE SetEvictionPriority(
            UINT                      EvictionPriority) FAKE;

    UINT STDMETHODCALLTYPE GetEvictionPriority() FAKE;

    HRESULT STDMETHODCALLTYPE Map(
            D3D10_MAP                 MapType,
            UINT                      MapFlags,
            void**                    ppData) FAKE;

    void STDMETHODCALLTYPE Unmap() FAKE;

    void STDMETHODCALLTYPE GetDesc(
            D3D10_BUFFER_DESC*        pDesc) FAKE;
    
    D3D11Buffer* GetD3D11Iface() {
      return m_d3d11;
    }

  private:

    D3D10Device* m_device;
    D3D11Buffer* m_d3d11;

  };

}