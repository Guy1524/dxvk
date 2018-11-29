#ifndef DXGI_H
#define DXGI_H

#include <windows.h>

//import "oaidl.idl";
//import "ocidl.idl";
#include <dxgitype.h>

const UINT _FACDXGI = 0x87a;

#define MAKE_DXGI_STATUS(x)                         MAKE_HRESULT(0, _FACDXGI, x)
#define MAKE_DXGI_HRESULT(x)                        MAKE_HRESULT(1, _FACDXGI, x)

typedef UINT DXGI_USAGE;
const DXGI_USAGE DXGI_USAGE_SHADER_INPUT            = 0x10L;
const DXGI_USAGE DXGI_USAGE_RENDER_TARGET_OUTPUT    = 0x20L;
const DXGI_USAGE DXGI_USAGE_BACK_BUFFER             = 0x40L;
const DXGI_USAGE DXGI_USAGE_SHARED                  = 0x80L;
const DXGI_USAGE DXGI_USAGE_READ_ONLY               = 0x100L;
const DXGI_USAGE DXGI_USAGE_DISCARD_ON_PRESENT      = 0x200L;
const DXGI_USAGE DXGI_USAGE_UNORDERED_ACCESS        = 0x400L;

const UINT DXGI_ENUM_MODES_INTERLACED               = 1;
const UINT DXGI_ENUM_MODES_SCALING                  = 2;

const UINT DXGI_RESOURCE_PRIORITY_MINIMUM           = 0x28000000;
const UINT DXGI_RESOURCE_PRIORITY_LOW               = 0x50000000;
const UINT DXGI_RESOURCE_PRIORITY_NORMAL            = 0x78000000;
const UINT DXGI_RESOURCE_PRIORITY_HIGH              = 0xa0000000;
const UINT DXGI_RESOURCE_PRIORITY_MAXIMUM           = 0xc8000000;

const UINT DXGI_MAP_READ                            = 0x1;
const UINT DXGI_MAP_WRITE                           = 0x2;
const UINT DXGI_MAP_DISCARD                         = 0x4;

typedef enum DXGI_SWAP_EFFECT {
    DXGI_SWAP_EFFECT_DISCARD    = 0,
    DXGI_SWAP_EFFECT_SEQUENTIAL = 1,
    DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3,
    DXGI_SWAP_EFFECT_FLIP_DISCARD = 4
} DXGI_SWAP_EFFECT;

typedef enum DXGI_RESIDENCY {
    DXGI_RESIDENCY_FULLY_RESIDENT               = 1,
    DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY    = 2,
    DXGI_RESIDENCY_EVICTED_TO_DISK              = 3,
} DXGI_RESIDENCY;

typedef struct DXGI_SURFACE_DESC {
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
    DXGI_SAMPLE_DESC SampleDesc;
} DXGI_SURFACE_DESC;

typedef struct DXGI_MAPPED_RECT {
    INT Pitch;
    BYTE *pBits;
} DXGI_MAPPED_RECT;

typedef struct DXGI_OUTPUT_DESC {
    WCHAR DeviceName[32];
    RECT DesktopCoordinates;
    BOOL AttachedToDesktop;
    DXGI_MODE_ROTATION Rotation;
    HMONITOR Monitor;
} DXGI_OUTPUT_DESC;

typedef struct DXGI_FRAME_STATISTICS {
    UINT PresentCount;
    UINT PresentRefreshCount;
    UINT SyncRefreshCount;
    LARGE_INTEGER SyncQPCTime;
    LARGE_INTEGER SyncGPUTime;
} DXGI_FRAME_STATISTICS;

typedef struct DXGI_ADAPTER_DESC {
    WCHAR Description[128];
    UINT VendorId;
    UINT DeviceId;
    UINT SubSysId;
    UINT Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID AdapterLuid;
} DXGI_ADAPTER_DESC;

typedef enum DXGI_SWAP_CHAIN_FLAG
{
    DXGI_SWAP_CHAIN_FLAG_NONPREROTATED                          = 0x0001,
    DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH                      = 0x0002,
    DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE                         = 0x0004,
    DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTEXT                     = 0x0008,
    DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER        = 0x0010,
    DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY                           = 0x0020,
    DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT          = 0x0040,
    DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER                       = 0x0080,
    DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO                       = 0x0100,
    DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO                              = 0x0200,
    DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED                           = 0x0400,
    DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING                          = 0x0800,
    DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = 0x1000,
} DXGI_SWAP_CHAIN_FLAG;

typedef struct DXGI_SWAP_CHAIN_DESC {
    DXGI_MODE_DESC BufferDesc;
    DXGI_SAMPLE_DESC SampleDesc;
    DXGI_USAGE BufferUsage;
    UINT BufferCount;
    HWND OutputWindow;
    BOOL Windowed;
    DXGI_SWAP_EFFECT SwapEffect;
    UINT Flags;
} DXGI_SWAP_CHAIN_DESC;

typedef struct DXGI_SHARED_RESOURCE {
    HANDLE Handle;
} DXGI_SHARED_RESOURCE;

struct IDXGIObject : public IUnknown
{
    static const GUID guid;

    virtual HRESULT SetPrivateData(
        /*in*/ REFGUID guid,
        /*in*/ UINT data_size,
        /*in*/ const void *data
    );
    virtual HRESULT SetPrivateDataInterface(
        /*in*/ REFGUID guid,
        /*in*/ const IUnknown *object
    );
    virtual HRESULT GetPrivateData(
        /*in*/ REFGUID guid,
        /*inout*/ UINT *data_size,
        /*out*/ void *data
    );
    virtual HRESULT GetParent(
        /*in*/ REFIID riid,
        /*out*/ void **parent
    );
};
const GUID IDXGIObject::guid = {0xaec22fb8,0x76f3,0x4639,{0x9b,0xe0,0x28,0xeb,0x43,0xa6,0x7a,0x2e}};

struct IDXGIDeviceSubObject : public IDXGIObject
{
    static const GUID guid;

    virtual HRESULT GetDevice(
        /*in*/ REFIID riid,
        /*out*/ void **device
    );
};
const GUID IDXGIDeviceSubObject::guid = {0x3d3e0379,0xf9de,0x4d58,{0xbb,0x6c,0x18,0xd6,0x29,0x92,0xf1,0xa6}};

struct IDXGIResource : public IDXGIDeviceSubObject
{
    static const GUID guid;

    virtual HRESULT GetSharedHandle(/*out*/ HANDLE *pSharedHandle);
    virtual HRESULT GetUsage(/*out*/ DXGI_USAGE *pUsage);
    virtual HRESULT SetEvictionPriority(/*in*/ UINT EvictionPriority);
    virtual HRESULT GetEvictionPriority(/*out*/ UINT *pEvictionPriority);
};
const GUID IDXGIResource::guid = {0x035f3ab4,0x482e,0x4e50,{0xb4,0x1f,0x8a,0x7f,0x8b,0xd8,0x96,0x0b}};

struct IDXGIKeyedMutex : public IDXGIDeviceSubObject
{
    static const GUID guid;

    virtual HRESULT AcquireSync(/*in*/ UINT64 Key, /*in*/ DWORD dwMilliseconds);
    virtual HRESULT ReleaseSync(/*in*/ UINT64 Key);
};
const GUID IDXGIKeyedMutex::guid = {0x9d8e1289,0xd7b3,0x465f,{0x81,0x26,0x25,0x0e,0x34,0x9a,0xf8,0x5d}};

struct IDXGISurface : public IDXGIDeviceSubObject
{
    static const GUID guid;

    virtual HRESULT GetDesc(
        /*out*/ DXGI_SURFACE_DESC *desc
    );
    virtual HRESULT Map(
        /*out*/ DXGI_MAPPED_RECT *mapped_rect,
        /*in*/ UINT flags
    );
    virtual HRESULT Unmap(
    );
};
const GUID IDXGISurface::guid = {0xcafcb56c,0x6ac3,0x4889,{0xbf,0x47,0x9e,0x23,0xbb,0xd2,0x60,0xec}};

struct IDXGISurface1 : public IDXGISurface
{
    static const GUID guid;

    virtual HRESULT GetDC(
        /*in*/ BOOL discard,
        /*out*/ HDC *hdc
    );
    virtual HRESULT ReleaseDC(
        /*in*/ RECT *dirty_rect
    );
};
const GUID IDXGISurface1::guid = {0x4ae63092,0x6327,0x4c1b,{0x80,0xae,0xbf,0xe1,0x2e,0xa3,0x2b,0x86}};

struct IDXGIOutput : public IDXGIObject
{
    static const GUID guid;

    virtual HRESULT GetDesc(
        /*out*/ DXGI_OUTPUT_DESC *desc
    );
    virtual HRESULT GetDisplayModeList(
        /*in*/ DXGI_FORMAT format,
        /*in*/ UINT flags,
        /*inout*/ UINT *mode_count,
        /*out*/ DXGI_MODE_DESC *desc
    );
    virtual HRESULT FindClosestMatchingMode(
        /*in*/ const DXGI_MODE_DESC *mode,
        /*out*/ DXGI_MODE_DESC *closest_match,
        /*in*/ IUnknown *device
    );
    virtual HRESULT WaitForVBlank(
    );
    virtual HRESULT TakeOwnership(
        /*in*/ IUnknown *device,
        /*in*/ BOOL exclusive
    );
    virtual void ReleaseOwnership(
    );
    virtual HRESULT GetGammaControlCapabilities(
        /*out*/ DXGI_GAMMA_CONTROL_CAPABILITIES *gamma_caps
    );
    virtual HRESULT SetGammaControl(
        /*in*/ const DXGI_GAMMA_CONTROL *gamma_control
    );
    virtual HRESULT GetGammaControl(
        /*out*/ DXGI_GAMMA_CONTROL *gamma_control
    );
    virtual HRESULT SetDisplaySurface(
        /*in*/ IDXGISurface *surface
    );
    virtual HRESULT GetDisplaySurfaceData(
        /*in*/ IDXGISurface *surface
    );
    virtual HRESULT GetFrameStatistics(
        /*out*/ DXGI_FRAME_STATISTICS *stats
    );
};
const GUID IDXGIOutput::guid = {0xae02eedb,0xc735,0x4690,{0x8d,0x52,0x5a,0x8d,0xc2,0x02,0x13,0xaa}};

struct IDXGIAdapter : public IDXGIObject
{
    static const GUID guid;

    virtual HRESULT EnumOutputs(
        /*in*/ UINT output_idx,
        /*inout*/ IDXGIOutput **output
    );
    virtual HRESULT GetDesc(
        /*out*/ DXGI_ADAPTER_DESC *desc
    );
    virtual HRESULT CheckInterfaceSupport(
        /*in*/ REFGUID guid,
        /*out*/ LARGE_INTEGER *umd_version
    );
};
const GUID IDXGIAdapter::guid = {0x2411e7e1,0x12ac,0x4ccf,{0xbd,0x14,0x97,0x98,0xe8,0x53,0x4d,0xc0}};

#define DXGI_MAX_SWAP_CHAIN_BUFFERS  (16)

#define DXGI_PRESENT_TEST                   __MSABI_LONG(0x00000001U)
#define DXGI_PRESENT_DO_NOT_SEQUENCE        __MSABI_LONG(0x00000002U)
#define DXGI_PRESENT_RESTART                __MSABI_LONG(0x00000004U)
#define DXGI_PRESENT_DO_NOT_WAIT            __MSABI_LONG(0x00000008U)
#define DXGI_PRESENT_STEREO_PREFER_RIGHT    __MSABI_LONG(0x00000010U)
#define DXGI_PRESENT_STEREO_TEMPORARY_MONO  __MSABI_LONG(0x00000020U)
#define DXGI_PRESENT_RESTRICT_TO_OUTPUT     __MSABI_LONG(0x00000040U)
#define DXGI_PRESENT_USE_DURATION           __MSABI_LONG(0x00000100U)
#define DXGI_PRESENT_ALLOW_TEARING          __MSABI_LONG(0x00000200U)

struct IDXGISwapChain : public IDXGIDeviceSubObject
{
    static const GUID guid;

    virtual HRESULT Present(
        /*in*/ UINT sync_interval,
        /*in*/ UINT flags
    );
    virtual HRESULT GetBuffer(
        /*in*/ UINT buffer_idx,
        /*in*/ REFIID riid,
        /*inout*/ void **surface
    );
    virtual HRESULT SetFullscreenState(
        /*in*/ BOOL fullscreen,
        /*in*/ IDXGIOutput *target
    );
    virtual HRESULT GetFullscreenState(
        /*out*/ BOOL *fullscreen,
        /*out*/ IDXGIOutput **target
    );
    virtual HRESULT GetDesc(
        /*out*/ DXGI_SWAP_CHAIN_DESC *desc
    );
    virtual HRESULT ResizeBuffers(
        /*in*/ UINT buffer_count,
        /*in*/ UINT width,
        /*in*/ UINT height,
        /*in*/ DXGI_FORMAT format,
        /*in*/ UINT flags
    );
    virtual HRESULT ResizeTarget(
        /*in*/ const DXGI_MODE_DESC *target_mode_desc
    );
    virtual HRESULT GetContainingOutput(
        /*out*/ IDXGIOutput **output
    );
    virtual HRESULT GetFrameStatistics(
        /*out*/ DXGI_FRAME_STATISTICS *stats
    );
    virtual HRESULT GetLastPresentCount(
        /*out*/ UINT *last_present_count
    );
};
const GUID IDXGISwapChain::guid = {0x310d36a0,0xd2e7,0x4c0a,{0xaa,0x04,0x6a,0x9d,0x23,0xb8,0x88,0x6a}};

#define DXGI_MWA_NO_WINDOW_CHANGES  0x1
#define DXGI_MWA_NO_ALT_ENTER       0x2
#define DXGI_MWA_NO_PRINT_SCREEN    0x4
#define DXGI_MWA_VALID              0x7

struct IDXGIFactory : public IDXGIObject
{
    static const GUID guid;

    virtual HRESULT EnumAdapters(
        /*in*/ UINT adapter_idx,
        /*out*/ IDXGIAdapter **adapter
    );
    virtual HRESULT MakeWindowAssociation(
        /*in*/ HWND window,
        /*in*/ UINT flags
    );
    virtual HRESULT GetWindowAssociation(
        /*in*/ HWND *window
    );
    virtual HRESULT CreateSwapChain(
        /*in*/ IUnknown *device,
        /*in*/ DXGI_SWAP_CHAIN_DESC *desc,
        /*out*/ IDXGISwapChain **swapchain
    );
    virtual HRESULT CreateSoftwareAdapter(
        /*in*/ HMODULE swrast,
        /*out*/ IDXGIAdapter **adapter
    );
};
const GUID IDXGIFactory::guid = {0x7b7166ec,0x21c7,0x44ae,{0xb2,0x1a,0xc9,0xae,0x32,0x1a,0xe3,0x69}};

HRESULT CreateDXGIFactory(REFIID riid, void **factory);
HRESULT CreateDXGIFactory1(REFIID riid, void **factory);

struct IDXGIDevice : public IDXGIObject
{
    static const GUID guid;

    virtual HRESULT GetAdapter(
        /*out*/ IDXGIAdapter **adapter
    );
    virtual HRESULT CreateSurface(
        /*in*/ const DXGI_SURFACE_DESC *desc,
        /*in*/ UINT surface_count,
        /*in*/ DXGI_USAGE usage,
        /*in*/ const DXGI_SHARED_RESOURCE *shared_resource,
        /*out*/ IDXGISurface **surface
    );
    virtual HRESULT QueryResourceResidency(
        /*in*/ IUnknown *const *resources,
        /*out*/ DXGI_RESIDENCY *residency,
        /*in*/ UINT resource_count
    );
    virtual HRESULT SetGPUThreadPriority(
        /*in*/ INT priority
    );
    virtual HRESULT GetGPUThreadPriority(
        /*out*/ INT *priority
    );
};
const GUID IDXGIDevice::guid = {0x54ec77fa,0x1377,0x44e6,{0x8c,0x32,0x88,0xfd,0x5f,0x44,0xc8,0x4c}};

typedef enum DXGI_ADAPTER_FLAG {
    DXGI_ADAPTER_FLAG_NONE         = 0,
    DXGI_ADAPTER_FLAG_REMOTE       = 1,
    DXGI_ADAPTER_FLAG_FORCE_DWORD  = 0xFFFFFFFF
} DXGI_ADAPTER_FLAG;

typedef struct DXGI_ADAPTER_DESC1 {
    WCHAR  Description[128];
    UINT   VendorId;
    UINT   DeviceId;
    UINT   SubSysId;
    UINT   Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID   AdapterLuid;
    UINT   Flags;
} DXGI_ADAPTER_DESC1;

struct IDXGIAdapter1 : public IDXGIAdapter
{
    static const GUID guid;

    virtual HRESULT GetDesc1(/*out*/ DXGI_ADAPTER_DESC1 *pDesc);
};
const GUID IDXGIAdapter1::guid = {0x29038f61,0x3839,0x4626,{0x91,0xfd,0x08,0x68,0x79,0x01,0x1a,0x05}};

struct IDXGIDevice1 : public IDXGIDevice
{
    static const GUID guid;

    virtual HRESULT SetMaximumFrameLatency(/*in*/ UINT MaxLatency);
    virtual HRESULT GetMaximumFrameLatency(/*out*/ UINT *pMaxLatency);
};
const GUID IDXGIDevice1::guid = {0x77db970f,0x6276,0x48ba,{0xba,0x28,0x07,0x01,0x43,0xb4,0x39,0x2c}};

struct IDXGIFactory1 : public IDXGIFactory
{
    static const GUID guid;

    virtual HRESULT EnumAdapters1(/*in*/ UINT Adapter, /*out*/ IDXGIAdapter1 **ppAdapter);
    virtual BOOL IsCurrent();
};
const GUID IDXGIFactory1::guid = {0x770aae78,0xf26f,0x4dba,{0xa8,0x29,0x25,0x3c,0x83,0xd1,0xb3,0x87}};

#endif