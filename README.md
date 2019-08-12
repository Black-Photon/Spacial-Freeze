# Spacial-Freeze
A game about a telekinetic person moving around objects to escape their frozen prison.

The player is stuck in a Cryo-Chamber in a room with no memory of anything. The chamber is locked by a combination, but you find you can manipulate the surroundings using your mind. Maybe you can find the code somewhere in this room and use it to get out of here.

This game is written in OpenGL, partially to improve skills in Computer Graphics and apply to a real project.

# Clone Instructions
## Windows
1) Clone with `git clone https://github.com/Black-Photon/Spacial-Freeze.git`
2) Install the latest assimp version at https://github.com/assimp/assimp/releases/tag/v4.1.0
3) Go to `INSTALL_LOCATION/Assimp/bin/x64` and copy `assimp-vc140-mt.dll` to the `cmake-build-debug` folder created by CLion
4) Change Toolchain type in File/Settings/Build, Execution, Deployment/Toolchains from `x86` to `amd64` in CLion
5) Run!

## Linux
1) Clone with `git clone https://github.com/Black-Photon/Spacial-Freeze.git`
2) Download the *source* zip at https://github.com/assimp/assimp/releases/tag/v4.1.0
3) Extract contents to `Spacial-Freeze/include/assimp-src`
4) Run!
