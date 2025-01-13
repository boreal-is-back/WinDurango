#include "pch.h"
#include "ConnectedStorage.h"
#include <shlobj.h>
#include <strsafe.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <robuffer.h>

winrt::Windows::Foundation::IAsyncAction WinDurango::impl::ConnectedStorage::CreateContainer(winrt::hstring name) const
{
    printf("[ConnectedStorage] Container %S requested creation\n", name.c_str());

    if (!co_await DoesFolderExist(storagePath + L"\\" + name))
    {
        auto folder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(storagePath);
        co_await folder.CreateFolderAsync(name);
    }

	printf("[ConnectedStorage] Container %S created\n", name.c_str());
}

winrt::Windows::Foundation::IAsyncAction WinDurango::impl::ConnectedStorage::Read(
    winrt::hstring containerName, winrt::Windows::Foundation::Collections::IMapView<winrt::hstring, winrt::Windows::Storage::Streams::IBuffer> data) const
{
    if (!co_await DoesFolderExist(storagePath + L"\\" + containerName)) {
        co_await CreateContainer(containerName);
        //printf("[ConnectedStorage] Container %S created\n", containerName.c_str( ));
    }

    auto folder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(storagePath + L"\\" + containerName);

    for (auto const& pair : data)
    {
        auto fileName = pair.Key();
        printf("FileName -> %ls | folder -> %ls\n", fileName.c_str(), folder.Path().c_str());
        auto file = co_await folder.GetFileAsync(fileName);
        auto fileBuffer = co_await winrt::Windows::Storage::FileIO::ReadBufferAsync(file);
        auto bufferByteAccess = fileBuffer.as<Windows::Storage::Streams::IBufferByteAccess>();
        uint8_t* fileData = nullptr;
        bufferByteAccess->Buffer(&fileData);
        auto dataBuffer = pair.Value();
        auto dataBufferByteAccess = dataBuffer.as<Windows::Storage::Streams::IBufferByteAccess>();
        uint8_t* dataBufferData = nullptr;
        dataBufferByteAccess->Buffer(&dataBufferData);
        memcpy(dataBufferData, fileData, fileBuffer.Length());
    }
}

winrt::Windows::Foundation::IAsyncAction WinDurango::impl::ConnectedStorage::Upload(
    winrt::hstring containerName,
    winrt::Windows::Foundation::Collections::IMapView<winrt::hstring, winrt::Windows::Storage::Streams::IBuffer> blobsToWrite,
    winrt::Windows::Foundation::Collections::IIterable<winrt::hstring> blobsToDelete) const
{
    if (!co_await DoesFolderExist(storagePath + L"\\" + containerName)) {
        co_await CreateContainer(containerName);
        //printf("[ConnectedStorage] Container %S created\n", containerName.c_str( ));
    }

    auto folder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(storagePath + L"\\" + containerName);
    
    for (auto const& pair : blobsToWrite)
    {
        auto fileName = pair.Key();
        auto dataBuffer = pair.Value();
        auto file = co_await folder.CreateFileAsync(fileName, winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting);
        co_await winrt::Windows::Storage::FileIO::WriteBufferAsync(file, dataBuffer);
    }

    //for (auto const& blobName : blobsToDelete)
    //{
    //    auto file = co_await folder.GetFileAsync(blobName);
    //    co_await file.DeleteAsync();
    //}
}

winrt::hstring WinDurango::impl::ConnectedStorage::ObtainPackageName()
{
    return winrt::Windows::ApplicationModel::Package::Current( ).Id( ).FamilyName( );
}

winrt::Windows::Foundation::IAsyncOperation<bool> WinDurango::impl::ConnectedStorage::DoesFolderExist(
	winrt::hstring path)
{
    try
    {
        co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(path);
    }
    catch (...)
    {
        co_return false;
    }

    co_return true;
}

winrt::Windows::Foundation::IAsyncOperation<bool> WinDurango::impl::ConnectedStorage::DoesFileExist(
	winrt::Windows::Storage::StorageFolder folder, winrt::hstring path)
{
	try
	{
		co_await folder.GetFileAsync(path);
		co_return true;
	}
	catch (...)
	{
		co_return false;
	}
}

winrt::Windows::Foundation::IAsyncAction WinDurango::impl::ConnectedStorage::CreateDirectories(const wchar_t* storageType, winrt::hstring& storagePath)
{
    co_await winrt::resume_background( );

    winrt::hstring packageName = ObtainPackageName( );
    if (packageName.empty( )) {
        co_return;
    }

    winrt::hstring folderPath = winrt::Windows::Storage::ApplicationData::Current( ).LocalFolder( ).Path( ) + L"\\WinDurango";

    if (!co_await DoesFolderExist(folderPath)) {
        auto folder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(winrt::Windows::Storage::ApplicationData::Current( ).LocalFolder( ).Path( ));
        co_await folder.CreateFolderAsync(L"WinDurango");
    }

    folderPath = folderPath + L"\\" + storageType;

    if (!co_await DoesFolderExist(folderPath))
    {
        auto folder = co_await winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(winrt::Windows::Storage::ApplicationData::Current( ).LocalFolder( ).Path( ) + L"\\WinDurango");
        co_await folder.CreateFolderAsync(storageType);
    }

	storagePath = folderPath;
}

winrt::Windows::Foundation::IAsyncAction WinDurango::impl::ConnectedStorage::InitializeStorage()
{
	co_await CreateDirectories(L"UserStorage", storagePath);

    printf("[ConnectedStorage] User storage initialized at %S\n", storagePath.c_str());
}
