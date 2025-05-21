# Loravian System
This is a discord bot and automation system for [Loravia](https://www.roblox.com/communities/13214273/Loravia#!/about). At the time of writing this, it is planned to handle the following;
- Promotions
- Community shop
- Automatic blacklists

## Installation
To install this system and use it yourself, you'll need to compile it from source. The prerequisites for compiling are as follows;
- CMake
- A modern C++ compiler (GCC, Clang, MinGW, etc.)

### Clone the repository
```
git clone https://github.com/Loravis/loravian_system
```

After cloning, you'll need to create a file named **env.h** within the env directory. Compilation will fail if this file is not present. Instructions can be found [here](https://github.com/Loravis/loravian_system/blob/main/env/README.md). 

### Compile
```
mkdir build
cd build
cmake ..
make
```