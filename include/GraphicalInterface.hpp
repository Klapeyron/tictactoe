#ifndef GRAPHICAL_INTERFACE_HPP_
#define GRAPHICAL_INTERFACE_HPP_

#include <vector>
#include <opencv/cv.hpp>
#include "MouseClickObserver.hpp"
#include "Symbol.hpp"

class MouseClickSubject {
  std::vector<MouseClickObserver*> obserwatorzy;
 public:
  void notify(const int x, const int y);
  void registerObserver(MouseClickObserver& obserwator);
};

using Image = cv::Mat;

class GraphicalInterface :public MouseClickSubject {
  Image windowImage;
 public:
  void updateTable(Symbol ** tablica, const int size);
  void showWinner(Symbol gracz);
  void clearWindow();
};

#endif /* GRAPHICAL_INTERFACE_HPP_ */
