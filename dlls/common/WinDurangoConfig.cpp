#include "WinDurangoConfig.h"
#include <iostream>
#include "toml.hpp"
#include <filesystem>


std::string Config::getVersion()
{
    return version;
}

HRESULT Config::load()
{
    toml::parse_result result = toml::parse_file(getConfigFilePath());

    auto toml = std::move(result);

    // is there not some funny reflection shit I can do lol
    ingameName = toml[ "ingameName" ].value<std::string>().value_or("The Durangler");
    debugLogging = toml[ "debugLogging" ].value<bool>( ).value_or(true);
    logToFile = toml[ "logToFile" ].value<bool>( ).value_or(true);

    return S_OK;
}

HRESULT Config::init() {
    PWSTR folder = getConfigFolder();

    if (folder == nullptr)
        return S_FALSE;

    if (!std::filesystem::exists(folder))
        std::filesystem::create_directories(folder);

    std::wstring file = getConfigFilePath();

    if (!std::filesystem::exists(file))
        save();

    load();
}

HRESULT Config::save()
{
    auto configFile = std::ofstream(getConfigFilePath());

    auto toml = toml::table{ { 
        { "configVersion", getVersion() },
        { "ingameName", ingameName },
        { "debugLogging", debugLogging },
        { "logToFile", logToFile }
    } };

    configFile << toml;

    configFile.close();

    return S_OK;
}

PWSTR Config::getConfigFolder()
{
    PWSTR path = NULL;
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);

    if (FAILED(hr)) {
        // todo: replace with logger
        std::cerr << "Couldn't get config path: " << hr << std::endl;
        return nullptr;
    }

    // I feel like it should return wstring instead but will leave it for now since it doesn't matter much at this moment I think.
    return path;
}

std::wstring Config::getConfigFilePath()
{
    PWSTR path = getConfigFolder();

    if (path == nullptr)
        return nullptr;

    std::wstring configPath = path;
    configPath += L"\\config.toml";

    CoTaskMemFree(path);
    return configPath;
}
