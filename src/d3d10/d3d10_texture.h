#pragma once

#include "d3d10_util.h"

namespace dxvk {

  class D3D10Device;
  class D3D11Device;
  class D3D11Texture1D;
  class D3D11Texture2D;
  class D3D11Texture3D;

  ///////////////////////////////////////////
  //      D 3 D 1 0 T E X T U R E 1 D
  class D3D10Texture1D : public ID3D10Texture1D {

  public:

    D3D10Texture1D(D3D11Texture1D* pParent, D3D10Device* pDevice)
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
            UINT                      Subresource,
            D3D10_MAP                 MapType,
            UINT                      MapFlags,
            void**                    ppData) FAKE;

    void STDMETHODCALLTYPE Unmap(
            UINT                      Subresource) FAKE;

    void STDMETHODCALLTYPE GetDesc(
            D3D10_TEXTURE1D_DESC*     pDesc) FAKE;
    
    D3D11Texture1D* GetD3D11Iface() {
      return m_d3d11;
    }
    
  private:

    D3D10Device*    m_device;
    D3D11Texture1D* m_d3d11;

  };


  ///////////////////////////////////////////
  //      D 3 D 1 0 T E X T U R E 2 D
  class D3D10Texture2D : public ID3D10Texture2D {

  public:

    D3D10Texture2D(D3D11Texture2D* pParent, D3D10Device* pDevice)
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
            UINT                      Subresource,
            D3D10_MAP                 MapType,
            UINT                      MapFlags,
            D3D10_MAPPED_TEXTURE2D*   pMappedTex2D) FAKE;

    void STDMETHODCALLTYPE Unmap(
            UINT                      Subresource) FAKE;

    void STDMETHODCALLTYPE GetDesc(
            D3D10_TEXTURE2D_DESC*     pDesc) FAKE;
    
    D3D11Texture2D* GetD3D11Iface() {
      return m_d3d11;
    }

  private:

    D3D10Device*    m_device;
    D3D11Texture2D* m_d3d11;

  };


  ///////////////////////////////////////////
  //      D 3 D 1 0 T E X T U R E 3 D
  class D3D10Texture3D : public ID3D10Texture3D {

  public:

    D3D10Texture3D(D3D11Texture3D* pParent, D3D10Device* pDevice)
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
            UINT                      Subresource,
            D3D10_MAP                 MapType,
            UINT                      MapFlags,
            D3D10_MAPPED_TEXTURE3D*   pMappedTex3D) FAKE;

    void STDMETHODCALLTYPE Unmap(
            UINT                      Subresource) FAKE;

    void STDMETHODCALLTYPE GetDesc(
            D3D10_TEXTURE3D_DESC*     pDesc) FAKE;
    
    D3D11Texture3D* GetD3D11Iface() {
      return m_d3d11;
    }

  private:

    D3D10Device*    m_device;
    D3D11Texture3D* m_d3d11;

  };

}