#pragma once

namespace {
const int DEFAULT_WINDOW_SIZE = 1000;
}

class GraphicalPreferencesHolder {
  const int _gameSize;
  const int _singleTemplateSize;
 public:
  GraphicalPreferencesHolder(const int size) :_gameSize(size), _singleTemplateSize(DEFAULT_WINDOW_SIZE/size) {}
  int singleTemplateSize() const;
  int gameSize() const;
  int convertMousePossitionToTableField(const int value) const;
};
