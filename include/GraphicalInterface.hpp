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

enum class Symbol : unsigned int {Empty, Circle, Cross};

class GraphicalInterface :public MouseClickSubject {

 public:
  void updateTable(Symbol ** tablica, const int size);
};

#endif
