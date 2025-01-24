#pragma once

#endif // INCLUDE/home/psydonic/code/Engine/include/ScreensTitleScreenTitleScreen.h_
#include "../UI/Widgets/Label.h"
#include "Screen.h"

class TitleScreen : public Screen {
public:
  TitleScreen(const char *titleName);
  void update() const override;
  void render() const override;

private:
  Label title;
  Label instructions;
};
