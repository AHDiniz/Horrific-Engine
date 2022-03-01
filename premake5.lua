workspace "HorrificEngine"
    configurations { "Debug", "Release" }

project "HorrificEngine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs { "include/", "vendor/glad/include/glad/", "vendor/glad/include/KHR/" }
    pchheader "include/pch.h"

    files { "**.h", "**.c", "**.cpp" }

    filter "configurations:Debug"

        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "RELEASE" }
        symbols "Off"

    filter "action:gmake2"
        buildoptions { "CC=gcc" }