Author: Logan Bates, Rodrigo Robinson
Email: loganbates2002@gmail.com
Asn#: Sampler
OS: Repl.it
Status: Completed
Files:
- main.cpp: the main class that plays the game
- Board.h: Draws and reads data regarding the game board
- Player.h: Moves, sets, and gets the functions of the player
- GameBoardMines.txt: A mapped out game board of the special tiles including mines and winning spaces
- ViewScore.txt Writes a file of the players name and score
Hours Working With Partner: 20
Hours Working Alone: 8
Hours Total: 28
Extra Credit:
-See below

Program Purpose:
This program plays a game like minesweeper. The objective of the game is to get to the "x" tile on the game board, hitting the fewest amount of mines in the fewest amount of moves.

Instruction: Only enter 1 character to move. You may not attempt to move past the bounds of the game board.

How to Use:
1. Install the source code into a directory and compile by typing: g++ -Wall -Wextra -Wpedantic -o main main.cpp
2. To run at the command line, type: ./main


Specifications Met:
##  Specification             File            Line#   Comment
--  -------------             ----            -----   -------
1.  No global variables
2.  Classes & objects         main.cpp        34
                              Board.h         13
				                      Player.h        13
3.  a. while loop             main.cpp        101
                              player.h        110
    b. for loop               Board.h         38,55
    c. if statement           main.cpp        60,120
4.  a. void function          main.cpp        19
    b. non-void function      main.cpp        21
    c. pass-by-value function player.h.       241
			                        main.cpp        153
    d. pass by reference func Board.h         53
                              player.h        255
5.  overloaded function defn  player.h        19,20
6.  overloaded constructors   Board.h         26,31
			                      	Player.h        50,59     
7.  vector type               main.cpp        24,25
					a vector of objects main.cpp        39
					b .at()             main.cpp        77
					c .size()           main.cpp        79
8.  a. Read from file         Board.h         85,57      filename: GameBoardMines.txt
    b. Write to file          main.cpp        149        filename: HighScore.txt
    c. Use of is_open()       Board.h         62      
    d. Stream parameter       Board.h         18,53      function: output()
9.  setw()                    main.cpp        45
10. setprecision()            main.cpp        163    
11. Project report            README.txt
12. Code compiles
13. Functions correctly
14. Meets documentation requirements
Extra credit:
#3. Recursive function call   main.cpp   179      shows recursion
