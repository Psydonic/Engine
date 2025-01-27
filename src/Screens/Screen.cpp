#include "Screens/Screen.h"

// This is a base class for all screens in the game

Screen::Screen() : parentLayout() {}

void Screen::update() {
  // Set the parentLayout's size and position
  parentLayout.setSize({static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())});

  parentLayout.update();
}

void Screen::draw() { parentLayout.draw(); }
