// ReSharper disable CppInconsistentNaming
#ifndef D3D11_X
#define D3D11_X

#include "dxgi1_5.h"
#include "d3d_x/d3d_x.hpp"

// remove all XBOX only flags passed to CreateDevice 
#define CREATE_DEVICE_FLAG_MASK (D3D11_CREATE_DEVICE_SINGLETHREADED | D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_SWITCH_TO_REF | \
        D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS | D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_DEBUGGABLE | \
        D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY | D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT | D3D11_CREATE_DEVICE_VIDEO_SUPPORT)

typedef GUID DXGI_DEBUG_ID;

typedef enum D3D11_GRAPHICS_MEMORY_ACCESS_FLAG
{
    D3D11_GRAPHICS_MEMORY_ACCESS_CPU_CACHE_COHERENT = 0,
    D3D11_GRAPHICS_MEMORY_ACCESS_CPU_WRITECOMBINE_NONCOHERENT = 1,
    D3D11_GRAPHICS_MEMORY_ACCESS_CPU_CACHE_NONCOHERENT_GPU_READONLY = 2
} D3D11_GRAPHICS_MEMORY_ACCESS_FLAG;

typedef struct D3D11X_CREATE_DEVICE_PARAMETERS {
    UINT Version;
    UINT Flags;
    void* pOffchipTessellationBuffer;
    void* pTessellationFactorsBuffer;
    UINT DeferredDeletionThreadAffinityMask;
    UINT ImmediateContextDeRingSizeBytes;
    UINT ImmediateContextCeRingSizeBytes;
    UINT ImmediateContextDeSegmentSizeBytes;
    UINT ImmediateContextCeSegmentSizeBytes;
} D3D11X_CREATE_DEVICE_PARAMETERS;

typedef struct _DXGIX_FRAME_STATISTICS
{
    UINT64 CPUTimePresentCalled;
    UINT64 CPUTimeAddedToQueue;
    UINT32 QueueLengthAddedToQueue;
    UINT64 CPUTimeFrameComplete;
    UINT64 GPUTimeFrameComplete;
    UINT64 GPUCountTitleUsed;
    UINT64 GPUCountSystemUsed;
    UINT64 CPUTimeVSync;
    UINT64 GPUTimeVSync;
    UINT64 CPUTimeFlip;
    UINT64 GPUTimeFlip;
    UINT64 VSyncCount;
    FLOAT  PercentScanned;
    VOID* Cookie[ 2 ];
} DXGIX_FRAME_STATISTICS;

struct D3D11X_VIRTUAL_MEMORY_CONFIGURATION
{
    UINT Flags;
    UINT PageTableMemory4MBPageCount;
    UINT64 MinimumValidGraphicsAddress;
    UINT64 MaximumValidGraphicsAddress;
};

struct D3D_SEQ_COUNTER_DATA
{
    unsigned int ReadCount[ 12 ];
    unsigned int ReadEdcCount[ 12 ];
    unsigned int WriteCount[ 12 ];
    unsigned int WriteEdcCount[ 12 ];
};

typedef struct _DXGIX_PRESENTARRAY_PARAMETERS
{
    BOOL        Disable;
    BOOL        UsePreviousBuffer;
    D3D11_RECT  SourceRect;
    POINT       DestRectUpperLeft;
    FLOAT       ScaleFactorVert;
    FLOAT       ScaleFactorHorz;
    void*       Cookie;
    UINT        Flags;
} DXGIX_PRESENTARRAY_PARAMETERS;

typedef enum DXGIX_FRAME_NOTIFICATION
{
    FRAME_NOTIFICATION_QUEUED = 0,
    FRAME_NOTIFICATION_COMPLETED = 1,
    FRAME_NOTIFICATION_FLIPPED = 2
} DXGIX_FRAME_NOTIFICATION;

typedef enum DXGIX_VLINECOUNTER
{
    VLINECOUNTER0 = 0,
    VLINECOUNTER1 = 1
} DXGIX_VLINECOUNTER;
// @Patoke todo: reimplement
//struct D3D11_TEXTURE2D_DESC_X
//{
//    UINT Width;
//    UINT Height;
//    UINT MipLevels;
//    UINT ArraySize;
//    DXGI_FORMAT Format;
//    DXGI_SAMPLE_DESC SampleDesc;
//    D3D11_USAGE Usage;
//    UINT BindFlags;
//    UINT CPUAccessFlags;
//    UINT MiscFlags;
//    UINT ESRAMOffsetBytes;
//    UINT ESRAMUsageBytes;
//};


typedef enum WDEVENT_TYPE : int
{
	WDEVENT_TYPE_INVALID = 0,
    WDEVENT_TYPE_KEYBOARD_ENGAGE
} WDEVENT_TYPE;

extern "C" const GUID  DXGI_DEBUG_ALL;
DEFINE_GUID(DXGI_DEBUG_DX, 0x35cdd7fc, 0x13b2, 0x421d, 0xa5, 0xd7, 0x7e, 0x44, 0x51, 0x28, 0x7d, 0x64);
DEFINE_GUID(DXGI_DEBUG_DXGI, 0x25cddaa4, 0xb1c6, 0x47e1, 0xac, 0x3e, 0x98, 0x87, 0x5b, 0x5a, 0x2e, 0x2a);
DEFINE_GUID(DXGI_DEBUG_APP, 0x6cd6e01, 0x4219, 0x4ebd, 0x87, 0x9, 0x27, 0xed, 0x23, 0x36, 0xc, 0x62);

DEFINE_GUID(DXGI_DEBUG_D3D11, 0x4b99317b, 0xac39, 0x4aa6, 0xbb, 0xb, 0xba, 0xa0, 0x47, 0x84, 0x79, 0x8f);

#endif