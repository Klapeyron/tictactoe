#ifndef GRAPHICAL_INTERFACE_HPP_
#define GRAPHICAL_INTERFACE_HPP_

#include <vector>
#include <opencv/cv.hpp>
#include "MouseClickObserver.hpp"
#include "Symbol.hpp"

using Image = cv::Mat;
using ImageWindow = std::string;

const std::string TEMPLATE_FILES_DIRECTORY = "imageTemplates/";
const std::vector<std::string> templateFileNames {"empty.png", "x.png", "o.png"};

class GraphicalInterface :public MouseClickSubject {
  const std::vector<Image> templateImages;
  Image windowImage;
  ImageWindow windowHandler;
  int gameSize;
 public:
  // TODO: Dopisac argument do windowImage()
  GraphicalInterface(const int size = 0) :gameSize(size), windowHandler("TicTacToe"), windowImage() {}
  void updateTable(Symbol ** tablica, const int size);
  void showWinner(Symbol gracz);
  void clearWindow();
};

#endif /* GRAPHICAL_INTERFACE_HPP_ */
