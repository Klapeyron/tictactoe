#ifndef GRAPHICAL_INTERFACE_HPP_
#define GRAPHICAL_INTERFACE_HPP_

#include <vector>
#include <opencv/cv.hpp>
#include "MouseClickObserver.hpp"
#include "GraphicalPreferencesHoler.hpp"
#include "Symbol.hpp"

using Image = cv::Mat;
using WindowName = std::string;

const std::string DEFAULT_WINDOW_NAME = "TicTacToe";
const std::string DEFAULT_WINNER_WINDOW_NAME = "Winner";

const std::string TEMPLATE_FILES_DIRECTORY = "imageTemplates/";
const std::vector<std::string> templateFileNames {"empty.png", "o.png", "x.png"};
const std::vector<std::string> templateWinnerFileNames {"emptyWin.png", "circleWin.png", "crossWin.png"};

class GraphicalInterface :public MouseClickSubject, GraphicalPreferencesHolder {
  
  std::vector<Image> templateSymbolImages;
  std::vector<Image> templateWinnerImages;
  Image windowImage;
  Image winnerImage;
  WindowName windowHandler;
  
  static void MouseUsage(int event, int x, int y, int flags, void* userdata);
  void ConvertMouseClick(const int x, const int y);
  cv::Rect getROI(const int x, const int y);
 public:
  GraphicalInterface(const int size = 3);
  void updateTable(Symbol ** tablica, const int size);
  void showWinner(Symbol gracz);
  void clearWindow();
};

#endif /* GRAPHICAL_INTERFACE_HPP_ */
