#pragma once

#include "raylib.h"

// Expand enum
enum class Expand { Minimum, Maximum, None };

const Expand DEFAULT_EXPANSION = Expand::Maximum;

// A widget is a visual element that can be drawn on the screen.
// It can be a simple shape, a text label, an image, or a more complex control.
// It can be positioned, sized, and styled.
// The expand variable is used by a parent layout to control the size

class Widget {
public:
  Widget(const Vector2 &pos, const Vector2 &s) : m_position(pos), m_size(s), m_expand(DEFAULT_EXPANSION) {}

  virtual void draw() const = 0;
  virtual void update() = 0;

  void setPosition(const Vector2 &pos) { m_position = pos; }
  void setPosition(int x, int y) { m_position = {(float)x, (float)y}; }
  void setSize(const Vector2 &s) { m_size = s; }

  const Vector2 &getPosition() const { return m_position; }
  const Vector2 &getSize() const { return m_size; }

  float getWidth() const { return m_size.x; }
  float getHeight() const { return m_size.y; }

  void setExpand(const Expand expand) { m_expand = expand; }
  Expand getExpand() const { return m_expand; }

protected:
  Vector2 m_position;
  Vector2 m_size;
  Expand m_expand;
};
