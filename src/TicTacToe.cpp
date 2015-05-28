#include "TicTacToe.hpp"

void TicTacToe::SetSize(int n){
  x.NewBoard(n);
  o.NewBoard(n);
  size = n;
}

void TicTacToe::MakeMove(){
  int a,b; 
  srand(time(NULL));
  do{
    a = rand()%size;
    b = rand()%size;
  }while(x.tab[a][b]);
  x.tab[a][b] = true;
}

Symbol** TicTacToe::Convert(){
  int i,j,size = x.size;
  Symbol ** tab = new Symbol *[size];
  for(i=0;i<size;++i){
    tab[i] = new Symbol[size];
    for(j=0;j<size;++j){
      if(x.tab[i][j])
	tab[i][j] = Symbol::Cross;
      else if(o.tab[i][j])
	tab[i][j] = Symbol::Circle;
      else
	tab[i][j] = Symbol::Empty;
    }
  }
  return tab;
}

void TicTacToe::Game(bool turn, int size){
  SetSize(size);
  turn_X = turn;
  if(turn_X)
    x.tab[0][0]=true;
  G.updateTable(Convert(),size);
}

void TicTacToe::update(const int a,const int b){
  if(o.tab[a][b] | x.tab[a][b])    //jeśli a,b już zajęte, 
    G.updateTable(Convert(),size); // ponownie wykonaj updateTable
  o.tab[a][b] = true;
  if(o.Check())    //sprawdź czy o nie wygrał aby
    G.showWinner(Symbol::Circle);
  MakeMove();
  if(x.Check())     //sprawdź czy aby nie wygrał krzyzyk
    G.showWinner(Symbol::Cross);
  G.updateTable(Convert(),size);
}
