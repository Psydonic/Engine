#include "Screens/Screen.h"

// This is a base class for all screens in the game

Screen::Screen() : parentLayout() 
{
  
}

void Screen::update() {
  parentLayout.update();
}

void Screen::draw() {
  parentLayout.draw();
}
