#include <iostream>
#include <cstdlib>
#include "Connect4Game.h"
using namespace std;
void Connect4Game::initBoard(int size){
  this->SIZE = size;
  this->board = new int*[size];
  for(int i=0; i<size; i++){
    this->board[i] = new int[size];
    for(int j=0; j<size; j++)
      this->board[i][j] = 0;
  }
}
void Connect4Game::showBoard(){
  cout << '\t';
  for(int j=0; j<this->SIZE; j++)
      cout << j << ' ';
  cout << "\n\n";
  for(int i=0; i<this->SIZE; i++){
    cout << i << "  " << '\t';
    for(int j=0; j<this->SIZE; j++)
      cout << this->board[i][j] << ' ';
    cout << '\n';
  }
  cout << '\n';
}
void Connect4Game::insertValue(int pos){
  if(pos < 0 || pos > 6){
    cout << "Invalid Position. Try again.";
    return;
  }
  this->board[rowsLeft(pos)][pos] = getTurn();
}
void Connect4Game::start(){
  system("cls");
  cout << "\t\t\t************************************\n"
       << "\t\t\t*    Welcome to Connect-4-Game     *\n"
       << "\t\t\t************************************\n";
  showBoard();
  this->turn = PLAYER1;
}
int Connect4Game::getTurn(){
  return this->turn;
}
void Connect4Game::switchTurn(int player){
  if(player == PLAYER1) this->turn = PLAYER2;
  else this->turn = PLAYER1;
}
int Connect4Game::rowsLeft(int pos){
  int row;
  for(row=this->SIZE-1; row>0; row--)
    if(this->board[row][pos] == 0)
      break;
  return row;

}
bool Connect4Game::isWin(int player){
  int i, j, k;
  for(j=0;j<SIZE;j++)
    for(i=0;i<SIZE;i++)
      if(this->board[i][j] == player){
        int count = 0;
        //For rows
        for(k=0;k<4;k++)
          if((i+k) < SIZE && this->board[i+k][j] == player)
            count++;
        if(count == 4)  return true;

        //For columns
        count = 0;
        for(k=0;k<4;k++)
          if((j+k) < SIZE && this->board[i][j+k] == player)
            count++;
        if(count == 4)  return true;

        //For diagnals
        count = 0;
        for(k=0;k<4;k++)
          if((i+k) < SIZE && (j+k) < SIZE && this->board[i+k][j+k] == player)
            count++;
        if(count == 4)  return true;

        count = 0;
        for(k=0;k<4;k++)
          if((i-k) >= SIZE && (j+k) < SIZE && this->board[i-k][j+k] == player)
            count++;
        if(count == 4)  return true;
      }
  return false;
}
bool Connect4Game::isBoardFull(){
  for(int i=0; i<this->SIZE; i++)
    for(int j=0; j<this->SIZE; j++)
      if(this->board[i][j] == 0) return false;
  return true;
}
