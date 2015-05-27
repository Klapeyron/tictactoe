#ifndef MOUSE_CLICK_OBSERVER_HPP_
#define MOUSE_CLICK_OBSERVER_HPP_

class MouseClickObserver {
 public:
  virtual void update(const int x,const int y) = 0;
};

#endif /* MOUSE_CLICK_OBSERVER_HPP_ */
