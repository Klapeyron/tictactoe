#include "GraphicalInterface.hpp"
#include "TicTacToe.hpp"

#include <iostream>
#include <cstdlib>


int main(int argc, char *argv[])
{
  int x=3;
  if(argc > 1){
    x=atoi(argv[1]);
    if(x <= 0){
      std::cerr<<"Błąd! Rozmiar planszy musi być liczbą naturalną!\n";
      exit(1);
    }
  }
  TicTacToe Gra(x);
  Gra.G.registerObserver(Gra);
  Gra.Game();
}
