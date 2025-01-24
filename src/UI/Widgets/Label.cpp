#include "UI/Widgets/Label.h"
#include "raylib.h"

// Label constructor (sets size based on texts size)
Label::Label(const char *text, const Vector2 &pos, Font font, int textSize)
    : Widget(pos, MeasureTextEx(font, text, textSize, 1)), text(text),
      textSize(textSize), font(font) {}

void Label::draw() const {
  // center the text
  Vector2 centered_position = {
      (float)static_cast<int>(position.x - size.x / 2.0),
      (float)static_cast<int>(position.y - size.y / 2.0)};

  DrawTextEx(font, text.c_str(), centered_position, textSize, 0, WHITE);
}
