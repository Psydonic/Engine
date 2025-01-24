# Design

## UI
The UI module is made up of an abstract superclass called widget, which has a size and position, and is simply used to implement polymorphism. This is then subclassed by a number of widget implementations (e.g buttons, labels, etc). One of these is a layout widget, which aggregates a number of child widgets, and controls their positioning. Screen classes have one of these layouts that fills the screen, effectivly acting as the UI "layer" for the screen. Widgets should not control their own position, that is the responsibility of the layout (unless you really want to hardcode positions). Widgets should control their own size.

Certain operations cannot be performed without a GLWF context initialised, such as obtaining the size of the screen or getting the default font. Consequently, these operations must be performed either on a callback (e.g. "onResize") or as part of the update function. This allows UI layouts to be defined programatically prior to starting the game.

Below is an example of building a simple layout:


```
Layout parentLayout();                          // by default this expands to fill its parent
parentLayout.setDirection(Direction::Vertical)  // you can set Alignment, Expansion and Direction 
parentLayout.addWidget(Label("Hello World"))    // the layout sets the location on resize
parentLayout.setPadding(10)                     // The layout controlls the padding, not the child
```

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
