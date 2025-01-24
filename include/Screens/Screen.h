#pragma once

#include "../UI/Layout.h"

// This is a base class for all screens in the game
// It is not abstract so that it can be used as a placeholder
class Screen {
public:
  Screen();

  void update();
  void draw();

  Layout getUILayout() { return parentLayout; }

protected:
  Layout parentLayout;
};
