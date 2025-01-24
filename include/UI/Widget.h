#pragma once

#include "raylib.h"

// A widget is a visual element that can be drawn on the screen.
// It can be a simple shape, a text label, an image, or a more complex control.
// It can be positioned, sized, and styled.

class Widget {
public:
  Widget(const Vector2 &pos, const Vector2 &s) : position(pos), size(s) {}

  virtual void draw() const = 0;
  virtual void update() = 0;

  void setPosition(const Vector2 &pos) { position = pos; }
  void setPosition(int x, int y) { position = {(float)x, (float)y}; }
  void setSize(const Vector2 &s) { size = s; }

  const Vector2 &getPosition() const { return position; }
  const Vector2 &getSize() const { return size; }

  float getWidth() const { return size.x; }
  float getHeight() const { return size.y; }

protected:
  Vector2 position;
  Vector2 size;
};
