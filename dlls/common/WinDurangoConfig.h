#pragma once
#include <string>
#include <winerror.h>
#include <shlobj_core.h>
class Config
{
	private:
		static inline std::string version = "idk";
	public:
		// maybe move to own class?
		// Name in-game
		static inline std::string ingameName = "The Durangler";
		// Should log debug stuff (potentially spammy)
		static inline bool debugLogging = true;
		// Should log to a file
		static inline bool logToFile = true;

		// Gets the version of WinDurango
		static std::string getVersion( );
		// Loads settings from the settings file.
		static HRESULT load( );
		// Loads the settings, and if the config doesn't exist yet, creates it.
		static HRESULT init( );
		// Saves modified settings to a file, not really needed unless a setting is modified from within the emulator.
		static HRESULT save( );
		// Gets the config folder (%appdata%\WinDurango)
		static PWSTR getConfigFolder( );
		// Gets the config file path (%appdata%\WinDurango\config.toml)
		static std::wstring getConfigFilePath( );
};

