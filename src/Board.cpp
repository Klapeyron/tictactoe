#include "Board.hpp"

using namespace std;

void Board::NewBoard(int n){
  int i,j;
  for(i=0;i<size;++i)
    delete [] tab[i];
  delete [] tab;
  size = n;
  tab = new bool *[n];
  for(i=0;i<n;++i){
    tab[i] = new bool[n];
    for(j=0;j<n;++j)
      tab[i][j]=false;
  }
}

bool Board::CheckInd(int n){
  if(n >= size){
    cerr<<"CheckInd: nieprawidłowy indeks!\n";
    exit(1);
  }
  bool h=true,v=true;
  for(int i=0;i<size;++i){
    h &= tab[i][n];
    v &= tab[n][i];
  }
  return h | v;
}

bool Board::CheckDiagonal(){
  bool l=true,r=true;
  for(int i=0;i<size;++i){
    l &= tab[i][i];
    r &= tab[size-1-i][i];
  }
  return l | r;
}

bool Board::Check(){
  for(int i=0;i<size;++i){
    if(tab[i][i]){
      if(CheckInd(i))
	return true;
    }
  }
  return CheckDiagonal();
}

Board::Board(const Board & Ob){
  tab = NULL;
  size = 0;
  NewBoard(Ob.size);
  for(int i=0;i<Ob.size;++i)
    for(int j=0;j<Ob.size;++j)
      tab[i][j]=Ob.tab[i][j];
}

Board & Board::operator = (const Board & Ob){
  NewBoard(Ob.size);
  for(int i=0;i<Ob.size;++i)
    for(int j=0;j<Ob.size;++j)
      tab[i][j]=Ob.tab[i][j];
  return *this;
}

Board::~Board(){
  for(int i=0;i<size;++i)
    delete [] tab[i];
  delete [] tab;
}
