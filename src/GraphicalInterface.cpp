#include "GraphicalInterface.hpp"

// TODO: Dopisac argument do windowImage()
GraphicalInterface::GraphicalInterface(const int size)
    :gameSize(size), windowHandler(DEFAULT_WINDOW_NAME), windowImage() {

  for(auto const& fileName : templateFileNames)
    templateSymbolImages.push_back( cv::imread(TEMPLATE_FILES_DIRECTORY+fileName,CV_LOAD_IMAGE_COLOR) );
}

void GraphicalInterface::clearWindow() {}

void GraphicalInterface::showWinner(Symbol) {}

void GraphicalInterface::updateTable(Symbol** tablica, const int size) {}
