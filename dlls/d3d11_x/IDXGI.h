#pragma once
#include "pch.h"
#include "d3d_x/d3d11_x_device.h"
#include "d3d_x/d3d_x.hpp"
#include <typeinfo>



namespace d3d11x
{
    struct IDXGISwapChain1_X;
   

    //MIDL_INTERFACE("aec22fb8-76f3-4639-9be0-28eb43a67a2e")
    struct IDXGIObject_X : public IGraphicsUnknown
    {
        /* 0x0000: fields for IGraphicsUnknown */
    /* 0x0010 */ public: void* m_pPrivateData;

    public:
        virtual HRESULT STDMETHODCALLTYPE SetPrivateData(_In_  REFGUID Name, UINT DataSize, _In_reads_bytes_(DataSize)  const void* pData) PURE;
        virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(_In_  REFGUID Name, _In_opt_  const IUnknown* pUnknown) PURE;
        /*virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterfaceGraphics(_In_ REFGUID Name, const IGraphicsUnknown* data)
        {
            return this->SetPrivateDataInterface(Name, reinterpret_cast<IUnknown const*>(data));
        }*/
        virtual HRESULT STDMETHODCALLTYPE GetPrivateData(_In_  REFGUID Name, _Inout_  UINT* pDataSize, _Out_writes_bytes_(*pDataSize)  void* pData) PURE;
        virtual HRESULT STDMETHODCALLTYPE GetParent(_In_  REFIID riid, _COM_Outptr_  void** ppParent) PURE;
    };




    // Adapted to Xbox one (look at pdb)
    //MIDL_INTERFACE("7b7166ec-21c7-44ae-b21a-c9ae321ae369")
    struct IDXGIFactory_X : public IDXGIObject_X
    {
    public:

        /* 0x0000: fields for IDXGIObject */
    /* 0x0018 */ public: IDXGIAdapter2* m_pAdapter;

                       virtual HRESULT STDMETHODCALLTYPE EnumAdapters(
                           UINT Adapter,

                           IDXGIAdapter** ppAdapter) PURE;

                       virtual HRESULT STDMETHODCALLTYPE MakeWindowAssociation(
                           HWND WindowHandle,
                           UINT Flags) PURE;

                       virtual HRESULT STDMETHODCALLTYPE GetWindowAssociation(
                           HWND* pWindowHandle) PURE;

                       virtual HRESULT STDMETHODCALLTYPE CreateSwapChain(
                           IGraphicsUnknown* pDevice,
                           DXGI_SWAP_CHAIN_DESC* pDesc,
                           IDXGISwapChain** ppSwapChain) PURE;

                       virtual HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(
                           HMODULE Module,
                           IDXGIAdapter** ppAdapter) PURE;

    };


    // Adapted to Xbox one (look at pdb)
    //MIDL_INTERFACE("770aae78-f26f-4dba-a829-253c83d1b387")
    struct IDXGIFactory1_X : public IDXGIFactory_X
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumAdapters1(UINT Adapter, IDXGIAdapter1** ppAdapter) PURE;

        virtual BOOL STDMETHODCALLTYPE IsCurrent(void) PURE;
    };


    // Adapted to Xbox one (look at pdb)
    //MIDL_INTERFACE("50c83a1c-e072-4c48-87b0-3630fa36a6d0")
    struct IDXGIFactory2_X : public IDXGIFactory1_X
    {
    public:
        virtual BOOL STDMETHODCALLTYPE IsWindowedStereoEnabled(void) PURE;



        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd(IGraphicsUnknown* pDevice,
            HWND hWnd, const DXGI_SWAP_CHAIN_DESC1* pDesc,
            const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
            IDXGIOutput* pRestrictToOutput,
            IDXGISwapChain1** ppSwapChain) PURE;

        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow(
           IGraphicsUnknown* pDevice,
           IUnknown* pWindow,
           DXGI_SWAP_CHAIN_DESC1* pDesc,
           IDXGIOutput* pRestrictToOutput,
           IDXGISwapChain1_X** ppSwapChain) PURE;

        virtual HRESULT STDMETHODCALLTYPE GetSharedResourceAdapterLuid(
            HANDLE hResource,
            LUID* pLuid) PURE;

        virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusWindow(
            HWND WindowHandle,
            UINT wMsg,
            DWORD* pdwCookie) PURE;

        virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusEvent(
            HANDLE hEvent,
            DWORD* pdwCookie) PURE;

        virtual void STDMETHODCALLTYPE UnregisterStereoStatus(
            DWORD dwCookie) PURE;

        virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusWindow(
            HWND WindowHandle,
            UINT wMsg,
            DWORD* pdwCookie) PURE;

        virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusEvent(
            HANDLE hEvent,
            DWORD* pdwCookie) PURE;

        virtual void STDMETHODCALLTYPE UnregisterOcclusionStatus(
            DWORD dwCookie) PURE;

        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition(
            IGraphicsUnknown* pDevice,
            const DXGI_SWAP_CHAIN_DESC1* pDesc,
            IDXGIOutput* pRestrictToOutput,
            IDXGISwapChain1** ppSwapChain) PURE;

    };


    struct IDXGIAdapter_X : IDXGIObject_X
    {
        virtual HRESULT STDMETHODCALLTYPE EnumOutputs(UINT Output, IDXGIOutput** ppOutput) PURE;

        virtual HRESULT STDMETHODCALLTYPE GetDesc(DXGI_ADAPTER_DESC* pDesc) PURE;

        virtual HRESULT STDMETHODCALLTYPE CheckInterfaceSupport(REFGUID InterfaceName, LARGE_INTEGER* pUMDVersion) PURE;

    };

    struct IDXGIDevice_X : d3d11x::IDXGIObject_X
    {
        virtual HRESULT STDMETHODCALLTYPE GetAdapter(IDXGIAdapter_X** pAdapter) PURE;

        virtual HRESULT STDMETHODCALLTYPE CreateSurface(const DXGI_SURFACE_DESC* pDesc, UINT NumSurfaces, DXGI_USAGE Usage,
            const DXGI_SHARED_RESOURCE* pSharedResource,
            _Out_writes_(NumSurfaces)  IDXGISurface** ppSurface) PURE;

        virtual HRESULT STDMETHODCALLTYPE QueryResourceResidency(
            _In_reads_(NumResources)  IGraphicsUnknown** ppResources,
            _Out_writes_(NumResources)  DXGI_RESIDENCY* pResidencyStatus,
            /* [in] */ UINT NumResources) PURE;

        virtual HRESULT STDMETHODCALLTYPE SetGPUThreadPriority(
            /* [in] */ INT Priority) PURE;

        virtual HRESULT STDMETHODCALLTYPE GetGPUThreadPriority(
            _Out_  INT* pPriority) PURE;

    };
   

    struct IDXGIDeviceSubObject_X : public IDXGIObject_X
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDevice(
            /* [annotation][in] */
            _In_  REFIID riid,
            /* [annotation][retval][out] */
            _COM_Outptr_  void** ppDevice) = 0;
    };


    struct IDXGISwapChain_X : public IDXGIDeviceSubObject_X
    {
        virtual HRESULT STDMETHODCALLTYPE Present(
            /* [in] */ UINT SyncInterval,
            /* [in] */ UINT Flags) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetBuffer(
            /* [in] */ UINT Buffer,
            /* [annotation][in] */
            _In_  REFIID riid,
            /* [annotation][out][in] */
            _COM_Outptr_  void** ppSurface) = 0;

        virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(
            /* [in] */ BOOL Fullscreen,
            /* [annotation][in] */
            _In_opt_  IDXGIOutput* pTarget) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(
            /* [annotation][out] */
            _Out_opt_  BOOL* pFullscreen,
            /* [annotation][out] */
            _COM_Outptr_opt_result_maybenull_  IDXGIOutput** ppTarget) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetDesc(
            /* [annotation][out] */
            _Out_  DXGI_SWAP_CHAIN_DESC* pDesc) = 0;

        virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
            /* [in] */ UINT BufferCount,
            /* [in] */ UINT Width,
            /* [in] */ UINT Height,
            /* [in] */ DXGI_FORMAT NewFormat,
            /* [in] */ UINT SwapChainFlags) = 0;

        virtual HRESULT STDMETHODCALLTYPE ResizeTarget(
            /* [annotation][in] */
            _In_  const DXGI_MODE_DESC* pNewTargetParameters) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(
            /* [annotation][out] */
            _COM_Outptr_  IDXGIOutput** ppOutput) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
            /* [annotation][out] */
            _Out_  DXGI_FRAME_STATISTICS* pStats) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(
            /* [annotation][out] */
            _Out_  UINT* pLastPresentCount) = 0;

    };


    struct IDXGISwapChain1_X : public IDXGISwapChain_X
    {
    
        virtual HRESULT STDMETHODCALLTYPE GetDesc1(
            /* [annotation][out] */
            _Out_  DXGI_SWAP_CHAIN_DESC1 * pDesc) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetFullscreenDesc(
            /* [annotation][out] */
            _Out_  DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetHwnd(
            /* [annotation][out] */
            _Out_  HWND* pHwnd) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetCoreWindow(
            /* [annotation][in] */
            _In_  REFIID refiid,
            /* [annotation][out] */
            _COM_Outptr_  void** ppUnk) = 0;

        virtual HRESULT STDMETHODCALLTYPE Present1(
            /* [in] */ UINT SyncInterval,
            /* [in] */ UINT PresentFlags,
            /* [annotation][in] */
            _In_  const DXGI_PRESENT_PARAMETERS* pPresentParameters) = 0;

        virtual BOOL STDMETHODCALLTYPE IsTemporaryMonoSupported(void) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetRestrictToOutput(
            /* [annotation][out] */
            _Out_  IDXGIOutput** ppRestrictToOutput) = 0;

        virtual HRESULT STDMETHODCALLTYPE SetBackgroundColor(
            /* [annotation][in] */
            _In_  const DXGI_RGBA* pColor) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetBackgroundColor(
            /* [annotation][out] */
            _Out_  DXGI_RGBA* pColor) = 0;

        virtual HRESULT STDMETHODCALLTYPE SetRotation(
            /* [annotation][in] */
            _In_  DXGI_MODE_ROTATION Rotation) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetRotation(
            /* [annotation][out] */
            _Out_  DXGI_MODE_ROTATION* pRotation) = 0;

    };

}
