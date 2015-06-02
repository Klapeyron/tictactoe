#include "TicTacToe.hpp"

void TicTacToe::SetSize(int n){
  x.NewBoard(n);
  o.NewBoard(n);
  size = n;
}

int TicTacToe::minmax(Board a, Board b, bool turn, int size, int cnt){
  int m,mmx=0,s=size*size;
  int actions = s-counter;
  int depth = cnt-counter;
  if(actions > 9 && depth > 2){
    if(actions > 68)
      return 0;
    if(actions > 24 && depth > 3)
      return 0;
    if(actions > 15 && depth > 4)
      return 0;
    if(actions > 10 && depth > 5)
      return 0;
    if(depth > 6)
      return 0;
  }
  if(turn){
    if(a.Check()){
      return 1;
    }
  }
  else{
    if(b.Check())
      return -1;
  }
  if(cnt == s)
    return 0;
  turn = !turn;
  mmx = turn ? -10 : 10;
  for(int i=0;i<size;++i){
    for(int j=0;j<size;++j){
      if(a.tab[i][j] == false && b.tab[i][j] == false){
	turn ? a.tab[i][j] = true : b.tab[i][j] = true;
      	m = minmax(a,b,turn,size,cnt+1);
	turn ? a.tab[i][j] = false : b.tab[i][j] = false;
	if((!turn && (m<mmx)) || (turn && (m>mmx)))
	  mmx = m;
      }
    }
  }
  return mmx;
}

void TicTacToe::MakeMove(int size, int cnt){
  int k=0,i,j,m,mmx=-10;
  int *a = new int[size*size-cnt];
  int *b = new int[size*size-cnt];

  srand(time(NULL));

  for(i=0;i<size;++i){
    for(j=0;j<size;++j){
      if(x.tab[i][j] == false && o.tab[i][j] == false){
	x.tab[i][j] = true;
	m = minmax(x,o,true,size,cnt+1);
	x.tab[i][j] = false;
	if(m>=mmx){
	  if(m == mmx){
	    a[k] = i;
	    b[k] = j;
	    k++;
	  }
	  else{
	    mmx = m;
	    delete [] a;
	    delete [] b;
	    a = new int[size*size-cnt];
	    b = new int[size*size-cnt];
	    a[0] = i;
	    b[0] = j;
	    k = 1;
	  }
	}
      }
    }
  }
  m = rand()%k;
  x.tab[a[m]][b[m]] = true;
  delete [] a;
  delete [] b;
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

void TicTacToe::Game(bool turn){
  if(turn){
    x.tab[0][0]=true;
    counter++;
  }
  G.updateTable(Convert(),size);

}

void TicTacToe::updateMouseClick(const int a,const int b){
  if(o.tab[a][b] || x.tab[a][b])    //jeśli a,b już zajęte, 
    G.updateTable(Convert(),size); // ponownie wykonaj updateTable
  o.tab[a][b] = true;
  counter++;
  if(o.Check()){    //sprawdź czy o nie wygrał aby
    SetSize(size);
    counter = 0;
    G.showWinner(Symbol::Circle);
    return;
  }
  if(counter == size*size){  //sprawdz czy nie ma remisu
    SetSize(size);
    counter = 0;
    G.showWinner(Symbol::Empty);
    return;
  }
  MakeMove(size,counter);
  counter++;
  if(x.Check()){     //sprawdź czy aby nie wygrał krzyzyk
    SetSize(size);
    counter = 0;
    G.showWinner(Symbol::Cross);
    return;
  }
  if(counter == size*size){  //sprawdz czy nie ma remisu
    SetSize(size);
    counter = 0;
    G.showWinner(Symbol::Empty);
    return;
  }
  G.updateTable(Convert(),size);
}
