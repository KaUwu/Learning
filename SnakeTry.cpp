#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
using std::cout, std::endl, std::cin;


bool exitGame = false;
bool movingLe, movingFel, movingBalra, movingJobbra;

char keyPressed;
char board[10][10];
int score, ySnakePos, xSnakePos;

void Setup() {
    for(int i=0;i<10;i++) { // resetting the board to all ' ' characters
            for(int j=0;j<10;j++) {
                board[i][j] = ' ';
            }
        }
    //setting outline why
    board[0][0] = '#';
    board[0][1] = '#';
    board[0][2] = '#';
    board[0][3] = '#';
    board[0][4] = '#';
    board[0][5] = '#';
    board[0][6] = '#';
    board[0][7] = '#';
    board[0][8] = '#';
    board[0][9] = '#';
    board[1][0] = '#';
    board[2][0] = '#';
    board[3][0] = '#';
    board[4][0] = '#';
    board[5][0] = '#';
    board[6][0] = '#';
    board[7][0] = '#';
    board[8][0] = '#';
    board[9][0] = '#';
    board[1][9] = '#';
    board[2][9] = '#';
    board[3][9] = '#';
    board[4][9] = '#';
    board[5][9] = '#';
    board[6][9] = '#';
    board[7][9] = '#';
    board[8][9] = '#';
    board[9][9] = '#';
    board[9][1] = '#';
    board[9][2] = '#';
    board[9][3] = '#';
    board[9][4] = '#';
    board[9][5] = '#';
    board[9][6] = '#';
    board[9][7] = '#';
    board[9][8] = '#';

    //disabling all movments
    movingBalra = false;
    movingFel = false;
    movingJobbra = false;
    movingLe = false;

    //setting the score to zero and resetting snake position
    score=0;
    ySnakePos = 5;
    xSnakePos = 5;
}
void Render() {

    system("cls"); //Clear the screen

    cout << "Score: " << score << endl; //Display the score

    //display game
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    

}
void Logic() {
//capturing keypresses
if(_kbhit()) {
    keyPressed = _getch();
    if(keyPressed == 'w') {
        movingFel = true; 
        movingJobbra = false; 
        movingLe = false;   
        movingBalra = false;
    } else if(keyPressed == 'a') {
        movingBalra = true;
        movingFel = false;
        movingJobbra = false; 
        movingLe = false;
    } else if(keyPressed == 's') {
        movingLe = true;
        movingJobbra = false; 
        movingFel = false;
        movingBalra = false;
    } else if(keyPressed == 'd') {
        movingJobbra = true;
        movingFel = false;
        movingLe = false;
        movingBalra = false;
}
}

//debug?
cout << keyPressed << movingFel;

//actually moving the lil blob
if(movingLe) {
            board[ySnakePos][xSnakePos] = ' ';
        if(ySnakePos == 8) 
            { board[ySnakePos][xSnakePos] = ' ';
              ySnakePos = 1; 
            } 
        else {ySnakePos++;}
            board[ySnakePos][xSnakePos] = '0';
}
if(movingFel) {
            board[ySnakePos][xSnakePos] = ' ';
        if(ySnakePos == 1) 
            { board[ySnakePos][xSnakePos] = ' ';
              ySnakePos = 8; 
            } 
        else {ySnakePos--;}
            board[ySnakePos][xSnakePos] = '0';
}
if(movingBalra) {
            board[ySnakePos][xSnakePos] = ' ';
        if(xSnakePos == 1) 
            { board[ySnakePos][xSnakePos] = ' ';
              xSnakePos = 8; 
            } 
        else {xSnakePos--;}
            board[ySnakePos][xSnakePos] = '0';
}
if(movingJobbra) {
            board[ySnakePos][xSnakePos] = ' ';
        if(xSnakePos == 8) 
            { board[ySnakePos][xSnakePos] = ' ';
              xSnakePos = 1; 
            }
        else {xSnakePos++;}
           board[ySnakePos][xSnakePos] = '0';
}



}

int main() {
    Setup();
    while(!exitGame) {
        Render();
        Logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); //set game pace
    }
    return 0;
}