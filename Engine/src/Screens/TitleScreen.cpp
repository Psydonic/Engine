#include "Screens/TitleScreen.h"
#include "raylib.h"

// Constructor
// add the title and instructions labels to the title screen
TitleScreen::TitleScreen(const char *titleName)
    : title(titleName, GetScreenWidth()/2, GetScreenHeight()/2, 40, WHITE),
      instructions("Press ENTER to start", GetScreenWidth()/2, GetScreenHeight()/2, 20, WHITE) {}

void TitleScreen::update() const {
  if (IsKeyPressed(KEY_ENTER)) {
    // Change the current screen to the game screen
    // game.setCurrentScreen(&gameScreen);
  }
}

void TitleScreen::render() const {
  // Draw the title and instructions labels
  title.draw();
  instructions.draw();
}
