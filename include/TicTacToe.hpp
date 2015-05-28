#ifndef TICTACTOE_HH
#define TICTACTOE_HH

#include "Board.hpp"
#include "MouseClickObserver.hpp"
#include "GraphicalInterface.hpp"
#include "Symbol.hpp"
#include <cstdlib>  
#include <ctime> 


class TicTacToe :public MouseClickObserver{
  Board x,o;
  int size;
  bool turn_X;  //true - tura gracza x, false - tura gracza o
  GraphicalInterface G;
  void update(const int x,const int y);
  Symbol** Convert();
public:
  void SetSize(int n=3);
  void MakeMove();
  void Game(bool turn=true, int size=3);
  //int CheckWin();
  TicTacToe(){
    turn_X = true;
    size = 0;
  }
};



#endif
