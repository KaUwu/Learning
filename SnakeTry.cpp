#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
using std::cout, std::endl, std::cin;


bool exitGame = false;
bool yMove = true;
bool movingDown = true;

char board[10][10];
int score=0;
static int ySnakePos = 0;

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
}
void Render() {

    system("cls"); //Clear the screen

    cout << "Score: " << score << endl; //Display the score

        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    

}
void Logic() {
    if(movingDown) {
        if(ySnakePos != 0 && ySnakePos != 8) {
            board[ySnakePos][5] = ' ';
        }
        ySnakePos++;
        if(ySnakePos == 9) {
            movingDown = 0;
            score++;
        }
        if(ySnakePos != 9) {
            board[ySnakePos][5] = '0';
        }

    } else {
         if(ySnakePos != 9 && ySnakePos != 1) {
            board[ySnakePos][5] = ' ';
        }
        ySnakePos--;
        if(ySnakePos == 0) {
            movingDown = 1;
            score++;
        }
        if(ySnakePos != 0) {
            board[ySnakePos][5] = '0';
        }
    }
}

int main() {
    Setup();
    while(!exitGame) {
        Render();
        Logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    return 0;
}