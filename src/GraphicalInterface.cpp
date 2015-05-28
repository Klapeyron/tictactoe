#include "GraphicalInterface.hpp"

#include <iostream>


void GraphicalInterface::MouseUsage(int event, int x, int y, int flags, void* userdata) {
  auto parametry = reinterpret_cast< GraphicalInterface* > (userdata);
  if  ( event == cv::EVENT_LBUTTONDOWN ) 
    parametry->ConvertMouseClick(x,y);
}

void GraphicalInterface::ConvertMouseClick(const int x,const int y) {
  std::cout << "Zarejestrowalem nacisniecie myszki ("<<x<<" "<<y<<")" << std::endl;

  // TODO: tutaj przetwarzam pozycje na indeksy tablicy
  MouseClickSubject::notify(x,y);
}

// TODO: Dopisac argument do windowImage()
GraphicalInterface::GraphicalInterface(const int size)
    :gameSize(size), windowHandler(DEFAULT_WINDOW_NAME), windowImage(1000,1000,1) {

  for(auto const& fileName : templateFileNames)
    templateSymbolImages.push_back( cv::imread(TEMPLATE_FILES_DIRECTORY+fileName,CV_LOAD_IMAGE_COLOR) );
}

void GraphicalInterface::clearWindow() {}

void GraphicalInterface::showWinner(Symbol) {}

void GraphicalInterface::updateTable(Symbol** tablica, const int size) {
  // TODO: Tymczasowa wartosc size do testow
  windowImage = templateSymbolImages[size];
  cv::namedWindow( windowHandler, CV_WINDOW_AUTOSIZE );
  cv::setMouseCallback(windowHandler, MouseUsage, this);
  cv::imshow( windowHandler, windowImage );
  cv::waitKey(0);
}
