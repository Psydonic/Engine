#pragma once

#include "Screens/Screen.h"

class Game {
public:
  // Constructor
  Game(int screenWidth, int screenHeight, Screen *startScreen);
  ~Game();

  // Getter for the current screen
  const Screen &getCurrentScreen() const;

  // Setter for the current screen
  void setCurrentScreen(Screen *newScreen);

private:
  Screen *m_currentScreen; // Pointer to the current screen


  // Function to update the game state
  void update();

  // Function to render the current screen
  void render() const;
};
