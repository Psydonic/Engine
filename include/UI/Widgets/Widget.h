#ifndef WIDGET_H
#define WIDGET_H

#include "raylib.h"

// A widget is a visual element that can be drawn on the screen.
// It can be a simple shape, a text label, an image, or a more complex control.
// It can be positioned, sized, and styled.

class Widget {
public: 
  virtual void draw() const = 0;
  virtual void update() = 0;

  void setPosition(const Vector2& pos) { position = pos; }
  void setSize(const Vector2& s) { size = s; }

  const Vector2& getPosition() const { return position; }
  const Vector2& getSize() const { return size; }

protected:
  Vector2 position;
  Vector2 size;
};

#endif // WIDGET_H
