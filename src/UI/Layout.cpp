#include "UI/Layout.h"
#include <algorithm>

// Constuctor - initializes the layout with default values and call the widget
void Layout::removeWidget(Widget *widget) {
  m_widgets.erase(std::remove_if(m_widgets.begin(), m_widgets.end(),
                                 [widget](const std::unique_ptr<Widget> &w) {
                                   return w.get() == widget;
                                 }),
                  m_widgets.end());
}

void Layout::draw() const {
  for (const auto& widget : m_widgets) {
    widget->draw();
  }
}

void Layout::update() {
  layoutWidgets(); 
}

// based on the aligment and direction properties, this method lays out the
// widgets inside the layout e.g. if the alignment is set to {Alignment::Center,
// Alignment::Center} and the direction is set to Direction::Horizontal the
// widgets will be centered horizontally and vertically inside the layout
// (second widget to the right of the first one) padding is taken into account
void Layout::layoutWidgets() {
  // The parent sets the size and position of the layout, based on it expansion property

  Vector2 pos = m_position; // cursor tracking insert loc

  for (const auto& widget : m_widgets) {
    // TODO set child widget size based on expansion and bias
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
    widget->update();
    pos.x += widget->getWidth() + m_padding;
  }
}
