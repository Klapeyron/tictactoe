#include "GraphicalPreferencesHoler.hpp"

int GraphicalPreferencesHolder::singleTemplateSize() const {
  return _singleTemplateSize;
}

int GraphicalPreferencesHolder::convertMousePossitionToTableField(const int value) const {
  return value/singleTemplateSize();
}
