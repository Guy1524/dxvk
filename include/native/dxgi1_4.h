#ifndef DXGI1_4_H
#define DXGI1_4_H

#include <dxgi1_3.h>

typedef enum DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG
{
    DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT = 0x1,
    DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT = 0x2,
} DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG;

typedef enum DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG
{
    DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT = 0x1,
} DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG;

typedef enum DXGI_MEMORY_SEGMENT_GROUP
{
    DXGI_MEMORY_SEGMENT_GROUP_LOCAL = 0x0,
    DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL = 0x1,
} DXGI_MEMORY_SEGMENT_GROUP;

typedef struct DXGI_QUERY_VIDEO_MEMORY_INFO
{
    UINT64 Budget;
    UINT64 CurrentUsage;
    UINT64 AvailableForReservation;
    UINT64 CurrentReservation;
} DXGI_QUERY_VIDEO_MEMORY_INFO;

const GUID IDXGISwapChain3_GUID = {0x94d99bdb,0xf1f8,0x4ab0,{0xb2,0x36,0x7d,0xa0,0x17,0x0e,0xda,0xb1}} ;
struct IDXGISwapChain3 : public IDXGISwapChain2
{
    virtual UINT GetCurrentBackBufferIndex();
    virtual HRESULT CheckColorSpaceSupport(
        /*in*/ DXGI_COLOR_SPACE_TYPE colour_space,
        /*out*/ UINT *colour_space_support
    );
    virtual HRESULT SetColorSpace1(
        /*in*/ DXGI_COLOR_SPACE_TYPE colour_space
    );
    virtual HRESULT ResizeBuffers1(
        /*in*/ UINT buffer_count,
        /*in*/ UINT width,
        /*in*/ UINT height,
        /*in*/ DXGI_FORMAT format,
        /*in*/ UINT flags,
        /*in*/ const UINT *node_mask,
        /*in*/ IUnknown *const *present_queue
    );
};

const GUID IDXGIOutput4_GUID = {0xdc7dca35,0x2196,0x414d,{0x9F,0x53,0x61,0x78,0x84,0x03,0x2a,0x60}};
struct IDXGIOutput4 : public IDXGIOutput3
{
    virtual HRESULT CheckOverlayColorSpaceSupport(
        /*in*/ DXGI_FORMAT format,
        /*in*/ DXGI_COLOR_SPACE_TYPE colour_space,
        /*in*/ IUnknown *device,
        /*out*/ UINT *flags
    );
};

const GUID IDXGIFactory4_GUID = {0x1bc6ea02,0xef36,0x464f,{0xbf,0x0c,0x21,0xca,0x39,0xe5,0x16,0x8a}};
struct IDXGIFactory4 : public IDXGIFactory3
{
    virtual HRESULT EnumAdapterByLuid(
        /*in*/ LUID luid,
        /*in*/ REFIID iid,
        /*out*/ void **adapter
    );
    virtual HRESULT EnumWarpAdapter(
        /*in*/ REFIID iid,
        /*out*/ void **adapter
    );
};

const GUID IDXGIAdapter3_GUID = {0x645967a4,0x1392,0x4310,{0xa7,0x98,0x80,0x53,0xce,0x3e,0x93,0xfd}};
struct IDXGIAdapter3 : public IDXGIAdapter2
{
    virtual HRESULT RegisterHardwareContentProtectionTeardownStatusEvent(
        /*in*/ HANDLE event,
        /*out*/ DWORD *cookie
    );
    virtual void UnregisterHardwareContentProtectionTeardownStatus(
        /*in*/ DWORD cookie
    );
    virtual HRESULT QueryVideoMemoryInfo(
        /*in*/ UINT node_index,
        /*in*/ DXGI_MEMORY_SEGMENT_GROUP segment_group,
        /*out*/ DXGI_QUERY_VIDEO_MEMORY_INFO *memory_info
    );
    virtual HRESULT SetVideoMemoryReservation(
        /*in*/ UINT node_index,
        /*in*/ DXGI_MEMORY_SEGMENT_GROUP segment_group,
        /*in*/ UINT64 reservation
    );
    virtual HRESULT RegisterVideoMemoryBudgetChangeNotificationEvent(
        /*in*/ HANDLE event,
        /*out*/ DWORD *cookie
    );
    virtual void UnregisterVideoMemoryBudgetChangeNotification(
        /*in*/ DWORD cookie
    );
};



#endif