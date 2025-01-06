#include "Widgets/Label.h"
#include "raylib.h"

// Constructor
Label::Label(const char* text, int x, int y, int fontSize, Color color, Alignment alignment, Font font)
    : Widget(x, y, 0, 0), text(text), fontSize(fontSize), color(color), alignment(alignment), font(font) {
  // Measure the text size
  Vector2 size = MeasureTextEx(font, text, fontSize, 0);
  width = size.x;
  height = size.y;
}

void Label::draw() const {
  // Depending on the aligment value, calculate the x position
  // to draw the text centered or right-aligned
  int drawX = x;
  if (alignment == ALIGN_CENTER) {
    drawX -= width / 2;
  } else if (alignment == ALIGN_RIGHT) {
    drawX -= width;
  }

  // Depending on the aligment value, calculate the y position
  // to draw the text centered or bottom-aligned
  int drawY = y;
  if (alignment == ALIGN_MIDDLE) {
    drawY -= height / 2;
  } else if (alignment == ALIGN_BOTTOM) {
    drawY -= height;
  }

  // Draw the text
  DrawTextEx(font, text, { (float)drawX, (float)drawY }, fontSize, 0, color);

}

// Setters
void Label::setText(const char* text) {
  this->text = text;
}

void Label::setFontSize(int fontSize) {
  this->fontSize = fontSize;
}

void Label::setColor(Color color) {
  this->color = color;
}

void Label::setAlignment(Alignment alignment) {
  this->alignment = alignment;
}

void Label::setFont(Font font) {
  this->font = font;
}



