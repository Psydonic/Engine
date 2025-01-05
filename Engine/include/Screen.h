#ifndef SCREEN_H
#define SCREEN_H

class Screen {
  public:
    virtual void update() const = 0;
    virtual void render() const = 0;
};

#endif
