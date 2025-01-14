#ifndef LABEL_H
#define LABEL_H

// A label is a simple text display widget.
// It can be used to display short, non-editable text strings.
// It can be drawn directly or handed to a layout controller.
// It can be styled with a font, color, and alignment.

#include "Widget.h"
#include "raylib.h"

class Label : public Widget {
public:
  Label(const char* text, int textSize, Font font);
  void draw() const override;
  void update() override;
  
  // Setters
  void setText(const char* text);
  void setTextSize(int fontSize);
  void setFont(Font font);

  // Getters
  const std::string getText() const;
  int getTextSize() const;
  Font getFont() const;

private:
  const std::string text;
  int textSize;
  Font font;
};

#endif // LABEL_H
