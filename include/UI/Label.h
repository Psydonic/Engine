#pragma once

// A label is a simple text display widget.
// It can be used to display short, non-editable text strings.
// It can be drawn directly or handed to a layout controller.
// It can be styled with a font, color, and alignment.

#include "Widget.h"
#include "raylib.h"
#include <optional>
#include <string>

class Label : public Widget {
public:
  Label(const char *text, const Vector2 &pos = {0, 0},
               std::optional<Font> font = std::nullopt, int textSize = 50)
      : Widget(pos), text(text),
        textSize(textSize), font(font) {}

  void draw() const override;
  void update() override;

  // Setters
  void setText(const std::string text) { this->text = text; }
  void setTextSize(int fontSize) { this->textSize = fontSize; }
  void setFont(Font font) { this->font = font; }

  // Getters
  const std::string getText() const { return text; }
  int getTextSize() const { return textSize; }
  Font getFont() const { return font.value(); }

private:
  std::string text;
  int textSize;
  std::optional<Font> font;
};
