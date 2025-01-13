#pragma once
#include "IDXGI.h"


namespace d3d11x
{
    class IDXGIFactoryWrapper : public d3d11x::IDXGIFactory2_X
    {
    public:

        IDXGIFactoryWrapper(IDXGIFactory2* factory) : m_realFactory(factory)
        {
            m_RefCount = 1;
        }


        // IGraphicsUnknown
        HRESULT QueryInterface(REFIID riid, void** ppvObject) override;

        


        ULONG AddRef( ) override;
        ULONG Release( ) override;

        // IDXGIObject
        HRESULT STDMETHODCALLTYPE SetPrivateData(_In_  REFGUID Name, UINT DataSize, _In_reads_bytes_(DataSize)  const void* pData) override;
        HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(_In_  REFGUID Name, _In_opt_  const IUnknown* pUnknown) override;
        HRESULT STDMETHODCALLTYPE GetPrivateData(_In_  REFGUID Name, _Inout_  UINT* pDataSize, _Out_writes_bytes_(*pDataSize)  void* pData) override;
        HRESULT STDMETHODCALLTYPE GetParent(_In_  REFIID riid, _COM_Outptr_  void** ppParent) override;

        // IDXGIFactory
        HRESULT STDMETHODCALLTYPE EnumAdapters(
            UINT Adapter,
            IDXGIAdapter** ppAdapter) override;
        HRESULT STDMETHODCALLTYPE MakeWindowAssociation(
            HWND WindowHandle,
            UINT Flags) override;
        HRESULT STDMETHODCALLTYPE GetWindowAssociation(
            HWND* pWindowHandle) override;
        HRESULT STDMETHODCALLTYPE CreateSwapChain(
            IGraphicsUnknown* pDevice,
            DXGI_SWAP_CHAIN_DESC* pDesc,
            IDXGISwapChain** ppSwapChain) override;
        HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(
            HMODULE Module,
            IDXGIAdapter** ppAdapter) override;


        // IDXGIFactory1
        HRESULT STDMETHODCALLTYPE EnumAdapters1(UINT Adapter, IDXGIAdapter1** ppAdapter) override;
        BOOL STDMETHODCALLTYPE IsCurrent(void) override;


        // IDXGIFactory2
        BOOL STDMETHODCALLTYPE IsWindowedStereoEnabled(void) override;

        HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd(IGraphicsUnknown* pDevice,
            HWND hWnd, const DXGI_SWAP_CHAIN_DESC1* pDesc,
            const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
            IDXGIOutput* pRestrictToOutput,
            IDXGISwapChain1** ppSwapChain) override;

        HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow(
            IGraphicsUnknown* pDevice,
            IUnknown* pWindow,
            DXGI_SWAP_CHAIN_DESC1* pDesc,
            IDXGIOutput* pRestrictToOutput,
            IDXGISwapChain1_X** ppSwapChain) override;


        HRESULT STDMETHODCALLTYPE GetSharedResourceAdapterLuid(
            HANDLE hResource,
            LUID* pLuid) override;
        HRESULT STDMETHODCALLTYPE RegisterStereoStatusWindow(
            HWND WindowHandle,
            UINT wMsg,
            DWORD* pdwCookie) override;
        HRESULT STDMETHODCALLTYPE RegisterStereoStatusEvent(
            HANDLE hEvent,
            DWORD* pdwCookie) override;
        void STDMETHODCALLTYPE UnregisterStereoStatus(
            DWORD dwCookie) override;
        HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusWindow(
            HWND WindowHandle,
            UINT wMsg,
            DWORD* pdwCookie) override;
        HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusEvent(
            HANDLE hEvent,
            DWORD* pdwCookie) override;
        void STDMETHODCALLTYPE UnregisterOcclusionStatus(
            DWORD dwCookie) override;
        HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition(
            IGraphicsUnknown* pDevice,
            const DXGI_SWAP_CHAIN_DESC1* pDesc,
            IDXGIOutput* pRestrictToOutput,
            IDXGISwapChain1** ppSwapChain) override;

    private:
        ::IDXGIFactory2* m_realFactory;
    };

    

    class IDXGIAdapterWrapper : public IDXGIAdapter_X
    {
    public:

        IDXGIAdapterWrapper(IDXGIAdapter* adapter) : m_realAdapter(adapter)
        {
            m_RefCount = 1;
        }



        // IGraphicsUnknown
        HRESULT QueryInterface(REFIID riid, void** ppvObject) override;
        ULONG AddRef( ) override;
        ULONG Release( ) override;

        // IDXGIObject
        HRESULT STDMETHODCALLTYPE SetPrivateData(_In_  REFGUID Name, UINT DataSize, _In_reads_bytes_(DataSize)  const void* pData) override;
        HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(_In_  REFGUID Name, _In_opt_  const IUnknown* pUnknown) override;
        HRESULT STDMETHODCALLTYPE GetPrivateData(_In_  REFGUID Name, _Inout_  UINT* pDataSize, _Out_writes_bytes_(*pDataSize)  void* pData) override;
        HRESULT STDMETHODCALLTYPE GetParent(_In_  REFIID riid, _COM_Outptr_  void** ppParent) override;

        HRESULT STDMETHODCALLTYPE EnumOutputs(
             UINT Output,
             IDXGIOutput** ppOutput) override;

        HRESULT STDMETHODCALLTYPE GetDesc(
            DXGI_ADAPTER_DESC* pDesc) override;

        HRESULT STDMETHODCALLTYPE CheckInterfaceSupport(
            REFGUID InterfaceName,
            LARGE_INTEGER* pUMDVersion) override;

    private:
        ::IDXGIAdapter* m_realAdapter;
    };

    class IDXGIDeviceWrapper : public IDXGIDevice_X
    {
    public:

        IDXGIDeviceWrapper(IDXGIDevice1* device) : m_realDevice(device)
        {
            m_RefCount = 1;
        }

        // IGraphicsUnknown
        HRESULT QueryInterface(REFIID riid, void** ppvObject) override;
        ULONG AddRef( ) override;
        ULONG Release( ) override;

        // IDXGIObject
        HRESULT STDMETHODCALLTYPE SetPrivateData(_In_  REFGUID Name, UINT DataSize, _In_reads_bytes_(DataSize)  const void* pData) override;
        HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(_In_  REFGUID Name, _In_opt_  const IUnknown* pUnknown) override;
        HRESULT STDMETHODCALLTYPE GetPrivateData(_In_  REFGUID Name, _Inout_  UINT* pDataSize, _Out_writes_bytes_(*pDataSize)  void* pData) override;
        HRESULT STDMETHODCALLTYPE GetParent(_In_  REFIID riid, _COM_Outptr_  void** ppParent) override;

        HRESULT STDMETHODCALLTYPE GetAdapter(
            _COM_Outptr_  IDXGIAdapter_X** pAdapter) override;

        HRESULT STDMETHODCALLTYPE CreateSurface(
            _In_  const DXGI_SURFACE_DESC* pDesc,
            UINT NumSurfaces,
            DXGI_USAGE Usage,
            _In_opt_  const DXGI_SHARED_RESOURCE* pSharedResource,
            _Out_writes_(NumSurfaces)  IDXGISurface** ppSurface) override;

        HRESULT STDMETHODCALLTYPE QueryResourceResidency(
            _In_reads_(NumResources)  IGraphicsUnknown** ppResources,
            _Out_writes_(NumResources)  DXGI_RESIDENCY* pResidencyStatus,
             UINT NumResources) override;

        HRESULT STDMETHODCALLTYPE SetGPUThreadPriority(
            INT Priority) override;

        HRESULT STDMETHODCALLTYPE GetGPUThreadPriority(
            _Out_  INT* pPriority) override;

    private:
        ::IDXGIDevice* m_realDevice;
    };




    class IDXGISwapChainWrapper : public IDXGISwapChain1_X
    {
    public:

        IDXGISwapChainWrapper(IDXGISwapChain1* swapchain) : m_realSwapchain(swapchain)
        {
            m_RefCount = 1;
        }

        // IGraphicsUnknown
        HRESULT QueryInterface(REFIID riid, void** ppvObject) override;
        ULONG AddRef( ) override;
        ULONG Release( ) override;

        // IDXGIObject
        HRESULT STDMETHODCALLTYPE SetPrivateData(_In_  REFGUID Name, UINT DataSize, _In_reads_bytes_(DataSize)  const void* pData) override;
        HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(_In_  REFGUID Name, _In_opt_  const IUnknown* pUnknown) override;
        HRESULT STDMETHODCALLTYPE GetPrivateData(_In_  REFGUID Name, _Inout_  UINT* pDataSize, _Out_writes_bytes_(*pDataSize)  void* pData) override;
        HRESULT STDMETHODCALLTYPE GetParent(_In_  REFIID riid, _COM_Outptr_  void** ppParent) override;

        // IDXGIDeviceSubObject
        HRESULT STDMETHODCALLTYPE GetDevice(
            /* [annotation][in] */
            _In_  REFIID riid,
            /* [annotation][retval][out] */
            _COM_Outptr_  void** ppDevice) override;
    

        // IDXGISwapChain
        HRESULT STDMETHODCALLTYPE Present(
            /* [in] */ UINT SyncInterval,
            /* [in] */ UINT Flags) override;

        HRESULT STDMETHODCALLTYPE GetBuffer(
            /* [in] */ UINT Buffer,
            /* [annotation][in] */
            _In_  REFIID riid,
            /* [annotation][out][in] */
            _COM_Outptr_  void** ppSurface) override;

        HRESULT STDMETHODCALLTYPE SetFullscreenState(
            /* [in] */ BOOL Fullscreen,
            /* [annotation][in] */
            _In_opt_  IDXGIOutput* pTarget) override;

        HRESULT STDMETHODCALLTYPE GetFullscreenState(
            /* [annotation][out] */
            _Out_opt_  BOOL* pFullscreen,
            /* [annotation][out] */
            _COM_Outptr_opt_result_maybenull_  IDXGIOutput** ppTarget) override;

        HRESULT STDMETHODCALLTYPE GetDesc(
            /* [annotation][out] */
            _Out_  DXGI_SWAP_CHAIN_DESC* pDesc) override;

        HRESULT STDMETHODCALLTYPE ResizeBuffers(
            /* [in] */ UINT BufferCount,
            /* [in] */ UINT Width,
            /* [in] */ UINT Height,
            /* [in] */ DXGI_FORMAT NewFormat,
            /* [in] */ UINT SwapChainFlags) override;

        HRESULT STDMETHODCALLTYPE ResizeTarget(
            /* [annotation][in] */
            _In_  const DXGI_MODE_DESC* pNewTargetParameters) override;

        HRESULT STDMETHODCALLTYPE GetContainingOutput(
            /* [annotation][out] */
            _COM_Outptr_  IDXGIOutput** ppOutput) override;

        HRESULT STDMETHODCALLTYPE GetFrameStatistics(
            /* [annotation][out] */
            _Out_  DXGI_FRAME_STATISTICS* pStats) override;

        HRESULT STDMETHODCALLTYPE GetLastPresentCount(
            /* [annotation][out] */
            _Out_  UINT* pLastPresentCount) override;




        HRESULT STDMETHODCALLTYPE GetDesc1(
            /* [annotation][out] */
            _Out_  DXGI_SWAP_CHAIN_DESC1* pDesc) override;

        HRESULT STDMETHODCALLTYPE GetFullscreenDesc(
            /* [annotation][out] */
            _Out_  DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc) override;

        HRESULT STDMETHODCALLTYPE GetHwnd(
            /* [annotation][out] */
            _Out_  HWND* pHwnd) override;

        HRESULT STDMETHODCALLTYPE GetCoreWindow(
            /* [annotation][in] */
            _In_  REFIID refiid,
            /* [annotation][out] */
            _COM_Outptr_  void** ppUnk) override;

        HRESULT STDMETHODCALLTYPE Present1(
            /* [in] */ UINT SyncInterval,
            /* [in] */ UINT PresentFlags,
            /* [annotation][in] */
            _In_  const DXGI_PRESENT_PARAMETERS* pPresentParameters) override;

        BOOL STDMETHODCALLTYPE IsTemporaryMonoSupported(void) override;

        HRESULT STDMETHODCALLTYPE GetRestrictToOutput(
            /* [annotation][out] */
            _Out_  IDXGIOutput** ppRestrictToOutput) override;

        HRESULT STDMETHODCALLTYPE SetBackgroundColor(
            /* [annotation][in] */
            _In_  const DXGI_RGBA* pColor)override;

        HRESULT STDMETHODCALLTYPE GetBackgroundColor(
            /* [annotation][out] */
            _Out_  DXGI_RGBA* pColor) override;

        HRESULT STDMETHODCALLTYPE SetRotation(
            /* [annotation][in] */
            _In_  DXGI_MODE_ROTATION Rotation) override;

        HRESULT STDMETHODCALLTYPE GetRotation(
            /* [annotation][out] */
            _Out_  DXGI_MODE_ROTATION* pRotation) override;



    private:
        IDXGISwapChain1* m_realSwapchain;
    };

}