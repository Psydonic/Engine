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

  if (m_widgets.empty()) return;

  // Calculate the total size of all widgets
  float totalWidth = 0, totalHeight = 0;
  for (const auto& widget : m_widgets) {
    totalWidth += widget->getWidth();
    totalHeight += widget->getHeight();
  }

  // Calculate the available space
  float availableWidth = getWidth();
  float availableHeight = getHeight();

  // Calculate the padding
  float horizontalPadding = getPadding();
  float verticalPadding = getPadding();

  // Adjust available space for padding
  availableWidth -= horizontalPadding;
  availableHeight -= verticalPadding;

  // Calculate the space between widgets
  float spaceBetweenWidgets = 0;
  if (m_direction == Direction::Horizontal && m_widgets.size() > 1) {
    spaceBetweenWidgets = (availableWidth - totalWidth) / (m_widgets.size() - 1);
  } else if (m_direction == Direction::Vertical && m_widgets.size() > 1) {
    spaceBetweenWidgets = (availableHeight - totalHeight) / (m_widgets.size() - 1);
  }

  // Calculate the starting position
  float startX = 0, startY = 0;
  if (m_alignment.x == Alignment::Center) {
    startX = (availableWidth - totalWidth - spaceBetweenWidgets * (m_widgets.size() - 1)) / 2;
  } else if (m_alignment.x == Alignment::End) {
    startX = availableWidth - totalWidth - spaceBetweenWidgets * (m_widgets.size() - 1);
  }
  if (m_alignment.y == Alignment::Center) {
    startY = (availableHeight - totalHeight - spaceBetweenWidgets * (m_widgets.size() - 1)) / 2;
  } else if (m_alignment.y == Alignment::End) {
    startY = availableHeight - totalHeight - spaceBetweenWidgets * (m_widgets.size() - 1);
  }

  // Position and size each widget
  float currentX = startX, currentY = startY;
  for (auto& widget : m_widgets) {
    if (m_direction == Direction::Horizontal) {
      widget->setPosition({currentX, startY});
      currentX += widget->getWidth() + spaceBetweenWidgets;
    } else if (m_direction == Direction::Vertical) {
      widget->setPosition({startX, currentY});
      currentY += widget->getHeight() + spaceBetweenWidgets;
    }
    widget->update();
  }
}
