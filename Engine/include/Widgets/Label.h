#ifndef LABEL_H
#define LABEL_H

// alignment enum 
typedef enum {
  ALIGN_LEFT = 0,
  ALIGN_CENTER = 1,
  ALIGN_RIGHT = 2,
  ALIGN_TOP = 3,
  ALIGN_MIDDLE = 4,
  ALIGN_BOTTOM = 5
} Alignment;

// A label is a simple text display widget.
// It can be used to display short, non-editable text strings.
// It can be drawn directly or handed to a layout controller.
// It can be styled with a font, color, and alignment.

#include "../Widget.h"
#include "raylib.h"

class Label : public Widget {
public:
  Label(const char* text, int x, int y, int fontSize, Color color, Alignment alignment = ALIGN_LEFT, Font font = GetFontDefault());
  void draw() const override;
  
  // Setters
  void setText(const char* text);
  void setFontSize(int fontSize);
  void setColor(Color color);
  void setAlignment(Alignment alignment);
  void setFont(Font font);

  // Getters
  const char* getText() const;
  int getFontSize() const;
  Color getColor() const;
  Alignment getAlignment() const;
  Font getFont() const;

private:
  const char* text;
  int fontSize;
  Color color;
  Alignment alignment;
  Font font;
};

#endif // LABEL_H
