#include "Game.h"
#include "Screens/Screen.h"
#include "UI/Label.h"

int main(void) {

  // Create the game object
  Screen startScreen = Screen();
  
  startScreen
    .getUILayout()
    .addWidget(
        std::make_unique<Label>("Hello")
        );
  
  const Game game = Game(800, 450, &startScreen);

  return 0;
}
