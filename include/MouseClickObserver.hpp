#ifndef MOUSE_CLICK_OBSERVER_HPP_
#define MOUSE_CLICK_OBSERVER_HPP_

#include <vector>

class MouseClickObserver {
 public:
  virtual void updateMouseClick(const int x,const int y) = 0;
};

class MouseClickSubject {
  std::vector<MouseClickObserver*> obserwatorzy;
 public:
  void notify(const int x, const int y);
  void registerObserver(MouseClickObserver& obserwator);
};

#endif /* MOUSE_CLICK_OBSERVER_HPP_ */
