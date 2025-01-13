$game_path = "C:\\Users\\unixian\\Desktop\\reversing\\xb1\\minecraft_lce_xb1\\Mount"
$out_dll_dir = "C:\\Users\\unixian\\Documents\\GitHub\\WinDurango\\x64\\Debug"

function make-link ($dll_name) {
    Copy-Item "$out_dll_dir\\$dll_name" "$game_path\\$dll_name" -Force
}

Add-AppxPackage -Register "$game_path\\AppxManifest.xml"

make-link("winrt_x.dll")
make-link("AcpHal.dll")
make-link("appmodel.dll")
make-link("common.dll")
make-link("d3d11_x.dll")
make-link("etwplus.dll")
make-link("kernelx.dll")
make-link("mfplat.dll")
#make-link("MMDevAPI.dll")
make-link("XboxIntegratedMultiplayer.dll")
make-link("xg_x.dll")
make-link("XFrontPanelDisplay.dll")
make-link("XAudio2_9_x.dll")