# Blitzcord
Blitz3D userlib to use the Discord Game SDK (RPC).

Requires the C++ files for the Discord Game SDK to be in a folder called "discord", and requires `discord_game_sdk.dll` and `discord_game_sdk.dll.lib` to be in the root of this repository.

Initially built using Visual Studio 2022, shouldn't be an issue to convert the .sln to the older Visual Studio 2019 platform toolset.

## Installation
Go to the `userlibs` directory of your Blitz3D install, and copy the `Blitzcord.decls` and `Blitzcord.dll` files there.

Go back, now into the `bin` directory of the install, and copy the `Blitzcord.dll` and `discord_game_sdk.dll` files there. **This is to allow Blitz3D to debug the program with the userlib, otherwise it will say the userlib could not be found.**

When you are building an executable, do the same as the `bin` directory procedure (copy `Blitzcord.dll` and `discord_game_sdk.dll`) but with the directory where the executable resides.

## License
Licensed under [CC-BY-SA 3.0](https://creativecommons.org/licenses/by-sa/3.0/)
