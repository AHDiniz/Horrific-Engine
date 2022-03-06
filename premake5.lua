workspace "HorrificEngine"
    configurations { "Debug", "Release" }

project "HorrificEngine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs { "include/", "vendor/glad/include/glad/", "vendor/glad/include/KHR/", "vendor/glfw/include" }
    libdirs { "vendor/glad", "vendor/glfw" }
    pchheader "include/pch.h"

    files { "include/**.h", "src/**.c", "src/**.cpp", "src/core/*.cpp" }

    cppdialect "C++17"

    if os.target() == "windows" then
        defines { "WINDOWS" }
        links {"opengl32", "glad", "glfw3", "gdi32", "glu32"}
    elseif os.target() == "linux" then
        defines { "LINUX" }
        links {"glfw", "GL", "pthread", "Xrandr", "glad", "dl"}
    end

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        symbols "Off"

    filter {"action:gmake2"}
        toolset "gcc"
        makesettings {"CC:=gcc", "CXX:=g++", "AR:=ar"}

    filter {"action:gmake"}
        toolset "gcc"
        makesettings {"CC:=gcc", "CXX:=g++", "AR:=ar"}
