#pragma once

#include "Screen.h"

class LogoScreen : public Screen {
  public:
    void update() override;
    void render() override;
};
