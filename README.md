# Codestyling

- use pragma once instead of include guards
- useheader files instead of forward declarations
- if a function can be implemented in one line then do it in the .h file
- curly brackets on the same line

# Requirements

## Tools
git, make, cmake, and gcc (or alternative CPP compiler)

## Libraries 
libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

# Build

## First time
```
mkdir build
cd ./build
cmake ..
make
```

## Subsequent builds
```
cmake --build ./build
```

# Run (example)

```
./build/basic
```
