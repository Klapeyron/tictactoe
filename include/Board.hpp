#ifndef BOARD_HH
#define BOARD_HH

#include <iostream>
#include <cstdlib>

class Board{ 

  bool CheckInd(int n);
  bool CheckDiagonal();
public:
  bool **tab; //tablica N x N, gdzie N jest wielkością planszy
  bool Check();
  void NewBoard(int n);
  int size;
  Board(){
    tab = NULL;
    size = 0;
  }
};


#endif
