#pragma once

#include "d3d10_include.h"

namespace dxvk {

  using D3D10DeviceMutex = sync::Spinlock;
  using D3D10DeviceLock = std::unique_lock<D3D10DeviceMutex>;
  
  class D3D11Device;
  class D3D11ImmediateContext;

  class D3D10Device final : public ID3D10Device1 {

  public:

    D3D10Device(
            D3D11Device*                      pDevice,
            D3D11ImmediateContext*            pContext) FAKE;
    
    ~D3D10Device() FAKE;

    HRESULT STDMETHODCALLTYPE QueryInterface(
            REFIID                            riid,
            void**                            ppvObject) FAKE;

    ULONG STDMETHODCALLTYPE AddRef() FAKE;

    ULONG STDMETHODCALLTYPE Release() FAKE;

    HRESULT STDMETHODCALLTYPE GetPrivateData(
            REFGUID                           guid,
            UINT*                             pDataSize,
            void*                             pData) FAKE;

    HRESULT STDMETHODCALLTYPE SetPrivateData(
            REFGUID                           guid,
            UINT                              DataSize,
      const void*                             pData) FAKE;

    HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
            REFGUID                           guid,
      const IUnknown*                         pData) FAKE;

    HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason() FAKE;

    HRESULT STDMETHODCALLTYPE SetExceptionMode(
            UINT                              RaiseFlags) FAKE;

    UINT STDMETHODCALLTYPE GetExceptionMode() FAKE;

    D3D10_FEATURE_LEVEL1 STDMETHODCALLTYPE GetFeatureLevel() FAKE;

    void STDMETHODCALLTYPE ClearState() FAKE;

    void STDMETHODCALLTYPE Flush() FAKE;

    HRESULT STDMETHODCALLTYPE CreateBuffer(
      const D3D10_BUFFER_DESC*                pDesc,
      const D3D10_SUBRESOURCE_DATA*           pInitialData,
            ID3D10Buffer**                    ppBuffer) FAKE;

    HRESULT STDMETHODCALLTYPE CreateTexture1D(
      const D3D10_TEXTURE1D_DESC*             pDesc,
      const D3D10_SUBRESOURCE_DATA*           pInitialData,
            ID3D10Texture1D**                 ppTexture1D) FAKE;

    HRESULT STDMETHODCALLTYPE CreateTexture2D(
      const D3D10_TEXTURE2D_DESC*             pDesc,
      const D3D10_SUBRESOURCE_DATA*           pInitialData,
            ID3D10Texture2D**                 ppTexture2D) FAKE;

    HRESULT STDMETHODCALLTYPE CreateTexture3D(
      const D3D10_TEXTURE3D_DESC*             pDesc,
      const D3D10_SUBRESOURCE_DATA*           pInitialData,
            ID3D10Texture3D**                 ppTexture3D) FAKE;

    HRESULT STDMETHODCALLTYPE CreateShaderResourceView(
            ID3D10Resource*                   pResource,
      const D3D10_SHADER_RESOURCE_VIEW_DESC*  pDesc,
            ID3D10ShaderResourceView**        ppSRView) FAKE;

    HRESULT STDMETHODCALLTYPE CreateShaderResourceView1(
            ID3D10Resource*                   pResource,
      const D3D10_SHADER_RESOURCE_VIEW_DESC1* pDesc,
            ID3D10ShaderResourceView1**       ppSRView) FAKE;

    HRESULT STDMETHODCALLTYPE CreateRenderTargetView(
            ID3D10Resource*                   pResource,
      const D3D10_RENDER_TARGET_VIEW_DESC*    pDesc,
            ID3D10RenderTargetView**          ppRTView) FAKE;

    HRESULT STDMETHODCALLTYPE CreateDepthStencilView(
            ID3D10Resource*                   pResource,
      const D3D10_DEPTH_STENCIL_VIEW_DESC*    pDesc,
            ID3D10DepthStencilView**          ppDepthStencilView) FAKE;

    HRESULT STDMETHODCALLTYPE CreateInputLayout(
      const D3D10_INPUT_ELEMENT_DESC*         pInputElementDescs,
            UINT                              NumElements,
      const void*                             pShaderBytecodeWithInputSignature,
            SIZE_T                            BytecodeLength,
            ID3D10InputLayout**               ppInputLayout) FAKE;

    HRESULT STDMETHODCALLTYPE CreateVertexShader(
      const void*                             pShaderBytecode,
            SIZE_T                            BytecodeLength,
            ID3D10VertexShader**              ppVertexShader) FAKE;

    HRESULT STDMETHODCALLTYPE CreateGeometryShader(
      const void*                             pShaderBytecode,
            SIZE_T                            BytecodeLength,
            ID3D10GeometryShader**            ppGeometryShader) FAKE;

    HRESULT STDMETHODCALLTYPE CreateGeometryShaderWithStreamOutput(
      const void*                             pShaderBytecode,
            SIZE_T                            BytecodeLength,
      const D3D10_SO_DECLARATION_ENTRY*       pSODeclaration,
            UINT                              NumEntries,
            UINT                              OutputStreamStride,
            ID3D10GeometryShader**            ppGeometryShader) FAKE;

    HRESULT STDMETHODCALLTYPE CreatePixelShader(
      const void*                             pShaderBytecode,
            SIZE_T                            BytecodeLength,
            ID3D10PixelShader**               ppPixelShader) FAKE;

    HRESULT STDMETHODCALLTYPE CreateBlendState(
      const D3D10_BLEND_DESC*                 pBlendStateDesc,
            ID3D10BlendState**                ppBlendState) FAKE;

    HRESULT STDMETHODCALLTYPE CreateBlendState1(
      const D3D10_BLEND_DESC1*                pBlendStateDesc,
            ID3D10BlendState1**               ppBlendState) FAKE;

    HRESULT STDMETHODCALLTYPE CreateDepthStencilState(
      const D3D10_DEPTH_STENCIL_DESC*         pDepthStencilDesc,
            ID3D10DepthStencilState**         ppDepthStencilState) FAKE;

    HRESULT STDMETHODCALLTYPE CreateRasterizerState(
      const D3D10_RASTERIZER_DESC*            pRasterizerDesc,
            ID3D10RasterizerState**           ppRasterizerState) FAKE;

    HRESULT STDMETHODCALLTYPE CreateSamplerState(
      const D3D10_SAMPLER_DESC*               pSamplerDesc,
            ID3D10SamplerState**              ppSamplerState) FAKE;

    HRESULT STDMETHODCALLTYPE CreateQuery(
      const D3D10_QUERY_DESC*                 pQueryDesc,
            ID3D10Query**                     ppQuery) FAKE;

    HRESULT STDMETHODCALLTYPE CreatePredicate(
      const D3D10_QUERY_DESC*                 pPredicateDesc,
            ID3D10Predicate**                 ppPredicate) FAKE;

    HRESULT STDMETHODCALLTYPE CreateCounter(
      const D3D10_COUNTER_DESC*               pCounterDesc,
            ID3D10Counter**                   ppCounter) FAKE;

    HRESULT STDMETHODCALLTYPE CheckFormatSupport(
            DXGI_FORMAT                       Format,
            UINT*                             pFormatSupport) FAKE;

    HRESULT STDMETHODCALLTYPE CheckMultisampleQualityLevels(
            DXGI_FORMAT                       Format,
            UINT                              SampleCount,
            UINT*                             pNumQualityLevels) FAKE;

    void STDMETHODCALLTYPE CheckCounterInfo(
            D3D10_COUNTER_INFO*               pCounterInfo) FAKE;

    HRESULT STDMETHODCALLTYPE CheckCounter(
      const D3D10_COUNTER_DESC*               pDesc,
            D3D10_COUNTER_TYPE*               pType,
            UINT*                             pActiveCounters,
            char*                             name,
            UINT*                             pNameLength,
            char*                             units,
            UINT*                             pUnitsLength,
            char*                             description,
            UINT*                             pDescriptionLength) FAKE;

    UINT STDMETHODCALLTYPE GetCreationFlags() FAKE;

    HRESULT STDMETHODCALLTYPE OpenSharedResource(
            HANDLE                            hResource,
            REFIID                            ReturnedInterface,
            void**                            ppResource) FAKE;

    void STDMETHODCALLTYPE ClearRenderTargetView(
            ID3D10RenderTargetView*           pRenderTargetView,
      const FLOAT                             ColorRGBA[4]) FAKE;

    void STDMETHODCALLTYPE ClearDepthStencilView(
            ID3D10DepthStencilView*           pDepthStencilView,
            UINT                              ClearFlags,
            FLOAT                             Depth,
            UINT8                             Stencil) FAKE;

    void STDMETHODCALLTYPE SetPredication(
            ID3D10Predicate*                  pPredicate,
            BOOL                              PredicateValue) FAKE;

    void STDMETHODCALLTYPE GetPredication(
            ID3D10Predicate**                 ppPredicate,
            BOOL*                             pPredicateValue) FAKE;

    void STDMETHODCALLTYPE CopySubresourceRegion(
            ID3D10Resource*                   pDstResource,
            UINT                              DstSubresource,
            UINT                              DstX,
            UINT                              DstY,
            UINT                              DstZ,
            ID3D10Resource*                   pSrcResource,
            UINT                              SrcSubresource,
      const D3D10_BOX*                        pSrcBox) FAKE;

    void STDMETHODCALLTYPE CopyResource(
            ID3D10Resource*                   pDstResource,
            ID3D10Resource*                   pSrcResource) FAKE;

    void STDMETHODCALLTYPE UpdateSubresource(
            ID3D10Resource*                   pDstResource,
            UINT                              DstSubresource,
      const D3D10_BOX*                        pDstBox,
      const void*                             pSrcData,
            UINT                              SrcRowPitch,
            UINT                              SrcDepthPitch) FAKE;

    void STDMETHODCALLTYPE GenerateMips(
            ID3D10ShaderResourceView*         pShaderResourceView) FAKE;

    void STDMETHODCALLTYPE ResolveSubresource(
            ID3D10Resource*                   pDstResource,
            UINT                              DstSubresource,
            ID3D10Resource*                   pSrcResource,
            UINT                              SrcSubresource,
            DXGI_FORMAT                       Format) FAKE;

    void STDMETHODCALLTYPE Draw(
            UINT                              VertexCount,
            UINT                              StartVertexLocation) FAKE;

    void STDMETHODCALLTYPE DrawIndexed(
            UINT                              IndexCount,
            UINT                              StartIndexLocation,
            INT                               BaseVertexLocation) FAKE;

    void STDMETHODCALLTYPE DrawInstanced(
            UINT                              VertexCountPerInstance,
            UINT                              InstanceCount,
            UINT                              StartVertexLocation,
            UINT                              StartInstanceLocation) FAKE;

    void STDMETHODCALLTYPE DrawIndexedInstanced(
            UINT                              IndexCountPerInstance,
            UINT                              InstanceCount,
            UINT                              StartIndexLocation,
            INT                               BaseVertexLocation,
            UINT                              StartInstanceLocation) FAKE;

    void STDMETHODCALLTYPE DrawAuto() FAKE;

    void STDMETHODCALLTYPE IASetInputLayout(
            ID3D10InputLayout*                pInputLayout) FAKE;

    void STDMETHODCALLTYPE IASetPrimitiveTopology(
            D3D10_PRIMITIVE_TOPOLOGY          Topology) FAKE;

    void STDMETHODCALLTYPE IASetVertexBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer* const*              ppVertexBuffers,
      const UINT*                             pStrides,
      const UINT*                             pOffsets) FAKE;

    void STDMETHODCALLTYPE IASetIndexBuffer(
            ID3D10Buffer*                     pIndexBuffer,
            DXGI_FORMAT                       Format,
            UINT                              Offset) FAKE;

    void STDMETHODCALLTYPE IAGetInputLayout(
            ID3D10InputLayout**               ppInputLayout) FAKE;

    void STDMETHODCALLTYPE IAGetPrimitiveTopology(
            D3D10_PRIMITIVE_TOPOLOGY*         pTopology) FAKE;

    void STDMETHODCALLTYPE IAGetVertexBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer**                    ppVertexBuffers,
            UINT*                             pStrides,
            UINT*                             pOffsets) FAKE;

    void STDMETHODCALLTYPE IAGetIndexBuffer(
            ID3D10Buffer**                    pIndexBuffer,
            DXGI_FORMAT*                      Format,
            UINT*                             Offset) FAKE;

    void STDMETHODCALLTYPE VSSetShader(
            ID3D10VertexShader*               pVertexShader) FAKE;

    void STDMETHODCALLTYPE VSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer* const*              ppConstantBuffers) FAKE;

    void STDMETHODCALLTYPE VSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D10ShaderResourceView* const*  ppShaderResourceViews) FAKE;

    void STDMETHODCALLTYPE VSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D10SamplerState* const*        ppSamplers) FAKE;

    void STDMETHODCALLTYPE VSGetShader(
            ID3D10VertexShader**              ppVertexShader) FAKE;

    void STDMETHODCALLTYPE VSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer**                    ppConstantBuffers) FAKE;

    void STDMETHODCALLTYPE VSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D10ShaderResourceView**        ppShaderResourceViews) FAKE;

    void STDMETHODCALLTYPE VSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D10SamplerState**              ppSamplers) FAKE;

    void STDMETHODCALLTYPE GSSetShader(
            ID3D10GeometryShader*             pShader) FAKE;

    void STDMETHODCALLTYPE GSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer* const*              ppConstantBuffers) FAKE;

    void STDMETHODCALLTYPE GSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D10ShaderResourceView* const*  ppShaderResourceViews) FAKE;

    void STDMETHODCALLTYPE GSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D10SamplerState* const*        ppSamplers) FAKE;

    void STDMETHODCALLTYPE GSGetShader(
            ID3D10GeometryShader**            ppGeometryShader) FAKE;

    void STDMETHODCALLTYPE GSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer**                    ppConstantBuffers) FAKE;

    void STDMETHODCALLTYPE GSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D10ShaderResourceView**        ppShaderResourceViews) FAKE;

    void STDMETHODCALLTYPE GSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D10SamplerState**              ppSamplers) FAKE;

    void STDMETHODCALLTYPE PSSetShader(
            ID3D10PixelShader*                pPixelShader) FAKE;

    void STDMETHODCALLTYPE PSSetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer* const*              ppConstantBuffers) FAKE;

    void STDMETHODCALLTYPE PSSetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D10ShaderResourceView* const*  ppShaderResourceViews) FAKE;

    void STDMETHODCALLTYPE PSSetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D10SamplerState* const*        ppSamplers) FAKE;

    void STDMETHODCALLTYPE PSGetShader(
            ID3D10PixelShader**               ppPixelShader) FAKE;

    void STDMETHODCALLTYPE PSGetConstantBuffers(
            UINT                              StartSlot,
            UINT                              NumBuffers,
            ID3D10Buffer**                    ppConstantBuffers) FAKE;

    void STDMETHODCALLTYPE PSGetShaderResources(
            UINT                              StartSlot,
            UINT                              NumViews,
            ID3D10ShaderResourceView**        ppShaderResourceViews) FAKE;

    void STDMETHODCALLTYPE PSGetSamplers(
            UINT                              StartSlot,
            UINT                              NumSamplers,
            ID3D10SamplerState**              ppSamplers) FAKE;

    void STDMETHODCALLTYPE OMSetRenderTargets(
            UINT                              NumViews,
            ID3D10RenderTargetView* const*    ppRenderTargetViews,
            ID3D10DepthStencilView*           pDepthStencilView) FAKE;

    void STDMETHODCALLTYPE OMSetBlendState(
            ID3D10BlendState*                 pBlendState,
      const FLOAT                             BlendFactor[4],
            UINT                              SampleMask) FAKE;

    void STDMETHODCALLTYPE OMSetDepthStencilState(
            ID3D10DepthStencilState*          pDepthStencilState,
            UINT                              StencilRef) FAKE;

    void STDMETHODCALLTYPE OMGetRenderTargets(
            UINT                              NumViews,
            ID3D10RenderTargetView**          ppRenderTargetViews,
            ID3D10DepthStencilView**          ppDepthStencilView) FAKE;

    void STDMETHODCALLTYPE OMGetBlendState(
            ID3D10BlendState**                ppBlendState,
            FLOAT                             BlendFactor[4],
            UINT*                             pSampleMask) FAKE;

    void STDMETHODCALLTYPE OMGetDepthStencilState(
            ID3D10DepthStencilState**         ppDepthStencilState,
            UINT*                             pStencilRef) FAKE;

    void STDMETHODCALLTYPE RSSetState(
            ID3D10RasterizerState*            pRasterizerState) FAKE;

    void STDMETHODCALLTYPE RSSetViewports(
            UINT                              NumViewports,
      const D3D10_VIEWPORT*                   pViewports) FAKE;

    void STDMETHODCALLTYPE RSSetScissorRects(
            UINT                              NumRects,
      const D3D10_RECT*                       pRects) FAKE;

    void STDMETHODCALLTYPE RSGetState(
            ID3D10RasterizerState**           ppRasterizerState) FAKE;

    void STDMETHODCALLTYPE RSGetViewports(
            UINT*                             NumViewports,
            D3D10_VIEWPORT*                   pViewports) FAKE;

    void STDMETHODCALLTYPE RSGetScissorRects(
            UINT*                             NumRects,
            D3D10_RECT*                       pRects) FAKE;

    void STDMETHODCALLTYPE SOSetTargets(
            UINT                              NumBuffers,
            ID3D10Buffer* const*              ppSOTargets,
      const UINT*                             pOffsets) FAKE;

    void STDMETHODCALLTYPE SOGetTargets(
            UINT                              NumBuffers,
            ID3D10Buffer**                    ppSOTargets,
            UINT*                             pOffsets) FAKE;

    void STDMETHODCALLTYPE SetTextFilterSize(
            UINT                              Width,
            UINT                              Height) FAKE;

    void STDMETHODCALLTYPE GetTextFilterSize(
            UINT*                             pWidth,
            UINT*                             pHeight) FAKE;
    
    D3D10DeviceLock LockDevice() {
      return m_threadSafe
        ? D3D10DeviceLock(m_mutex)
        : D3D10DeviceLock();
    }
    
  private:

    D3D10DeviceMutex        m_mutex;
    D3D11Device*            m_device;
    D3D11ImmediateContext*  m_context;

    bool m_threadSafe = true;

  };

}