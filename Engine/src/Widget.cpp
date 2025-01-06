#include "Widget.h"

Widget::Widget(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

void Widget::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

void Widget::setSize(int width, int height) {
  this->width = width;
  this->height = height;
}

int Widget::getX() const {
  return x;
}

int Widget::getY() const {
  return y;
}

int Widget::getWidth() const {
  return width;
}

int Widget::getHeight() const {
  return height;
}
