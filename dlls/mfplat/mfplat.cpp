#include "pch.h"

#include <mmreg.h>

HRESULT MFCreateDxvaSampleRendererX_X(void* pDevice, void* pAttribute, void** pObject)
{
	return E_NOTIMPL;
}

HRESULT MFCreateDXGIDeviceManager_X(UINT* resetToken, void** ppDeviceManager)
{
	return E_NOTIMPL;
}

HRESULT MFResetDXGIDeviceManagerX_X(
         void* pDeviceManager,
         void* pUnkDevice,
         UINT resetToken
)
{
	return E_NOTIMPL;
}

HRESULT MFCreateAttributes_X(
         void** ppMFAttributes,
         UINT32 cInitialSize
)
{
	return E_NOTIMPL;
}

HRESULT MFCreateMediaType_X(
         void** ppMFType
)
{
	return E_NOTIMPL;
}

HRESULT MFStartup_X(
         ULONG Version,
         DWORD dwFlags
)
{
	return E_NOTIMPL;
}

HRESULT MFShutdown_X( )
{
	return E_NOTIMPL;
}

HRESULT __fastcall MFCreateNV12ToRGB32ConverterX_X(void*, void*, void*)
{
	return E_NOTIMPL;
}

HRESULT(MFCreateWaveFormatExFromMFMediaType_X)(void* pMFType, void** ppWF, UINT32* pcbSize, UINT32 Flags) {
	return E_NOTIMPL;
}

HRESULT MFInitMediaTypeFromWaveFormatEx_X(
         void* pMFType,
         const WAVEFORMATEX* pWaveFormat,
         UINT32 cbBufSize
)
{
	return E_NOTIMPL;
}