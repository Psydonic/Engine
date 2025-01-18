#include "Screen.h"
#include "../UI/Widgets/Label.h"

class TitleScreen : public Screen 
{
public:
  TitleScreen(const char* titleName);
  void update() const override;
  void render() const override;
private:
  Label title;
  Label instructions;
};
