#pragma once

#include "Widget.h"
#include <memory>
#include <vector>

// Alignment enum
enum class Alignment { Start, Center, End };

struct Alignment2 {
  Alignment x;
  Alignment y;
};

// Direction enum
enum class Direction { Horizontal, Vertical };

const int DEFAULT_PADDING = 10;
const Alignment2 DEFAULT_ALIGNMENT2 = {Alignment::Center, Alignment::Center};
const Direction DEFAULT_DIRECTION = Direction::Horizontal;

// The layout class is a container for widgets. It is a widget itself, so it can
// be nested in other layouts. It has an alignmenty property that determines how
// the widgets are aligned inside the layout. It has a padding property that
// determines the space between the widgets and the layout's border. It has a
// direction property that determines the order in which the widgets are laid
// out. It has a expand property that determines if the layout should expand to
// fill the available space.

class Layout : public Widget {
public:
  Layout(Vector2 position = {0,0}, Vector2 size = {0,0})
      : Widget(position, size), m_alignment(DEFAULT_ALIGNMENT2),
        m_padding(DEFAULT_PADDING), m_direction(DEFAULT_DIRECTION) {}
  ~Layout() { clearWidgets(); }

  // Widget managmenet
  void addWidget(std::unique_ptr<Widget> widget) { m_widgets.push_back(std::move(widget)); }
  void removeWidget(Widget *widget);
  void clearWidgets() { m_widgets.clear(); }
  
  // Alignment
  void setAlignment(Alignment2 alignment) { this->m_alignment = alignment; }
  Alignment2 getAlignment() const { return m_alignment; }
  
  // Padding
  void setPadding(int padding) { m_padding = padding; }
  int getPadding() const { return m_padding; }

  // Direction
  void setDirection(Direction direction) { m_direction = direction; }
  Direction getDirection() const { return m_direction; }
  
  void draw() const override;
  void update() override;

protected:
  void layoutWidgets();

  std::vector<std::unique_ptr<Widget>> m_widgets;
  Alignment2 m_alignment;
  int m_padding;
  Direction m_direction;
};
