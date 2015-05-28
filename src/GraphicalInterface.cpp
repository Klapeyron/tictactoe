#include "GraphicalInterface.hpp"

void MouseClickSubject::notify(const int x, const int y) {
  for(auto const& obserwator : obserwatorzy)
    obserwator->update(x,y);
}

void MouseClickSubject::registerObserver(MouseClickObserver& obserwator) {
   obserwatorzy.push_back(&obserwator);
}

void GraphicalInterface::clearWindow() {}

void GraphicalInterface::showWinner(Symbol) {}

void GraphicalInterface::updateTable(Symbol** tablica, const int size) {}
