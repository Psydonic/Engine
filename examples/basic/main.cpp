#include "Game.h"
#include "Screens/Screen.h"

int main(void) {

  // Create the game object  
  const Screen startScreen = Screen();
  const Game game = Game(800, 450, &startScreen);

  // Initialize the Game
  game.initialize();
  
  return 0;
}
