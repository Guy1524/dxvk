#ifndef D3D11_1_H
#define D3D11_1_H

/*
 * Copyright 2014 Jacek Caban for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

//import "oaidl.idl";
//import "ocidl.idl";
#include <dxgi1_2.h>
#include <d3dcommon.h>
#include <d3d11.h>

typedef enum D3D11_LOGIC_OP
{
    D3D11_LOGIC_OP_CLEAR = 0,
    D3D11_LOGIC_OP_SET,
    D3D11_LOGIC_OP_COPY,
    D3D11_LOGIC_OP_COPY_INVERTED,
    D3D11_LOGIC_OP_NOOP,
    D3D11_LOGIC_OP_INVERT,
    D3D11_LOGIC_OP_AND,
    D3D11_LOGIC_OP_NAND,
    D3D11_LOGIC_OP_OR,
    D3D11_LOGIC_OP_NOR,
    D3D11_LOGIC_OP_XOR,
    D3D11_LOGIC_OP_EQUIV,
    D3D11_LOGIC_OP_AND_REVERSE,
    D3D11_LOGIC_OP_AND_INVERTED,
    D3D11_LOGIC_OP_OR_REVERSE,
    D3D11_LOGIC_OP_OR_INVERTED
} D3D11_LOGIC_OP;

typedef enum D3D11_COPY_FLAGS
{
    D3D11_COPY_NO_OVERWRITE                                                         = 0x00000001,
    D3D11_COPY_DISCARD                                                              = 0x00000002,
} D3D11_COPY_FLAGS;

typedef enum D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG
{
    D3D11_1_CREATE_DEVICE_CONTEXT_STATE_SINGLETHREADED                              = 0x1,
} D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG;

typedef enum D3D11_VIDEO_DECODER_CAPS
{
    D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE                                             = 0x01,
    D3D11_VIDEO_DECODER_CAPS_NON_REAL_TIME                                          = 0x02,
    D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE_DYNAMIC                                     = 0x04,
    D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE_REQUIRED                                    = 0x08,
    D3D11_VIDEO_DECODER_CAPS_UNSUPPORTED                                            = 0x10,
} D3D11_VIDEO_DECODER_CAPS;

typedef enum D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINTS
{
    D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_ROTATION                 = 0x01,
    D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_RESIZE                   = 0x02,
    D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_COLOR_SPACE_CONVERSION   = 0x04,
    D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_TRIPLE_BUFFER_OUTPUT                        = 0x08,
} D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINTS;

typedef enum D3D11_CRYPTO_SESSION_STATUS
{
    D3D11_CRYPTO_SESSION_STATUS_OK                                                  = 0x0,
    D3D11_CRYPTO_SESSION_STATUS_KEY_LOST                                            = 0x1,
    D3D11_CRYPTO_SESSION_STATUS_KEY_AND_CONTENT_LOST                                = 0x2,
} D3D11_CRYPTO_SESSION_STATUS;

typedef struct D3D11_RENDER_TARGET_BLEND_DESC1
{
    BOOL           BlendEnable;
    BOOL           LogicOpEnable;
    D3D11_BLEND    SrcBlend;
    D3D11_BLEND    DestBlend;
    D3D11_BLEND_OP BlendOp;
    D3D11_BLEND    SrcBlendAlpha;
    D3D11_BLEND    DestBlendAlpha;
    D3D11_BLEND_OP BlendOpAlpha;
    D3D11_LOGIC_OP LogicOp;
    UINT8          RenderTargetWriteMask;
} D3D11_RENDER_TARGET_BLEND_DESC1;

typedef struct D3D11_BLEND_DESC1
{
    BOOL                            AlphaToCoverageEnable;
    BOOL                            IndependentBlendEnable;
    D3D11_RENDER_TARGET_BLEND_DESC1 RenderTarget[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
} D3D11_BLEND_DESC1;

typedef struct D3D11_RASTERIZER_DESC1
{
    D3D11_FILL_MODE FillMode;
    D3D11_CULL_MODE CullMode;
    BOOL            FrontCounterClockwise;
    INT             DepthBias;
    FLOAT           DepthBiasClamp;
    FLOAT           SlopeScaledDepthBias;
    BOOL            DepthClipEnable;
    BOOL            ScissorEnable;
    BOOL            MultisampleEnable;
    BOOL            AntialiasedLineEnable;
    UINT            ForcedSampleCount;
} D3D11_RASTERIZER_DESC1;

typedef struct D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK
{
    UINT ClearSize;
    UINT EncryptedSize;
} D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK;

typedef struct D3D11_VIDEO_DECODER_BUFFER_DESC1
{
    D3D11_VIDEO_DECODER_BUFFER_TYPE BufferType;
    UINT DataOffset;
    UINT DataSize;
    void *pIV;
    UINT IVSize;
    D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK *pSubSampleMappingBlock;
    UINT SubSampleMappingCount;
} D3D11_VIDEO_DECODER_BUFFER_DESC1;

typedef struct D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION
{
    ID3D11CryptoSession *pCryptoSession;
    UINT BlobSize;
    void *pBlob;
    GUID *pKeyInfoId;
    UINT PrivateDataSize;
    void *pPrivateData;
} D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION;

typedef struct D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT
{
    BOOL Enable;
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
} D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT;

typedef struct D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA
{
    UINT PrivateDataSize;
    UINT HWProtectionDataSize;
    BYTE pbInput[4];
} D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA;

typedef struct D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA
{
    UINT PrivateDataSize;
    UINT MaxHWProtectionDataSize;
    UINT HWProtectionDataSize;
    UINT64 TransportTime;
    UINT64 ExecutionTime;
    BYTE pbOutput[4];
} D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA;

typedef struct D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA
{
    UINT HWProtectionFunctionID;
    D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA *pInputData;
    D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA *pOutputData;
    HRESULT Status;
} D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA;

typedef struct D3D11_VIDEO_SAMPLE_DESC
{
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
    DXGI_COLOR_SPACE_TYPE ColorSpace;
} D3D11_VIDEO_SAMPLE_DESC;

struct ID3D11BlendState1 : public ID3D11BlendState
{
    static const GUID guid;

    virtual void GetDesc1(D3D11_BLEND_DESC1 *pDesc);
};
const GUID ID3D11BlendState1::guid = {0xcc86fabe,0xda55,0x401d,{0x85,0xe7,0xe3,0xc9,0xde,0x28,0x77,0xe9}};

struct ID3DDeviceContextState : public ID3D11DeviceChild
{
    static const GUID guid;
};
const GUID ID3DDeviceContextState::guid = {0x5c1e0d8a,0x7c23,0x48f9,{0x8c,0x59,0xa9,0x29,0x58,0xce,0xff,0x11}};

struct ID3D11DeviceContext1 : public ID3D11DeviceContext
{
    static const GUID guid;

    virtual void CopySubresourceRegion1(
            ID3D11Resource *pDstResource,
            UINT DstSubresource,
            UINT DstX,
            UINT DstY,
            UINT DstZ,
            ID3D11Resource *pSrcResource,
            UINT SrcSubresource,
            const D3D11_BOX *pSrcBox,
            UINT CopyFlags);

    virtual void UpdateSubresource1(
            ID3D11Resource *pDstResource,
            UINT DstSubresource,
            const D3D11_BOX *pDstBox,
            const void *pSrcData,
            UINT SrcRowPitch,
            UINT SrcDepthPitch,
            UINT CopyFlags);

    virtual void DiscardResource(ID3D11Resource *pResource);

    virtual void DiscardView(ID3D11View *pResourceView);

    virtual void VSSetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer *const *ppConstantBuffers,
            const UINT *pFirstConstant,
            const UINT *pNumConstants);

    virtual void HSSetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer *const *ppConstantBuffers,
            const UINT *pFirstConstant,
            const UINT *pNumConstants);

    virtual void DSSetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer *const *ppConstantBuffers,
            const UINT *pFirstConstant,
            const UINT *pNumConstants);

    virtual void GSSetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer *const *ppConstantBuffers,
            const UINT *pFirstConstant,
            const UINT *pNumConstants);

    virtual void PSSetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer *const *ppConstantBuffers,
            const UINT *pFirstConstant,
            const UINT *pNumConstants);

    virtual void CSSetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer *const *ppConstantBuffers,
            const UINT *pFirstConstant,
            const UINT *pNumConstants);

    virtual void VSGetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer **ppConstantBuffers,
            UINT *pFirstConstant,
            UINT *pNumConstants);

    virtual void HSGetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer **ppConstantBuffers,
            UINT *pFirstConstant,
            UINT *pNumConstants);

    virtual void DSGetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer **ppConstantBuffers,
            UINT *pFirstConstant,
            UINT *pNumConstants);

    virtual void GSGetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer **ppConstantBuffers,
            UINT *pFirstConstant,
            UINT *pNumConstants);

    virtual void PSGetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer **ppConstantBuffers,
            UINT *pFirstConstant,
            UINT *pNumConstants);

    virtual void CSGetConstantBuffers1(
            UINT StartSlot,
            UINT NumBuffers,
            ID3D11Buffer **ppConstantBuffers,
            UINT *pFirstConstant,
            UINT *pNumConstants);

    virtual void SwapDeviceContextState(
            ID3DDeviceContextState *pState,
            ID3DDeviceContextState **ppPreviousState);

    virtual void ClearView(
            ID3D11View *pView,
            const FLOAT Color[4],
            const D3D11_RECT *pRect,
            UINT NumRects);

    virtual void DiscardView1(
            ID3D11View *pResourceView,
            const D3D11_RECT *pRects,
            UINT NumRects);
};
const GUID ID3D11DeviceContext1::guid = {0xbb2c6faa,0xb5fb,0x4082,{0x8e,0x6b,0x38,0x8b,0x8c,0xfa,0x90,0xe1}};

struct ID3D11VideoContext1 : public ID3D11VideoContext
{
    static const GUID guid;

    virtual HRESULT SubmitDecoderBuffers1(
        ID3D11VideoDecoder *decoder,
        UINT buffer_count,
        const D3D11_VIDEO_DECODER_BUFFER_DESC1 *buffer_desc
    );
    virtual HRESULT GetDataForNewHardwareKey(
        ID3D11CryptoSession *session,
        UINT input_size,
        const void *input_data,
        UINT64 *output_data
    );
    virtual HRESULT CheckCryptoSessionStatus(
        ID3D11CryptoSession *session,
        D3D11_CRYPTO_SESSION_STATUS *status
    );
    virtual HRESULT DecoderEnableDownsampling(
        ID3D11VideoDecoder *decoder,
        DXGI_COLOR_SPACE_TYPE colour_space,
        const D3D11_VIDEO_SAMPLE_DESC *output_desc,
        UINT reference_frame_count
    );
    virtual HRESULT DecoderUpdateDownsampling(
        ID3D11VideoDecoder *decoder,
        const D3D11_VIDEO_SAMPLE_DESC *output_desc
    );
    virtual void VideoProcessorSetOutputColorSpace1(
        ID3D11VideoProcessor *processor,
        DXGI_COLOR_SPACE_TYPE colour_space
    );
    virtual void VideoProcessorSetOutputShaderUsage(
        ID3D11VideoProcessor *processor,
        BOOL shader_usage
    );
    virtual void VideoProcessorGetOutputColorSpace1(
        ID3D11VideoProcessor *processor,
        DXGI_COLOR_SPACE_TYPE *colour_space
    );
    virtual void VideoProcessorGetOutputShaderUsage(
        ID3D11VideoProcessor *processor,
        BOOL *shader_usage
    );
    virtual void VideoProcessorSetStreamColorSpace1(
        ID3D11VideoProcessor *processor,
        UINT stream_index,
        DXGI_COLOR_SPACE_TYPE colour_space
    );
    virtual void VideoProcessorSetStreamMirror(
        ID3D11VideoProcessor *processor,
        UINT stream_index,
        BOOL enable,
        BOOL flip_horizontal,
        BOOL flip_vertical
    );
    virtual void VideoProcessorGetStreamColorSpace1(
        ID3D11VideoProcessor *processor,
        UINT stream_index,
        DXGI_COLOR_SPACE_TYPE *colour_space
    );
    virtual void VideoProcessorGetStreamMirror(
        ID3D11VideoProcessor *processor,
        UINT stream_index,
        BOOL *enable,
        BOOL *flip_horizontal,
        BOOL *flip_vertical
    );
    virtual HRESULT VideoProcessorGetBehaviorHints(
        ID3D11VideoProcessor *processor,
        UINT output_width,
        UINT output_height,
        DXGI_FORMAT output_format,
        UINT stream_count,
        const D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT *streams,
        UINT *behaviour_hints
    );
};
const GUID ID3D11VideoContext1::guid = {0xa7f026da,0xa5f8,0x4487,{0xa5,0x64,0x15,0xe3,0x43,0x57,0x65,0x1e}};

struct ID3D11VideoDevice1 : public ID3D11VideoDevice
{
    static const GUID guid;

    virtual HRESULT GetCryptoSessionPrivateDataSize(
        const GUID *crypto_type,
        const GUID *decoder_profile,
        const GUID *key_exchange_type,
        UINT *input_size,
        UINT *output_size
    );
    virtual HRESULT GetVideoDecoderCaps(
        const GUID *decoder_profile,
        UINT sample_width,
        UINT sample_height,
        const DXGI_RATIONAL *framerate,
        UINT bitrate,
        const GUID *crypto_type,
        UINT *decoder_caps
    );
    virtual HRESULT CheckVideoDecoderDownsampling(
        const D3D11_VIDEO_DECODER_DESC *input_desc,
        DXGI_COLOR_SPACE_TYPE input_colour_space,
        const D3D11_VIDEO_DECODER_CONFIG *input_config,
        const DXGI_RATIONAL *framerate,
        const D3D11_VIDEO_SAMPLE_DESC *output_desc,
        BOOL *supported,
        BOOL *real_time_hint
    );
    virtual HRESULT RecommendVideoDecoderDownsampleParameters(
        const D3D11_VIDEO_DECODER_DESC *input_desc,
        DXGI_COLOR_SPACE_TYPE input_colour_space,
        const D3D11_VIDEO_DECODER_CONFIG *input_config,
        const DXGI_RATIONAL *framerate,
        D3D11_VIDEO_SAMPLE_DESC *recommended_output_desc
    );
};
const GUID ID3D11VideoDevice1::guid = {0x29da1d51,0x1321,0x4454,{0x80,0x4b,0xf5,0xfc,0x9f,0x86,0x1f,0x0f}};

struct ID3D11VideoProcessorEnumerator1 : public ID3D11VideoProcessorEnumerator
{
    static const GUID guid;

    virtual HRESULT CheckVideoProcessorFormatConversion(
        DXGI_FORMAT input_format,
        DXGI_COLOR_SPACE_TYPE input_colour_space,
        DXGI_FORMAT output_format,
        DXGI_COLOR_SPACE_TYPE output_colour_space,
        BOOL *supported
    );
};
const GUID ID3D11VideoProcessorEnumerator1::guid = {0x465217f2,0x5568,0x43cf,{0xb5,0xb9,0xf6,0x1d,0x54,0x53,0x1c,0xa1}};

struct ID3DUserDefinedAnnotation : public IUnknown
{
    static const GUID guid;

    virtual INT BeginEvent(LPCWSTR Name);
    virtual INT EndEvent();
    virtual void SetMarker(LPCWSTR Name);
    virtual BOOL GetStatus();
};
const GUID ID3DUserDefinedAnnotation::guid = {0xb2daad8b,0x03d4,0x4dbf,{0x95,0xeb,0x32,0xab,0x4b,0x63,0xd0,0xab}};

struct ID3D11RasterizerState1 : public ID3D11RasterizerState
{
    static const GUID guid;

    virtual void GetDesc1(D3D11_RASTERIZER_DESC1 *pDesc);
};
const GUID ID3D11RasterizerState1::guid = {0x1217d7a6,0x5039,0x418c,{0xb0,0x42,0x9c,0xbe,0x25,0x6a,0xfd,0x6e}};

struct ID3D11Device1 : public ID3D11Device
{
    static const GUID guid;

    virtual void GetImmediateContext1(
            ID3D11DeviceContext1 **ppImmediateContext);

    virtual HRESULT CreateDeferredContext1(
            UINT ContextFlags,
            ID3D11DeviceContext1 **ppDeferredContext);

    virtual HRESULT CreateBlendState1(
            const D3D11_BLEND_DESC1 *pBlendStateDesc,
            ID3D11BlendState1 **ppBlendState);

    virtual HRESULT CreateRasterizerState1(
            const D3D11_RASTERIZER_DESC1 *pRasterizerDesc,
            ID3D11RasterizerState1 **ppRasterizerState);

    virtual HRESULT CreateDeviceContextState(
            UINT Flags,
            const D3D_FEATURE_LEVEL *pFeatureLevels,
            UINT FeatureLevels,
            UINT SDKVersion,
            REFIID EmulatedInterface,
            D3D_FEATURE_LEVEL *pChosenFeatureLevel,
            ID3DDeviceContextState **ppContextState);

    virtual HRESULT OpenSharedResource1(
            HANDLE hResource,
            REFIID returnedInterface,
            void **ppResource);

     virtual HRESULT OpenSharedResourceByName(
            LPCWSTR lpName,
            DWORD dwDesiredAccess,
            REFIID returnedInterface,
            void **ppResource);
};
const GUID ID3D11Device1::guid = {0xa04bfb29,0x08ef,0x43d6,{0xa4,0x9c,0xa9,0xbd,0xbd,0xcb,0xe6,0x86}};

#endif