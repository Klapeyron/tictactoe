#pragma once
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
