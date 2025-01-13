#include "pch.h"
#include "overlay.h"
#include "../../../thirdparty/imgui/imgui.h"
#include "../../../thirdparty/imgui/backends/imgui_impl_dx11.h"
#include "../../../thirdparty/imgui_impl_uwp.h"
#include <winrt/windows.graphics.display.h>

WinDurango::Overlay::Overlay(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain1* pSwapchain):
	m_pRenderTargetView(nullptr)
{
	m_pDevice = pDevice;
	m_pContext = pContext;
	m_pSwapchain = pSwapchain;
}

WinDurango::Overlay::~Overlay()
{
	Shutdown( );
	m_pDevice = nullptr;
	m_pContext = nullptr;
	m_pSwapchain = nullptr;
}

// This should be called when Run is called by the game inside the wrapper.
void WinDurango::Overlay::Initialize()
{
	ID3D11Texture2D* pBackBuffer;

	m_pSwapchain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	m_pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView);

	IMGUI_CHECKVERSION( );
	ImGui::CreateContext( );
	ImGuiIO& io = ImGui::GetIO( ); (void) io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);

	ImGui::StyleColorsDark( );

	ImGui_ImplUwp_InitForCurrentView( );
	ImGui_ImplDX11_Init(m_pDevice, m_pContext);
}

void WinDurango::Overlay::Shutdown()
{
	ImGui_ImplDX11_Shutdown( );
	ImGui_ImplUwp_Shutdown( );
	ImGui::DestroyContext( );
}

void WinDurango::Overlay::Present() const
{
	//ImVec4 clear_color = ImVec4(255, 255, 255, 0);
	ImGui_ImplDX11_NewFrame( );
	ImGui_ImplUwp_NewFrame( );
	ImGui::NewFrame( );

	ImGui::ShowDemoWindow();
	ImGui::Render( );

	//const float clear_color_with_alpha[ 4 ] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };

	m_pContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);
	//m_pContext->ClearRenderTargetView(m_pRenderTargetView, clear_color_with_alpha);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData( ));

	//m_pSwapchain->Present(1, 0);
}
