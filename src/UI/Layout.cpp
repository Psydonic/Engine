#include "UI/Layout.h"
#include <algorithm>

// Constuctor - initializes the layout with default values and call the widget
// superclass constructor
Layout::Layout()
    : m_padding(0), m_direction(Direction::Horizontal), m_expand(Expand::None),
      m_alignment({Alignment::Start, Alignment::Start}),
      Widget({0, 0}, {0, 0}) {}

Layout::Layout(const Vector2 &pos, const Vector2 &s)
    : m_padding(0), m_direction(Direction::Horizontal), m_expand(Expand::None),
      m_alignment({Alignment::Start, Alignment::Start}), Widget(pos, s) {}

Layout::~Layout() { clearWidgets(); }

void Layout::addWidget(Widget *widget) {
  m_widgets.push_back(widget);
}

void Layout::removeWidget(Widget *widget) {
  auto it = std::find(m_widgets.begin(), m_widgets.end(), widget);
  if (it != m_widgets.end()) {
    m_widgets.erase(it);
  }
}

void Layout::draw() const {
  for (auto widget : m_widgets) {
    widget->draw();
  }
}

void Layout::update() {
  for (auto widget : m_widgets) {
    widget->update();
  }
  layoutWidgets() // TODO execute on resize instead of update
}

// based on the aligment and direction properties, this method lays out the
// widgets inside the layout e.g. if the alignment is set to {Alignment::Center,
// Alignment::Center} and the direction is set to Direction::Horizontal the
// widgets will be centered horizontally and vertically inside the layout
// (second widget to the right of the first one) padding is taken into account
void Layout::layoutWidgets() {
  Vector2 pos = position;
  Vector2 maxSize = {0, 0};

  for (auto widget : m_widgets) {
    maxSize.x = std::max(maxSize.x, widget->getWidth());
    maxSize.y = std::max(maxSize.y, widget->getHeight());
  }

  for (auto widget : m_widgets) {
    Vector2 widgetSize = widget->getSize();
    Vector2 offset = {0, 0};

    if (m_direction == Direction::Horizontal) {
      if (m_alignment.x == Alignment::Center) {
        offset.x = (maxSize.x - widgetSize.x) / 2;
      } else if (m_alignment.x == Alignment::End) {
        offset.x = maxSize.x - widgetSize.x;
      }
    } else if (m_direction == Direction::Vertical) {
      if (m_alignment.y == Alignment::Center) {
        offset.y = (maxSize.y - widgetSize.y) / 2;
      } else if (m_alignment.y == Alignment::End) {
        offset.y = maxSize.y - widgetSize.y;
      }
    }

    Vector2 newPosition = {pos.x + offset.x, pos.y + offset.y};
    widget->setPosition(newPosition);
    pos.x += widget->getWidth() + m_padding;
  }

  if (m_expand == Expand::Maximum) {
    size = maxSize;
  } else if (m_expand == Expand::Minimum) {
    size = {0, 0};
  }
}
