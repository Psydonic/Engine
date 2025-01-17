#ifndef LAYOUT
#define LAYOUT

#include "Widget.h"
#include <vector>
#include <algorithm>

class Layout : public Widget {
public:
  Layout(const Vector2& pos, const Vector2& s) : Widget(pos, s) {}

  void draw() const override {
    for (const auto& widget : widgets) {
      widget->draw();
    }
  }

  void update() override {
    for (const auto& widget : widgets) {
      widget->update();
    }
  }

  void addWidget(Widget* widget) {
    widgets.push_back(widget);
  }

  void removeWidget(Widget* widget) {
    widgets.erase(std::remove(widgets.begin(), widgets.end(), widget), widgets.end());
  }

private:
  std::vector<Widget*> widgets;
};
#endif // LAYOUT
