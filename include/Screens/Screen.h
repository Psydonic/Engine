#ifndef SCREEN_H
#define SCREEN_H

#include "../UI/Widgets/Layout.h"

// This is a base class for all screens in the game
// It is not abstract so that it can be used as a placeholder
class Screen {
public:
  Screen();

  void update();
  void draw();

protected:
  Layout parentLayout;
};

#endif
