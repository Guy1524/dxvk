#ifndef DXGI1_3_H
#define DXGI1_3_H

#include <dxgi1_2.h>

typedef struct DXGI_MATRIX_3X2_F
{
    float _11;
    float _12;
    float _21;
    float _22;
    float _31;
    float _32;
} DXGI_MATRIX_3X2_F;

typedef struct DXGI_DECODE_SWAP_CHAIN_DESC
{
    UINT Flags;
} DXGI_DECODE_SWAP_CHAIN_DESC;

typedef enum DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS
{
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE = 0x1,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709 = 0x2,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC = 0x4,
} DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS;

typedef enum DXGI_FRAME_PRESENTATION_MODE
{
    DXGI_FRAME_PRESENTATION_MODE_COMPOSED = 0,
    DXGI_FRAME_PRESENTATION_MODE_OVERLAY = 1,
    DXGI_FRAME_PRESENTATION_MODE_NONE = 2,
    DXGI_FRAME_PRESENTATION_MODE_COMPOSITION_FAILURE = 3,
} DXGI_FRAME_PRESENTATION_MODE;

typedef struct DXGI_FRAME_STATISTICS_MEDIA
{
    UINT PresentCount;
    UINT PresentRefreshCount;
    UINT SyncRefreshCount;
    LARGE_INTEGER SyncQPCTime;
    LARGE_INTEGER SyncGPUTime;
    DXGI_FRAME_PRESENTATION_MODE CompositionMode;
    UINT ApprovedPresentDuration;
} DXGI_FRAME_STATISTICS_MEDIA;

typedef enum DXGI_OVERLAY_SUPPORT_FLAG
{
    DXGI_OVERLAY_SUPPORT_FLAG_DIRECT = 0x1,
    DXGI_OVERLAY_SUPPORT_FLAG_SCALING = 0x2,
} DXGI_OVERLAY_SUPPORT_FLAG;

struct IDXGIDevice3 : public IDXGIDevice2
{
    static const GUID guid;

    virtual void Trim();
};
const GUID IDXGIDevice3::guid = {0x6007896c,0x3244,0x4afd,{0xbf,0x18,0xa6,0xd3,0xbe,0xda,0x50,0x23}};

struct IDXGISwapChain2 : public IDXGISwapChain1
{
    static const GUID guid;

    virtual HRESULT SetSourceSize(UINT width, UINT height);

    virtual HRESULT GetSourceSize(
        /*out*/ UINT *width,
        /*out*/ UINT *height
    );

    virtual HRESULT SetMaximumFrameLatency(UINT max_latency);

    virtual HRESULT GetMaximumFrameLatency(
        /*out*/ UINT *max_latency
    );

    virtual HANDLE  GetFrameLatencyWaitableObject();

    virtual HRESULT SetMatrixTransform(const DXGI_MATRIX_3X2_F *matrix);

    virtual HRESULT GetMatrixTransform(
        /*out*/ DXGI_MATRIX_3X2_F *matrix
    );
};
const GUID IDXGISwapChain2::guid = {0xa8be2ac4,0x199f,0x4946,{0xb3,0x31,0x79,0x59,0x9f,0xb9,0x8d,0xe7}};

struct IDXGIOutput2 : public IDXGIOutput1
{
    static const GUID guid;

    virtual BOOL SupportsOverlays();
};
const GUID IDXGIOutput2::guid = {0x595e39d1,0x2724,0x4663,{0x99,0xb1,0xda,0x96,0x9d,0xe2,0x83,0x64}};

struct IDXGIFactory3 : public IDXGIFactory2
{
    static const GUID guid;

    virtual UINT GetCreationFlags();
};
const GUID IDXGIFactory3::guid = {0x25483823,0xcd46,0x4c7d,{0x86,0xca,0x47,0xaa,0x95,0xb8,0x37,0xbd}};

struct IDXGIOutput3 : public IDXGIOutput2
{
    static const GUID guid;

    virtual HRESULT CheckOverlaySupport(
        /*in*/ DXGI_FORMAT enum_format,
        /*out*/ IUnknown *concerned_device,
        /*out*/ UINT *flags
    );
};
const GUID IDXGIOutput3::guid = {0x8a6bb301,0x7e7e,0x41F4,{0xa8,0xe0,0x5b,0x32,0xf7,0xf9,0x9b,0x18}};

const UINT DXGI_CREATE_FACTORY_DEBUG = 0x1;

HRESULT CreateDXGIFactory2(UINT flags, REFIID iid, void **factory);

HRESULT DXGIGetDebugInterface1(UINT flags, REFIID iid, void **debug);

#endif