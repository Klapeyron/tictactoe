#include "GraphicalInterface.hpp"
#include "TicTacToe.hpp"

#include <iostream>
#include <cstdlib>


int main(int argc, char *argv[])
{
  int x=3;
  if(argc > 1)
    x=atoi(argv[1]);
  TicTacToe Gra(x);
  Gra.G.registerObserver(Gra);
  Gra.Game();
}
