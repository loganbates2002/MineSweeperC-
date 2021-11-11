#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Player.h"
using namespace std;

class Board{
    public: 
    Board();
    Board(int newWidth, int newHeight);
    void draw();
    bool getMine(ifstream& fin,int x, int y);
    bool getFinish( int x, int y);

    private: 
    int width;
    int height;
};

Board::Board(){
  width = 0;
  height = 0;
}
//draws a board set to new dimensions
Board::Board(int newWidth, int newHeight){
  width = newWidth;
  height = newHeight;
}

// draws a board from a txt file
void Board::draw(){
  for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
            if((i==4)&& (j==4)){
              cout << "x";
            }else if((i==0)&& (j==0)){
              cout << "i";
            } else{
            cout << "o";
          }
      }
    cout << endl;
  }
}

// returns true if mine at x,y false if not
bool Board::getMine(ifstream& fin, int x, int y){
    string currRow;
    for(int i=0; i<=y;i++){
      if(!fin.fail()){
          getline(fin, currRow);
      }
      if(i==y){
          for(unsigned int j=0; j<currRow.length(); j++){
              if(currRow.at(x) == 'm'){
                return true;
              } 
              
          }
      }
     
      
    }


    return false;
}
// checks if player has landed on finishing tile.
bool Board::getFinish(int x, int y){
    if((x == 4)&&(y==4)){
      return true;
    }
    return false;
}

#endif