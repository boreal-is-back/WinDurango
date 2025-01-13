#include "pch.h"

#include <chrono>
#include <thread>

#include "IDXGIWrappers.h"
#include "ID3DWrappers.h"
#include "overlay/overlay.h"

namespace d3d11x
{
	// s/o to stackoverflow
    template<std::intmax_t FPS>
    class frame_rater {
    public:
        frame_rater( ) :
            time_between_frames{ 1 },
            tp{ std::chrono::steady_clock::now( ) }
        {
        }

        void sleep( ) {
            tp += time_between_frames;
            std::this_thread::sleep_until(tp);
        }

    private:
        std::chrono::duration<double, std::ratio<1, FPS>> time_between_frames;
        std::chrono::time_point<std::chrono::steady_clock, decltype(time_between_frames)> tp;
    };

	inline frame_rater<60> fps60 = {};

    HRESULT IDXGISwapChainWrapper::QueryInterface(REFIID riid, void** ppvObject)
    {
        if (riid == __uuidof(IDXGISwapChain1) || riid == __uuidof(IDXGISwapChain))
        {
            *ppvObject = this;
            AddRef( );
            return S_OK;
        }

        // DEBUG
        char iidstr[ sizeof("{AAAAAAAA-BBBB-CCCC-DDEE-FFGGHHIIJJKK}") ];
        OLECHAR iidwstr[ sizeof(iidstr) ];
        StringFromGUID2(riid, iidwstr, ARRAYSIZE(iidwstr));
        WideCharToMultiByte(CP_UTF8, 0, iidwstr, -1, iidstr, sizeof(iidstr), nullptr, nullptr);
        printf("[IDXGIDeviceWrapper] QueryInterface: %s\n", iidstr);

        *ppvObject = nullptr;
        return E_NOINTERFACE;
    }


    ULONG IDXGISwapChainWrapper::AddRef( )
    {
        printf("[IDXGISwapChainWrapper] --> AddRef\n");
        return InterlockedIncrement(&m_RefCount);
    }

    ULONG IDXGISwapChainWrapper::Release( )
    {
        printf("[IDXGISwapChainWrapper] --> Release\n");
        ULONG refCount = InterlockedDecrement(&m_RefCount);
        if (refCount == 0)
            delete this;
        return refCount;
    }

    HRESULT __stdcall IDXGISwapChainWrapper::SetPrivateData(REFGUID Name, UINT DataSize, const void* pData)
    {
        return m_realSwapchain->SetPrivateData(Name, DataSize, pData);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::SetPrivateDataInterface(REFGUID Name, const IUnknown* pUnknown)
    {
        return m_realSwapchain->SetPrivateDataInterface(Name, pUnknown);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetPrivateData(REFGUID Name, UINT* pDataSize, void* pData)
    {
        return m_realSwapchain->GetPrivateData(Name, pDataSize, pData);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetParent(REFIID riid, void** ppParent)
    {
        return m_realSwapchain->GetParent(riid, ppParent);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetDevice(REFIID riid, void** ppDevice)
    {
        return m_realSwapchain->GetDevice(riid, ppDevice);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::Present(UINT SyncInterval, UINT Flags)
    {
        WinDurango::g_Overlay->Present( );
        return m_realSwapchain->Present(SyncInterval, Flags);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetBuffer(UINT Buffer, REFIID riid, void** ppSurface)
    {
        if (riid == __uuidof(ID3D11Texture2D))
        {
            ID3D11Texture2D* texture2d = nullptr;
            HRESULT hr = m_realSwapchain->GetBuffer(Buffer, IID_PPV_ARGS(&texture2d));
            *ppSurface = new ID3D11Texture2DWrapper(texture2d);
            this->AddRef( );
            return hr;
        }

        *ppSurface = nullptr;
        return E_NOINTERFACE;
    }

    HRESULT __stdcall IDXGISwapChainWrapper::SetFullscreenState(BOOL Fullscreen, IDXGIOutput* pTarget)
    {
        return m_realSwapchain->SetFullscreenState(Fullscreen, pTarget);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetFullscreenState(BOOL* pFullscreen, IDXGIOutput** ppTarget)
    {
        return m_realSwapchain->GetFullscreenState(pFullscreen, ppTarget);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetDesc(DXGI_SWAP_CHAIN_DESC* pDesc)
    {
        return m_realSwapchain->GetDesc(pDesc);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::ResizeBuffers(UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
    {
        return m_realSwapchain->ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::ResizeTarget(const DXGI_MODE_DESC* pNewTargetParameters)
    {
        return m_realSwapchain->ResizeTarget(pNewTargetParameters);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetContainingOutput(IDXGIOutput** ppOutput)
    {
        return m_realSwapchain->GetContainingOutput(ppOutput);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetFrameStatistics(DXGI_FRAME_STATISTICS* pStats)
    {
        return m_realSwapchain->GetFrameStatistics(pStats);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetLastPresentCount(UINT* pLastPresentCount)
    {
        return m_realSwapchain->GetLastPresentCount(pLastPresentCount);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetDesc1(DXGI_SWAP_CHAIN_DESC1* pDesc)
    {
        return m_realSwapchain->GetDesc1(pDesc);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetFullscreenDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
    {
        return m_realSwapchain->GetFullscreenDesc(pDesc);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetHwnd(HWND* pHwnd)
    {
        return m_realSwapchain->GetHwnd(pHwnd);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetCoreWindow(REFIID refiid, void** ppUnk)
    {
        return m_realSwapchain->GetCoreWindow(refiid, ppUnk);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::Present1(UINT SyncInterval, UINT PresentFlags, const DXGI_PRESENT_PARAMETERS* pPresentParameters)
    {
		WinDurango::g_Overlay->Present( );

        if (pPresentParameters == nullptr) {
            //fps60.sleep( );
            return m_realSwapchain->Present(SyncInterval, PresentFlags);
        }

        return m_realSwapchain->Present1(SyncInterval, PresentFlags, pPresentParameters);
    }

    BOOL __stdcall IDXGISwapChainWrapper::IsTemporaryMonoSupported(void)
    {
        return m_realSwapchain->IsTemporaryMonoSupported();
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetRestrictToOutput(IDXGIOutput** ppRestrictToOutput)
    {
        return m_realSwapchain->GetRestrictToOutput(ppRestrictToOutput);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::SetBackgroundColor(const DXGI_RGBA* pColor)
    {
        return m_realSwapchain->SetBackgroundColor(pColor);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetBackgroundColor(DXGI_RGBA* pColor)
    {
        return m_realSwapchain->GetBackgroundColor(pColor);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::SetRotation(DXGI_MODE_ROTATION Rotation)
    {
        return m_realSwapchain->SetRotation(Rotation);
    }

    HRESULT __stdcall IDXGISwapChainWrapper::GetRotation(DXGI_MODE_ROTATION* pRotation)
    {
        return m_realSwapchain->GetRotation(pRotation);
    }
}