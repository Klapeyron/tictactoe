#include "GraphicalInterface.hpp"
#include "TicTacToe.hpp"

#include <iostream>



int main(int argc, char *argv[])
{
  TicTacToe Gra();
  Gra.G.registerObserver(Gra);
  Gra.Game();


}
