/**
  CS-11 Lab 14.2: Sampler Project
  @file minesweeper.cpp
  @author Lgan Bates, Rodrigo Robinson
  @version 1.0  12/10/2020
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Player.h"
#include "Board.h"
using namespace std;

const int NUM_MINES = 3;

void start( Player player, Board board, vector<int>& life,  vector<int>& hs);

bool checkStatus(Player player,Board board,  vector<int>& life);

void writeHighScore(ofstream& fout,Player player, int score);   

void writeHighScore(ofstream& fout,Player player, int score, int numLives);

int subLife(vector<int>& life);

vector<int>& fibb(int score,int count,vector<int>& word);

int square(int number);


int main() {

  Board gameBoard;
  Player player1;
  Player player2;
  vector<Player> {player1, player2};
  vector<int> life {0,1,2,3};
  vector<int> hs;

  int userInput;
  string getName;
  do{
  const int TITLE_WIDTH = 30;
  cout << setw(TITLE_WIDTH) << "***********  Welcome to MineIsland! ***********" << endl;
  cout << "===============================================" << endl;
  cout << "............ INCOMING TRANSMISSION............." << endl;
  cout << ":::You've crash landed on an unknown planet covered with lava"<< endl << ":::Luckily, you have found youself on an island of mines" <<endl <<
   ":::Your only chance of escape is to traverse the mine-filled island" << endl <<
   ":::Acess your spaceship marked with an (x)" << endl <<
   ":::Be careful not to fall off the island or step on any mines" << endl << 
   ":::Good luck spaceman" << endl;
   cout << "................................................" << endl;

  cout << "Instructions: " << endl << "Only enter 1 character to move." << endl;
  cout << "You may not attempt to move past the bounds of the game board." << endl;
  cout << "===============================================" << endl;
  cout << endl;


  cout << "Select: " << endl;
  cout << "1. Start New Game" << endl;
  cout << "2. View Score" << endl;
  cout << "3. Quit Game" << endl;
  cout << " Choice (1-3): ";
  cin >> userInput;
  cout << endl;
   if(userInput == 1){
     player1.setLives(3);
     cout << "Enter a name:";
      cin >> ws;
      getline(cin,getName);
      player1.setName(getName);
      start(player1, gameBoard, life, hs);
      cout << endl;

      ofstream fout;
      
      fout.open("ViewScore.txt");
        
      if (!fout.is_open()) {
            cout << "Could not open file ViewScore.txt." << endl;
        }

        if(life.at(life.size()-1)==0){
          unsigned int scoreRN = 0;
          for(unsigned int i=0; i<=hs.size();i++){
              scoreRN = i;
          }
          writeHighScore(fout,player1, scoreRN);
        }else{
          writeHighScore(fout,player1, hs.size(),life.at(life.size()-1));
        }

        hs = {};
        life = {0,1,2,3};
        fout.close();
  } else if(userInput == 2){
    
        ifstream fin;

        fin.open("ViewScore.txt");
          
        if (!fin.is_open()) {
              cout << "Could not open file ViewScore.txt." << endl;
          }
          string score;
        while(fin.good()){
          getline(fin, score);
          cout << score << endl;
        }
  }
 }while (userInput !=3);
  cout << "Goodbye!" << endl;
}

// draws the board and loops through actions until the player dies or finishes
void start(Player player, Board board, vector<int>& life, vector<int>& hs){    
    board.draw(); 
  while(checkStatus(player, board, life)){
      player.move(player);     
      cout << "Score: " << player.plusHighscore(hs) << endl;
      player.setScore(hs.size());  
      cout << endl;
  } 
}

//checks if player steps on mine or finish tile
bool checkStatus(Player player, Board board, vector<int>& life){
    ifstream fin;
    fin.open("GameBoardMines.txt");   
    if (!fin.is_open()) {
        cout << "Could not open file GameBoardMines.txt." << endl;
    }

    if(board.getMine(fin , player.getWidth(), player.getHeight())){
      cout << "You hit a mine and lost a life!" << endl;
      cout << "You have " << subLife(life) << " lives left!" << endl;

        if(life.at(life.size()-1)==0){
          cout << "Better luck next time :)" << endl;
          fin.close();
          
          return false;
        }
        fin.close();
        return true;
      
    }else 
    // if player lands on winning tile, player wins
    if(board.getFinish(player.getWidth(), player.getHeight())){
      cout << "*** You survived!***" << endl;
      fin.close();
      return false;
    }

    fin.close();
    return true;
}
// writes high score if you lost
void writeHighScore(ofstream& fout,Player player, int score){
    fout << "Player: " << player.getName() << endl;
    fout << "Score: " << score << endl;
    fout << "Cause of End: " << "*You DIED* - Mines Hit: 3" << endl;
    fout << endl;
}
//writes high score if you won
void writeHighScore(ofstream& fout,Player player, int score, int numLives){
  vector<int> nums;
    fout << "Player: " << player.getName() << endl;
    fout << "Score: " << score << endl;
    fout << "Cause of End: " << "~You Won!~ - Mines Hit: " <<  
     setprecision(1) << static_cast<double>(NUM_MINES - numLives) << 
    endl;
    fout << "Because you won, here is the number of your (secret)score: ";
    fout << square(score);
    fout << endl;
}

int subLife(vector<int>& life){
    life.pop_back();
    return life.at(life.size()-1);
}

int square(int score){
  if(score <= 1){
    return 1;
  }
  score = score * square(score/2);

  return score;
  
}