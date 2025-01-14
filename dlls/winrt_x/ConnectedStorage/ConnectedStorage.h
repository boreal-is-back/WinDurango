#pragma once
#include <winrt/base.h>
#include <winrt/Windows.Storage.h>

namespace WinDurango::impl
{
	class ConnectedStorage
	{
	public:
		winrt::Windows::Foundation::IAsyncAction InitializeStorage( );
		winrt::Windows::Foundation::IAsyncAction CreateContainer(winrt::hstring name) const;
		winrt::Windows::Foundation::IAsyncAction Read(winrt::hstring containerName, winrt::Windows::Foundation::Collections::IMapView<winrt::hstring, winrt::Windows::Storage::Streams::IBuffer> data) const;
		winrt::Windows::Foundation::IAsyncAction Upload(winrt::hstring containerName, winrt::Windows::Foundation::Collections::IMapView<winrt::hstring, winrt::Windows::Storage::Streams::IBuffer> blobsToWrite, winrt::Windows::Foundation::Collections::IIterable<winrt::hstring> blobsToDelete) const;
		
		static winrt::Windows::Foundation::IAsyncAction CreateDirectories(const wchar_t* storageType, winrt::hstring &storagePath);
		static winrt::Windows::Foundation::IAsyncOperation<bool> DoesFolderExist(winrt::hstring path);
		static winrt::Windows::Foundation::IAsyncOperation<bool> DoesFileExist(winrt::Windows::Storage::StorageFolder folder, winrt::hstring path);

	private:
		static winrt::hstring ObtainPackageName( );
		

		winrt::hstring storagePath;
	};

	inline ConnectedStorage* s_userStorage;
	inline HANDLE h_ContainerWriteEvent;
	inline winrt::hstring h_DesiredContainerName;
}