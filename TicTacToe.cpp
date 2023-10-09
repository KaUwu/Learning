#include <iostream>
char board[3][3];

void boardReset() {

    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            board[i][j] = '8';
        }
    }        

}
void boardShow() {
    std::cout << std::endl;
    std::cout << "   1 2 3" << std::endl;
    for(int i=0;i<3;i++) {
        std::cout << i+1 << "  ";
        for(int j=0;j<3;j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    } 
}
bool Winning() {

    //Vertical
           if(board[0][0] != '8' && board[0][1] != '8' && board[0][2] != '8' && board[0][0] == board[0][1] && board[0][2] == board[0][0] && board[0][2] == board[0][1]) {
        return true;
    } else if(board[1][0] != '8' && board[1][1] != '8' && board[1][2] != '8' && board[1][0] == board[1][1] && board[1][2] == board[1][0] && board[1][2] == board[1][1]) {
        return true;
    } else if(board[2][0] != '8' && board[2][1] != '8' && board[2][2] != '8' && board[2][0] == board[2][1] && board[2][2] == board[2][0] && board[2][2] == board[2][1]) {
        return true;
    }
    //Horizontal
      else if(board[0][0] != '8' && board[1][0] != '8' && board[2][0] != '8' && board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[1][0] == board[2][0]) {
        return true;
    } else if(board[0][1] != '8' && board[1][1] != '8' && board[2][1] != '8' && board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[1][1] == board[2][1]) {
        return true;
    } else if(board[0][2] != '8' && board[1][2] != '8' && board[2][2] != '8' && board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[1][2] == board[2][2]) {
       return true;
    } 
    //Diagonal
      else if(board[0][0] != '8' && board[1][1] != '8' && board[2][2] != '8' && board[0][0] == board[1][1] && board[2][2] == board[0][0] && board[1][1] == board[2][2]) {
        return true;
    } else if(board[2][0] != '8' && board[2][2] != '8' && board[0][2] != '8' && board[2][0] == board[2][2] && board[2][2] == board[0][2] && board[0][2] == board[2][0]) {
        return true;
    }  else {return false;}
}

int main() {

std::cout << "Welcome in TicTacToe!" << std::endl;
std::cout << "Player moves: xCordinate yCordinate" << std::endl;
std::cout << "Board: " << std::endl;
boardReset();
boardShow();
int xCord;
int yCord;

for(bool win=0;!win;) {
    std::cout << "X moves: ";
    std::cin >> xCord;
    std::cin >> yCord;
    board[yCord-1][xCord-1] = 'X';
    boardShow();
    bool winningEnd = Winning();
    if(winningEnd && win==0) { 
        win=1;
        std::cout << std::endl;
        std::cout << "Winner: X" << std::endl;
    }

    std::cout << std::endl;

    if(win==0) {
        std::cout << "O moves: ";
        std::cin >> xCord;
        std::cin >> yCord;
        board[yCord-1][xCord-1] = 'O';
        boardShow();

        if(winningEnd && win==0) { 
            win=1;
            std::cout << std::endl;
            std::cout << "Winner: O" << std::endl;
        }

    }

}

}