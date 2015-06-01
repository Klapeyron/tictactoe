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
  int counter;  // zlicza ktora to z kolei tura

  void updateMouseClick(const int a,const int b);
  Symbol** Convert();
  int minmax(Board a, Board b, bool tura, int size, int cnt);
public:
  GraphicalInterface G;
  void SetSize(int n=3);
  void MakeMove(int size, int cnt);
  void Game(bool turn=true);
  TicTacToe(const int siz=3) : G(siz) {
    SetSize(siz);
    counter = 0;
    //G.registerObserver(*this);  - to bedzie w mainie
  }
};



#endif
