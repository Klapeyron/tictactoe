#include "GraphicalInterface.hpp"

#include <iostream>

void GraphicalInterface::MouseUsage(int event, int x, int y, int flags, void* userdata) {
  auto myClass = reinterpret_cast< GraphicalInterface* > (userdata);
  if  ( event == cv::EVENT_LBUTTONDOWN ) 
    myClass->ConvertMouseClick(x,y);
}

void GraphicalInterface::ConvertMouseClick(const int x,const int y) {  
  auto convertedX = convertMousePossitionToTableField(x);
  auto convertedY = convertMousePossitionToTableField(y);
  MouseClickSubject::notify(convertedX,convertedY);
}

GraphicalInterface::GraphicalInterface(const int size) :GraphicalPreferencesHolder(size),
                                                        windowHandler(DEFAULT_WINDOW_NAME),
                                                        windowImage(DEFAULT_WINDOW_SIZE,DEFAULT_WINDOW_SIZE,CV_8U)
{
  auto edge = GraphicalPreferencesHolder::singleTemplateSize();
  cv::Size newImageSize {edge, edge};
  
  for(auto const& fileName : templateFileNames) {
    auto loadedImage = cv::imread(TEMPLATE_FILES_DIRECTORY+fileName,CV_8U);
    cv::Mat newImage;
    cv::resize(loadedImage,newImage, newImageSize,0,0,cv::INTER_CUBIC);
    templateSymbolImages.push_back(newImage);
  }

  for(auto const& fileName : templateWinnerFileNames) {
    auto newImage = cv::imread(TEMPLATE_FILES_DIRECTORY+fileName,CV_8U);  
    templateWinnerImages.push_back(newImage);
  }
  winnerImage = templateWinnerImages[0];
  
  cv::namedWindow( windowHandler, CV_WINDOW_AUTOSIZE );
  // TODO: przeniesc obsluge myszy do osobnej klasy;
  cv::setMouseCallback(windowHandler, MouseUsage, this);
}

void GraphicalInterface::clearWindow() {
  const auto size = GraphicalPreferencesHolder::gameSize();
  Symbol** tablica = new Symbol*[size];
  
  for(int i = 0; i < size; ++i)
    tablica[i] = new Symbol[size];
  
  for(int i =0; i<size; ++i)
    for(int j=0; j<size; ++j)
      tablica[i][j] = Symbol::Empty;
  updateTable(tablica,size);
  // TODO: dodac wyswietlanie siatki
}

void GraphicalInterface::showWinner(Symbol gracz) {
  cv::namedWindow( DEFAULT_WINNER_WINDOW_NAME, CV_WINDOW_AUTOSIZE );
  auto symbol = static_cast<int> (gracz);
  winnerImage = templateWinnerImages[symbol];
  cv::imshow( DEFAULT_WINNER_WINDOW_NAME,winnerImage);
  cv::waitKey(0);
  cv::destroyWindow(DEFAULT_WINNER_WINDOW_NAME);
  clearWindow();
}

cv::Rect GraphicalInterface::getROI(const int x, const int y) {
  auto newX = x*singleTemplateSize();
  auto newY = y*singleTemplateSize();
  cv::Rect roi( cv::Point(newX,newY), templateSymbolImages[0].size() );
  return roi;
}

void GraphicalInterface::updateTable(Symbol** tablica, const int size) { 
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
    {
      auto roi = getROI(i,j);
      auto symbol = static_cast<int> (tablica[i][j]);
      templateSymbolImages[symbol].copyTo(windowImage(roi)); 
    }
  cv::imshow( windowHandler, windowImage );
  cv::waitKey(0);
}


void GraphicalInterface::updateTableW(Symbol** tablica, const int size) { 
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
    {
      auto roi = getROI(i,j);
      auto symbol = static_cast<int> (tablica[i][j]);
      templateSymbolImages[symbol].copyTo(windowImage(roi)); 
    }
  cv::imshow( windowHandler, windowImage );
}

