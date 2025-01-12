#ifndef SCREEN_H
#define SCREEN_H

// This is a base class for all screens in the game
// It is not abstract so that it can be used as a placeholder
class Screen {
  public:
    void update() const {};
    void render() const {};
};

#endif
