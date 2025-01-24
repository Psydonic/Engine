#include "Game.h"
#include "raylib.h"

// Constructor with start screen
Game::Game(int screenWidth, int screenHeight, Screen *startScreen)
    : screenWidth(screenWidth), screenHeight(screenHeight),
      m_currentScreen(startScreen) {
  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - basic screen manager");
  SetTargetFPS(60);

  // main game loop
  while (!WindowShouldClose()) {
    update();
    render();
  }

  CloseWindow();
}

// Destructor
Game::~Game() {}

// Function to update the game state
void Game::update() { m_currentScreen->update(); }

// Function to render the current screen
void Game::render() const {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  m_currentScreen->draw();

  EndDrawing();
}

// Getter for the current screen
const Screen &Game::getCurrentScreen() const { return *m_currentScreen; }

// Setter for the current screen
void Game::setCurrentScreen(Screen *newScreen) { m_currentScreen = newScreen; }
