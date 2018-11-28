#ifndef DXGI1_2_H
#define DXGI1_2_H

#include <dxgi.h>

const UINT DXGI_ENUM_MODES_STEREO = 0x4;
const UINT DXGI_ENUM_MODES_DISABLED_STEREO = 0x8;

const DWORD DXGI_SHARED_RESOURCE_READ = 0x80000000;
const DWORD DXGI_SHARED_RESOURCE_WRITE = 0x00000001;

typedef enum _DXGI_OFFER_RESOURCE_PRIORITY {
    DXGI_OFFER_RESOURCE_PRIORITY_LOW = 1,
    DXGI_OFFER_RESOURCE_PRIORITY_NORMAL,
    DXGI_OFFER_RESOURCE_PRIORITY_HIGH
} DXGI_OFFER_RESOURCE_PRIORITY;

typedef enum DXGI_ALPHA_MODE {
    DXGI_ALPHA_MODE_UNSPECIFIED = 0,
    DXGI_ALPHA_MODE_PREMULTIPLIED = 1,
    DXGI_ALPHA_MODE_STRAIGHT = 2,
    DXGI_ALPHA_MODE_IGNORE = 3,
    DXGI_ALPHA_MODE_FORCE_DWORD = 0xffffffff
} DXGI_ALPHA_MODE;

typedef struct DXGI_OUTDUPL_MOVE_RECT
{
    POINT SourcePoint;
    RECT DestinationRect;
} DXGI_OUTDUPL_MOVE_RECT;

typedef struct DXGI_OUTDUPL_DESC
{
    DXGI_MODE_DESC ModeDesc;
    DXGI_MODE_ROTATION Rotation;
    BOOL DesktopImageInSystemMemory;
} DXGI_OUTDUPL_DESC;

typedef struct DXGI_OUTDUPL_POINTER_POSITION
{
    POINT Position;
    BOOL Visible;
} DXGI_OUTDUPL_POINTER_POSITION;

typedef enum DXGI_OUTDUPL_POINTER_SHAPE_TYPE
{
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME = 0x00000001,
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR = 0x00000002,
    DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR = 0x00000004
} DXGI_OUTDUPL_POINTER_SHAPE_TYPE;

typedef struct DXGI_OUTDUPL_POINTER_SHAPE_INFO
{
    UINT Type;
    UINT Width;
    UINT Height;
    UINT Pitch;
    POINT HotSpot;
} DXGI_OUTDUPL_POINTER_SHAPE_INFO;

typedef struct DXGI_OUTDUPL_FRAME_INFO
{
    LARGE_INTEGER LastPresentTime;
    LARGE_INTEGER LastMouseUpdateTime;
    UINT AccumulatedFrames;
    BOOL RectsCoalesced;
    BOOL ProtectedContentMaskedOut;
    DXGI_OUTDUPL_POINTER_POSITION PointerPosition;
    UINT TotalMetadataBufferSize;
    UINT PointerShapeBufferSize;
} DXGI_OUTDUPL_FRAME_INFO;

typedef struct DXGI_MODE_DESC1
{
    UINT Width;
    UINT Height;
    DXGI_RATIONAL RefreshRate;
    DXGI_FORMAT Format;
    DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
    DXGI_MODE_SCALING Scaling;
    BOOL Stereo;
} DXGI_MODE_DESC1;

const GUID IDXGIOutputDuplication_GUID = {0x191cfac3,0xa341,0x470d,{0xb2,0x6e,0xa8,0x64,0xf4,0x28,0x31,0x9c}};
struct IDXGIOutputDuplication : public IDXGIObject
{
    virtual void GetDesc(
        /*out*/ DXGI_OUTDUPL_DESC *desc
    );

    virtual HRESULT AcquireNextFrame(
        /*in*/ UINT timeout_in_milliseconds,
        /*out*/ DXGI_OUTDUPL_FRAME_INFO *frame_info,
        /*out*/ IDXGIResource **desktop_resource
    );

    virtual HRESULT GetFrameDirtyRects(
        /*in*/ UINT dirty_rects_buffer_size,
        /*out*/ RECT *dirty_rects_buffer,
        /*out*/ UINT *dirty_rects_buffer_size_required
    );

    virtual HRESULT GetFrameMoveRects(
        /*in*/ UINT move_rects_buffer_size,
        /*out*/ DXGI_OUTDUPL_MOVE_RECT *move_rect_buffer,
        /*out*/ UINT *move_rects_buffer_size_required
    );

    virtual HRESULT GetFramePointerShape(
        /*in*/ UINT pointer_shape_buffer_size,
        /*out*/ void *pointer_shape_buffer,
        /*out*/ UINT *pointer_shape_buffer_size_required,
        /*out*/ DXGI_OUTDUPL_POINTER_SHAPE_INFO *pointer_shape_info
    );

    virtual HRESULT MapDesktopSurface(
        /*out*/ DXGI_MAPPED_RECT *locked_rect
    );

    virtual HRESULT UnMapDesktopSurface();

    virtual HRESULT ReleaseFrame();
};

const GUID IDXGISurface2_GUID = {0xaba496dd,0xb617,0x4cb8,{0xa8,0x66,0xbc,0x44,0xd7,0xeb,0x1f,0xa2}};
struct IDXGISurface2 : public IDXGISurface1
{
    virtual HRESULT GetResource(
        /*in*/ REFIID iid,
        /*out*/ void **parent_resource,
        /*out*/ UINT *subresource_idx
    );
};

const GUID IDXGIResource1_GUID = {0x30961379,0x4609,0x4a41,{0x99,0x8e,0x54,0xfe,0x56,0x7e,0xe0,0xc1}};
struct IDXGIResource1 : public IDXGIResource
{
    virtual HRESULT CreateSubresourceSurface(
        UINT index,
        /*out*/ IDXGISurface2 **surface
    );
    virtual HRESULT CreateSharedHandle(
        /*in*/ const SECURITY_ATTRIBUTES *attributes,
        /*in*/ DWORD access,
        /*in*/ const WCHAR *name,
        /*out*/ HANDLE *handle
    );
};

const GUID IDXGIDisplayControl_GUID = {0xea9dbf1a,0xc88e,0x4486,{0x85,0x4a,0x98,0xaa,0x01,0x38,0xf3,0x0c}};
struct IDXGIDisplayControl : public IUnknown
{
    virtual BOOL IsStereoEnabled();
    virtual void SetStereoEnabled(BOOL enabled);
};

const GUID IDXGIDevice2_GUID = {0x05008617,0xfbfd,0x4051,{0xa7,0x90,0x14,0x48,0x84,0xb4,0xf6,0xa9}};
struct IDXGIDevice2 : public IDXGIDevice1
{
    virtual HRESULT OfferResources(
            /*in*/ UINT NumResources,
            /*in*/ IDXGIResource *const *ppResources,
            /*in*/ DXGI_OFFER_RESOURCE_PRIORITY Priority);

    virtual HRESULT ReclaimResources(
            /*in*/ UINT NumResources,
            /*in*/ IDXGIResource *const *ppResources,
            /*in*/ BOOL *pDiscarded);

    virtual HRESULT EnqueueSetEvent(
            /*in*/ HANDLE hEvent);
};

typedef enum DXGI_SCALING {
    DXGI_SCALING_STRETCH = 0,
    DXGI_SCALING_NONE = 1
} DXGI_SCALING;

typedef struct DXGI_SWAP_CHAIN_DESC1 {
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
    BOOL Stereo;
    DXGI_SAMPLE_DESC SampleDesc;
    DXGI_USAGE BufferUsage;
    UINT BufferCount;
    DXGI_SCALING Scaling;
    DXGI_SWAP_EFFECT SwapEffect;
    DXGI_ALPHA_MODE AlphaMode;
    UINT Flags;
} DXGI_SWAP_CHAIN_DESC1;

typedef struct DXGI_SWAP_CHAIN_FULLSCREEN_DESC {
    DXGI_RATIONAL RefreshRate;
    DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
    DXGI_MODE_SCALING Scaling;
    BOOL Windowed;
} DXGI_SWAP_CHAIN_FULLSCREEN_DESC;

typedef struct DXGI_PRESENT_PARAMETERS {
    UINT DirtyRectsCount;
    RECT *pDirtyRects;
    RECT *pScrollRect;
    POINT *pScrollOffset;
} DXGI_PRESENT_PARAMETERS;


const GUID IDXGISwapChain1_GUID = {0x790a45f7,0x0d42,0x4876,{0x98,0x3a,0x0a,0x55,0xcf,0xe6,0xf4,0xaa}};
struct IDXGISwapChain1 : public IDXGISwapChain
{
    virtual HRESULT GetDesc1(
            /*out*/ DXGI_SWAP_CHAIN_DESC1 *pDesc);

    virtual HRESULT GetFullscreenDesc(
            /*out*/ DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pDesc);

    virtual HRESULT GetHwnd(
            /*out*/ HWND *pHwnd);

    virtual HRESULT GetCoreWindow(
            /*in*/ REFIID refiid,
            /*out*/ void **ppUnk);

    virtual HRESULT Present1(
            /*in*/ UINT SyncInterval,
            /*in*/ UINT PresentFlags,
            /*in*/ const DXGI_PRESENT_PARAMETERS *pPresentParameters);

    virtual BOOL IsTemporaryMonoSupported();

    virtual HRESULT GetRestrictToOutput(
            /*out*/ IDXGIOutput **ppRestrictToOutput);

    virtual HRESULT SetBackgroundColor(
            /*in*/ const DXGI_RGBA *pColor);

    virtual HRESULT GetBackgroundColor(
            /*out*/ DXGI_RGBA *pColor);

    virtual HRESULT SetRotation(
            /*in*/ DXGI_MODE_ROTATION Rotation);

    virtual HRESULT GetRotation(
            /*out*/ DXGI_MODE_ROTATION *pRotation);
};

const GUID IDXGIFactory2_GUID = {0x50c83a1c,0xe072,0x4c48,{0x87,0xb0,0x36,0x30,0xfa,0x36,0xa6,0xd0}};
struct IDXGIFactory2 : public IDXGIFactory1
{
    virtual BOOL IsWindowedStereoEnabled();

    virtual HRESULT CreateSwapChainForHwnd(
            /*in*/  IUnknown *pDevice,
            /*in*/  HWND hWnd,
            /*in*/  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /*in*/  const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc,
            /*in*/  IDXGIOutput *pRestrictToOutput,
            /*out*/ IDXGISwapChain1 **ppSwapChain);

    virtual HRESULT CreateSwapChainForCoreWindow(
            /*in*/  IUnknown *pDevice,
            /*in*/  IUnknown *pWindow,
            /*in*/  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /*in*/  IDXGIOutput *pRestrictToOutput,
            /*out*/ IDXGISwapChain1 **ppSwapChain);

    virtual HRESULT GetSharedResourceAdapterLuid(
            /*in*/  HANDLE hResource,
            /*out*/ LUID *pLuid);

    virtual HRESULT RegisterOcclusionStatusWindow(
            /*in*/  HWND WindowHandle,
            /*in*/  UINT wMsg,
            /*out*/ DWORD *pdwCookie);

    virtual HRESULT RegisterStereoStatusEvent(
            /*in*/  HANDLE hEvent,
            /*out*/ DWORD *pdwCookie);

    virtual void UnregisterStereoStatus(
            /*in*/  DWORD dwCookie);

    virtual HRESULT RegisterStereoStatusWindow(
            /*in*/  HWND WindowHandle,
            /*in*/  UINT wMsg,
            /*out*/ DWORD *pdwCookie);

    virtual HRESULT RegisterOcclusionStatusEvent(
            /*in*/  HANDLE hEvent,
            /*out*/ DWORD *pdwCookie);

    virtual void UnregisterOcclusionStatus(
            /*in*/  DWORD dwCookie);

    virtual HRESULT CreateSwapChainForComposition(
            /*in*/  IUnknown *pDevice,
            /*in*/  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /*in*/  IDXGIOutput *pRestrictToOutput,
            /*out*/ IDXGISwapChain1 **ppSwapChain);
};

typedef enum DXGI_GRAPHICS_PREEMPTION_GRANULARITY {
    DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY,
    DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY,
    DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY,
    DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY,
    DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY
} DXGI_GRAPHICS_PREEMPTION_GRANULARITY;

typedef enum DXGI_COMPUTE_PREEMPTION_GRANULARITY {
    DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY,
    DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY,
    DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY,
    DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY,
    DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY
} DXGI_COMPUTE_PREEMPTION_GRANULARITY;

typedef struct DXGI_ADAPTER_DESC2 {
    WCHAR Description[128];
    UINT VendorId;
    UINT DeviceId;
    UINT SubSysId;
    UINT Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID AdapterLuid;
    UINT Flags;
    DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity;
    DXGI_COMPUTE_PREEMPTION_GRANULARITY ComputePreemptionGranularity;
} DXGI_ADAPTER_DESC2;

const GUID IDXGIAdapter2_GUID = {0x0aa1ae0a,0xfa0e,0x4b84,{0x86,0x44,0xe0,0x5f,0xf8,0xe5,0xac,0xb5}};
struct IDXGIAdapter2 : public IDXGIAdapter1
{
    virtual HRESULT GetDesc2(/*out*/ DXGI_ADAPTER_DESC2 *pDesc);
};

const GUID IDXGIOutput1_GUID = {0x00cddea8,0x939b,0x4b83,{0xa3,0x40,0xa6,0x85,0x22,0x66,0x66,0xcc}};
struct IDXGIOutput1 : public IDXGIOutput
{
    virtual HRESULT GetDisplayModeList1(
        /*in*/ DXGI_FORMAT enum_format,
        /*in*/ UINT flags,
        /*inout*/ UINT *num_modes,
        /*out*/ DXGI_MODE_DESC1 *desc
    );

    virtual HRESULT FindClosestMatchingMode1(
        /*in*/ const DXGI_MODE_DESC1 *mode_to_match,
        /*out*/ DXGI_MODE_DESC1 *closest_match,
        /*in*/ IUnknown *concerned_device
    );

    virtual HRESULT GetDisplaySurfaceData1(
        /*in*/ IDXGIResource *destination
    );

    virtual HRESULT DuplicateOutput(
        /*in*/ IUnknown *device,
        /*out*/ IDXGIOutputDuplication **output_duplication
    );
};

#endif