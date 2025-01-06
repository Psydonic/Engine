#ifndef WIDGET_H
#define WIDGET_H

// A widget is a visual element that can be drawn on the screen.
// It can be a simple shape, a text label, an image, or a more complex control.
// It can be positioned, sized, and styled.

class Widget {
public: 
  Widget(int x, int y, int width, int height);
  virtual void draw() const = 0;
  void setPosition(int x, int y);
  void setSize(int width, int height);
  
  int getX() const;
  int getY() const;
  int getWidth() const;
  int getHeight() const;

protected:
  int x;
  int y;
  int width;
  int height;
};

#endif // WIDGET_H
