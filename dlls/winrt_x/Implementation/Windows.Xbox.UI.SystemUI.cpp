#include "pch.h"
#include "Windows.Xbox.UI.SystemUI.h"

#include "Windows.Xbox.UI.AccountPickerResult.h"
#include "Windows.Xbox.UI.SystemUI.g.cpp"

// WARNING: This file is automatically generated by a tool. Do not directly
// add this file to your project, as any changes you make will be lost.
// This file is a stub you can use as a starting point for your implementation.
//
// To add a copy of this file to your project:
//   1. Copy this file from its original location to the location where you store 
//      your other source files (e.g. the project root). 
//   2. Add the copied file to your project. In Visual Studio, you can use 
//      Project -> Add Existing Item.
//   3. Delete this comment and the 'static_assert' (below) from the copied file.
//      Do not modify the original file.
//
// To update an existing file in your project:
//   1. Copy the relevant changes from this file and merge them into the copy 
//      you made previously.
//    
// This assertion helps prevent accidental modification of generated files.
//static_assert(false, "This file is generated by a tool and will be overwritten. Open this error and view the comment for assistance.");

void* g_pD3D11XEventFunc = nullptr;
void* g_pWDWaitForKeyboardFunc = nullptr;

namespace winrt::Windows::Xbox::UI::implementation
{
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowEpgAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Foundation::Collections::IKeyValuePair<hstring, winrt::Windows::Foundation::IInspectable>> propertySet)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowMiniguideAsync(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowProfileCardAsync(winrt::Windows::Xbox::System::IUser requestingUser, hstring targetXuid)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowSendInvitesAsync(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::AccountPickerResult> SystemUI::ShowAccountPickerAsync(winrt::Windows::Xbox::Input::IController controller, winrt::Windows::Xbox::UI::AccountPickerOptions options)
    {
		printf("TODO: SystemUI::ShowAccountPickerAsync (this function just returns the first user in User::Users)\n");
        co_return winrt::make<implementation::AccountPickerResult>( );
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> SystemUI::ShowVirtualKeyboardAsync(hstring defaultText, hstring titleText, hstring descriptionText, winrt::Windows::Xbox::UI::VirtualKeyboardInputScope inputScope)
    {
        co_await resume_background( );

		if (!g_pD3D11XEventFunc && !g_pWDWaitForKeyboardFunc)
		{
			g_pD3D11XEventFunc = GetProcAddress(GetModuleHandle(L"d3d11_x.dll"), "WD11XNotify");
			g_pWDWaitForKeyboardFunc = GetProcAddress(GetModuleHandle(L"d3d11_x.dll"), "WDWaitForKeyboard");
		}

        reinterpret_cast<void(__stdcall*)(int)>(g_pD3D11XEventFunc)(1);

		const char* text = nullptr;
		reinterpret_cast<void(__stdcall*)(const char**)>(g_pWDWaitForKeyboardFunc)(&text);

        co_return winrt::to_hstring(text);
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::LaunchPartyAsync(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::LaunchAchievementsAsync(winrt::Windows::Xbox::System::IUser requestingUser, uint32_t titleId)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowPartyAndSendPartyInvitesAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> recipientUserIdList)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowCreateLookingForGroupAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> preselectedTags, hstring preselectedDescription, uint32_t defaultNeedCount)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowUserLookingForGroupsAsync(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowLookingForGroupResultsAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> tags)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::LaunchKinectSetupAsync(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::LaunchRecentPlayersAsync(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::SnapDefaultBroadcastApp(winrt::Windows::Xbox::System::IUser requestingUser)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowComposeMessageAsync(winrt::Windows::Xbox::System::IUser requestingUser, hstring defaultMessageText, winrt::Windows::Foundation::Collections::IVector<hstring> recipientUserIdList)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::AddRemoveFriendResult> SystemUI::ShowAddRemoveFriendAsync(winrt::Windows::Xbox::System::IUser requestingUser, hstring targetUserId)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<hstring>> SystemUI::ShowPeoplePickerAsync(winrt::Windows::Xbox::System::IUser requestingUser, hstring promptText, winrt::Windows::Foundation::Collections::IVectorView<hstring> selectFromUserIdList, winrt::Windows::Foundation::Collections::IVectorView<hstring> preselectedUserIdList, uint32_t minimumSelectionCount, uint32_t maximumSelectionCount)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<bool> SystemUI::TrySnapSelf()
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<bool> SystemUI::TrySnapOther(winrt::Windows::Foundation::Uri snapTargetUri, winrt::Windows::Xbox::System::IUser user)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction SystemUI::ShowMiniguideWithCommandAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Xbox::UI::MiniguideCommand initialCommand)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> SystemUI::ShowVirtualKeyboardWithOptionsAsync(winrt::Windows::Xbox::UI::KeyboardOptions options)
    {
        throw hresult_not_implemented();
    }
    void SystemUI::SetNotificationPositionHint(winrt::Windows::Xbox::UI::NotificationPositionHint const& value)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::WebAuthenticationResult> SystemUI::AuthenticateAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Xbox::UI::WebAuthenticationOptions options, winrt::Windows::Foundation::Uri requestUri, winrt::Windows::Foundation::Uri callbackUri)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::WebAuthenticationResult> SystemUI::AuthenticateAsync(winrt::Windows::Xbox::System::IUser requestingUser, winrt::Windows::Xbox::UI::WebAuthenticationOptions options, winrt::Windows::Foundation::Uri requestUri)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Uri SystemUI::GetCurrentApplicationCallbackUri(winrt::Windows::Xbox::System::IUser const& requestingUser)
    {
        throw hresult_not_implemented();
    }
}
