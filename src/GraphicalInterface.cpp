#include "GraphicalInterface.hpp"

#include <iostream>

using namespace cv;
using namespace std;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
       cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
}

// TODO: Dopisac argument do windowImage()
GraphicalInterface::GraphicalInterface(const int size)
    :gameSize(size), windowHandler(DEFAULT_WINDOW_NAME), windowImage() {

  for(auto const& fileName : templateFileNames)
    templateSymbolImages.push_back( cv::imread(TEMPLATE_FILES_DIRECTORY+fileName,CV_LOAD_IMAGE_COLOR) );
}

void GraphicalInterface::clearWindow() {}

void GraphicalInterface::showWinner(Symbol) {}

void GraphicalInterface::updateTable(Symbol** tablica, const int size) {
  windowImage = templateSymbolImages[1];
  cv::namedWindow( windowHandler, CV_WINDOW_AUTOSIZE );
  cv::setMouseCallback(windowHandler, CallBackFunc, NULL);
  cv::imshow( windowHandler, windowImage );
  cv::waitKey(0); 
}
