#pragma once

namespace WinDurango
{
	class Overlay
	{
	public:
		Overlay(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain1* pSwapchain);
		~Overlay( );
		void Initialize();
		void Shutdown( );
		void EnableKeyboard( );
		void Present( );

	private:
		bool m_bOpen = false;
		bool m_bKeyboard = false;

		ID3D11Device* m_pDevice = nullptr;
		ID3D11DeviceContext* m_pContext = nullptr;
		IDXGISwapChain1* m_pSwapchain = nullptr;
		ID3D11RenderTargetView* m_pRenderTargetView;
	};

	inline Overlay* g_Overlay = nullptr;
	inline HANDLE g_KeyboardFinished;
	inline char g_KeyboardText[ 256 ];
}
