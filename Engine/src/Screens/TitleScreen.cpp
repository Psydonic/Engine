#include "Screens/TitleScreen.h"
#include "raylib.h"

void TitleScreen::update() const {
  if (IsKeyPressed(KEY_ENTER)) {
    // Change the current screen to the game screen
    // game.setCurrentScreen(&gameScreen);
  }
}

void TitleScreen::render() const {
  DrawText("Title Screen", 20, 20, 40, DARKGRAY);
  DrawText("Press Enter to start the game", 20, 80, 20, DARKGRAY);
}
