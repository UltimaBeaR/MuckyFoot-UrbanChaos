# Experimenting with Urban Chaos game

[Original readme](/README_ORIGINAL.md)

It's an attempt to make the game crossplatform (windows/linux/macos) and also move from x86 to optional ARM as well, add gamepad support (xbox, ps4/5 gamepads), mabe add some graphics options and fixing some issues with game.

As part1 i'm trying to remove as much unused/debug/editor-only code as i can so it's easier to understand code. Maby latter i get all removed code back when i figure out how to make game crossplatform.

Editor is not priority for now, i'm just trying to port game itself. Editor takes slot of code so i'm removing it for now.

It's seems that rewriting whole game to better architecture, or move to different game engine is going to be very time consuming so i won't do that.

## Build:

### Prerequisites
* Windows (tested on windows 11)

* Visual Studio 2022 with c++ packages

* vcpkg (package manager for c++). Installation below:
* * `git clone https://github.com/microsoft/vcpkg.git` to some folder (should be global, not local to game) for example `C:\vcpkg`
* * run `bootstrap-vcpkg.bat` from this folder to initialize it
* * run `.\vcpkg.exe integrate install` from this folder to integrate it to visual studio

Open Fallen.sln and rebuild Fallen project. It should download vcpkg packages on first build to `./vcpkg_installed` folder.

Game build will be in `./Debug` folder from project root.

## Debug/Run:

Game resource files are needed to run the game.

Get the game from somewhere (you need windows version) and copy game files to `./Debug` folder. Copy all contents except top-level `.exe` and `.dll` files (these files would be overwritten by build).

I used steam version, files are here on my pc - `C:\Program Files (x86)\Steam\steamapps\common\Urban Chaos`

To run this from ide under debug mode you should add following to your `Fallen.vcxproj.user` file inside of Project tag:
```
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <LocalDebuggerWorkingDirectory>$(ProjectDir)\Debug</LocalDebuggerWorkingDirectory>
    <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
  </PropertyGroup>
```

