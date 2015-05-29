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
  std::cout << "Współrzędne pola ("<< convertedX << " "<< convertedY << ")" << std::endl;
}

GraphicalInterface::GraphicalInterface(const int size) :GraphicalPreferencesHolder(size),
                                                        windowHandler(DEFAULT_WINDOW_NAME),
                                                        windowImage(DEFAULT_WINDOW_SIZE,DEFAULT_WINDOW_SIZE,0) {
  auto edge = GraphicalPreferencesHolder::singleTemplateSize();
  cv::Size newImageSize {edge, edge};
  
  for(auto const& fileName : templateFileNames) {
    auto loadedImage = cv::imread(TEMPLATE_FILES_DIRECTORY+fileName,
                                  CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
    cv::Mat newImage;
    cv::resize(loadedImage,newImage, newImageSize,0,0,cv::INTER_CUBIC);
    templateSymbolImages.push_back(newImage);
  }
  
  cv::namedWindow( windowHandler, CV_WINDOW_AUTOSIZE );
  cv::setMouseCallback(windowHandler, MouseUsage, this);
}

void GraphicalInterface::clearWindow() {}

void GraphicalInterface::showWinner(Symbol) {}

void GraphicalInterface::updateTable(Symbol** tablica, const int size) {
  cv::imshow( windowHandler, windowImage );
  cv::waitKey(0);
}
