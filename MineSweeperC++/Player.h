#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


class Player{
    public:
    Player();
    Player(string newName, int newScore);
    void setName(string newName);
    void setScore(int newScore);
    void setLives(int newLives);
    void setLives(int newLives, int num);
    string getName() const;
    int getScore()const;
    int getLives()const;
    void move(Player player);
    void moveUp(Player player);
    void moveLeft(Player player);
    void moveDown(Player player);
    void moveRight(Player player);
    void setPosition(int x, int y);
    int getWidth()const;
    int getHeight()const;
    void setHeight(int y);
    void setWidth(int x);
    int plusHighscore(vector<int>& highscore);
    int getHighScore()const;
    int pushBack(Player player,int width);
    void setNumMinesHit(int& num);
    int getNumMinesHit();

    private:
    string name;
    int lives;
    int score;
    int width;
    int height;
    int minesHit;
    vector<int> highscore;
};

Player::Player(){
    name = " ";
    lives = 0;
    score = 0;
    width = 0;
    height = 0;
    minesHit = 0;
}
//gets the player class ready for a player
Player::Player(string newName, int newScore){
    name = newName;
    score = newScore;
}

// sets player name
void Player::setName(string newName){
    name = newName;
}

// sets player score
void Player::setScore(int newScore){
    score = newScore;
}

// returns player name
string Player::getName()const{
  return name;
}

//returns player score
int Player::getScore()const{
  return score;
}

// prompts the user to input a desired direction and executes
void Player:: move(Player player){
  char direction;
  do{
    cout << " " << endl;
    cout <<"Where would you like to go?:" << endl;
    cout << "UP(w), LEFT(a), DOWN(s), RIGHT(d)" << endl;
    cin >> direction;
    cout << endl;
    direction = tolower(direction);

    if(direction == 'w'){
      player.moveUp(player);
      height = height-1;
    } else if(direction == 'a'){
      player.moveLeft(player);
      width = width -1;
    } else if(direction == 's'){
      player.moveDown(player);
      height = height+1;
    } else if(direction == 'd'){
      player.moveRight(player);
      width = width+1;
    } else {
      cout << "Try again" << endl;
    }
  }while (!(direction=='w')&&!(direction=='a')&&!(direction=='s')&&!(direction=='d'));

}
// moves the player up a tile
void Player::moveUp(Player player){
 
  if(player.getHeight()== 0){
     cout << "You cant move up try again." << endl;
    player.move(player);
    } else{
        height = height-1;
        for(int i=0; i<5; i++){
          for(int j=0; j<5; j++){
            if((i== (height))&& (j==width)){
              cout << "i";
            }else if(i==4 && j==4){
              cout << "x";
            }else{
            cout << "o";
            }
        }
        cout << endl;
    }
  }
}

// moves the player left a tile
void Player::moveLeft(Player player){
   
  if(player.getWidth()== 0){
     cout << "You cant move left try again." << endl;
     player.move(player);
    } else{
        width = width -1;
        for(int i=0; i<5; i++){
          for(int j=0; j<5; j++){
            if((i== (height))&& (j==width)){
              cout << "i";
            }else if(i==4 && j==4){
              cout << "x";
            }else{
            cout << "o";
          }
        }
        cout << endl;
      }
    }
}

// moves the player down a tile
void Player::moveDown(Player player){

  if(player.getHeight()== 4){
     cout << "You cant move down try again." << endl;
     player.move(player);
    } else{
        height = height+1;
        for(int i=0; i<5; i++){
          for(int j=0; j<5; j++){
            if((i== (height))&& (j==width)){
              cout << "i";
            }else if(i==4 && j==4){
              cout << "x";
            }else{
            cout << "o";
          }   
        }
        cout << endl;
    }
  }
}

// moves the player right a tile
void Player::moveRight(Player player){
  
  if(player.getWidth()== 4){
     cout << "You cant move right try again." << endl;
     player.move(player);
    } else{
       width = width +1;
        for(int i=0; i<5; i++){
          for(int j=0; j<5; j++){
            if((i== (height))&& (j==width)){
              cout << "i";
            }else if(i==4 && j==4){
              cout << "x";
            }else{
            cout << "o";
          } 
        }
        cout << endl;
    }
  }
}

// sets playersx potition
void Player::setPosition(int x, int y){
  width = x;
  height = y;

}

// returns players y position
void Player::setHeight(int y){
   height = y;
}

// returns players x position
void Player::setWidth(int x){
  width = x;
}

// returns players y position
int Player::getHeight()const{
  return height;
}

// returns players x position
int Player::getWidth()const{
  return width;
}
//sets lives back to 3 after each game
void Player::setLives(int newLives){
    lives = newLives;
}
//decreases a life 
void Player::setLives(int newLives, int num){
    lives = newLives - num;
}

// returns players lives
int Player::getLives()const{
  return lives;
}

int Player::plusHighscore(vector<int>& highscore){
  int add = 1;
  highscore.push_back(add);
  return highscore.size();
}
// returns players highscore
int Player::getHighScore()const{
  return score;
}

void setNumMinesHit(int& numMinesHit){
  numMinesHit++;
}

int getNumMinesHit(){
    return 0;
}



#endif  