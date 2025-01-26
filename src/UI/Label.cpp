#include "UI/Label.h"
#include "raylib.h"

// Label update
void Label::update() {
  if (!font.has_value()) {
    font = GetFontDefault();
  }

  m_size = MeasureTextEx(font.value(), text.c_str(), textSize, 1);
}

void Label::draw() const {
  // center the text
  Vector2 centered_position = {
      (float)static_cast<int>(m_position.x - m_size.x / 2.0),
      (float)static_cast<int>(m_position.y - m_size.y / 2.0)};

  DrawTextEx(font.value(), text.c_str(), centered_position, textSize, 0, BLACK);
}
