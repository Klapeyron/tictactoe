#ifndef GRAPHICAL_INTERFACE_HPP_
#define GRAPHICAL_INTERFACE_HPP_

#include <vector>
#include "MouseClickObserver.hpp"

class MouseClickSubject {
  std::vector<MouseClickObserver*> obserwatorzy;
 public:
  void notify(const int x, const int y);
  void registerObserver(MouseClickObserver& obserwator);
};

enum class Symbol : unsigned int {Circle, Cross, Empty};

class GraphicalInterface :public MouseClickSubject {

 public:
  // TODO: Ustalić argument funkcji
  void updateTable(Symbol ** tablica, const int size);
};

#endif
