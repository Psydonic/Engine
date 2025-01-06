#include "Game.h"
#include "Screens/TitleScreen.h"

int main(void) {

  // Create the game object  
  const TitleScreen titleScreen = TitleScreen("My Game");
  const Game game = Game(800, 450, &titleScreen);

  // Initialize the Game
  game.initialize();
  
  return 0;
}
