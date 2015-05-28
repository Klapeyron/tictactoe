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
  void update(const int a,const int b);
  Symbol** Convert();
public:
  void SetSize(int n=3);
  void MakeMove();
  void Game(bool turn=true, int size=3);
  TicTacToe(const int siz=3) : G(siz) {
    turn_X = true;
    size = siz;
    //G.registerObserver(*this);  - to bedzie w mainie
  }
};



#endif
