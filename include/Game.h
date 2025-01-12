#ifndef GAME_H
#define GAME_H

#include "Screens/Screen.h"

class Game {
public:
  
  // Constructor
  Game(int screenWidth, int screenHeight, const Screen *startScreen);
  ~Game();
  
  // Function to initialize the game
  void initialize() const;

  // Getter for the current screen
  const Screen &getCurrentScreen() const;

  // Setter for the current screen
  void setCurrentScreen(Screen *newScreen);

private:
  const Screen *m_currentScreen; // Pointer to the current screen
  const int screenWidth;
  const int screenHeight;
  
 // Function to update the game state
  void update() const;

  // Function to render the current screen
  void render() const;

};

#endif // GAME_H
