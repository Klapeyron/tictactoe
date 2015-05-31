#include "GraphicalPreferencesHoler.hpp"

int GraphicalPreferencesHolder::singleTemplateSize() const {
  return _singleTemplateSize;
}

int GraphicalPreferencesHolder::gameSize() const {
  return _gameSize;
}

int GraphicalPreferencesHolder::convertMousePossitionToTableField(const int value) const {
  return value/singleTemplateSize();
}

