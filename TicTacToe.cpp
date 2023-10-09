#include <iostream>
char board[3][3]; //main board
char boardCheck[3][3]; //board for checking if there has been something placed
int xCord; //input taken for Vertical
int yCord; //input for horizontal

void inputX() { //input for X, used for oMove
    bool done = 0;
    while(!done) {
    if(!(std::cin >> xCord))         
    {
		std::cout << "Please enter numbers only: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n'); 
	} else {done = 1;}
    }
}
void inputY() { //input for O (accidentaly titled y), used for xMove
    bool done = 0;
    while(!done) {
     if(!(std::cin >> yCord))       
    {
		std::cout << "Please enter numbers only: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n'); 
	} else {done = 1;}
    } 
}
void oMove() { //taking input for O
        std::cout << "O moves: X Cordinate: ";
    inputX();
    std::cout << "         Y Cordinate: ";
    inputY();
}
void xMove() {    //taking input for X
    std::cout << "X moves: X Cordinate: ";
    inputX();
    std::cout << "         Y Cordinate: ";
    inputY();}
void Move() { //taking input used for invalid options to amke things clearer
    std::cout << "         X Cordinate: ";
    inputX();
    std::cout << "         Y Cordinate: ";
    inputY();
}
void boardReset() { //resetting the board

    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            board[i][j] = ' ';
        }
    }  

    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            boardCheck[i][j] = 'n';
        }
    }      

}
void boardShow() { //showing the current board
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
bool Winning() { //checking if there are any winners

    //Vertical
           if(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[0][0] == board[0][1] && board[0][2] == board[0][0] && board[0][2] == board[0][1]) {
        return true;
    } else if(board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[1][0] == board[1][1] && board[1][2] == board[1][0] && board[1][2] == board[1][1]) {
        return true;
    } else if(board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ' && board[2][0] == board[2][1] && board[2][2] == board[2][0] && board[2][2] == board[2][1]) {
        return true;
    }
    //Horizontal
      else if(board[0][0] != ' ' && board[1][0] != ' ' && board[2][0] != ' ' && board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[1][0] == board[2][0]) {
        return true;
    } else if(board[0][1] != ' ' && board[1][1] != ' ' && board[2][1] != ' ' && board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[1][1] == board[2][1]) {
        return true;
    } else if(board[0][2] != ' ' && board[1][2] != ' ' && board[2][2] != ' ' && board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[1][2] == board[2][2]) {
       return true;
    } 
    //Diagonal
      else if(board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ' && board[0][0] == board[1][1] && board[2][2] == board[0][0] && board[1][1] == board[2][2]) {
        return true;
    } else if(board[2][0] != ' ' && board[2][2] != ' ' && board[0][2] != ' ' && board[2][0] == board[2][2] && board[2][2] == board[0][2] && board[0][2] == board[2][0]) {
        return true;
    }  else {return false;}
}
bool Draw() { //cheking for draw
    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
bool game() { //The Game
boardReset();
boardShow();

//Main function
for(bool win=0;!win;) {
    //X moves
    xMove();
    if(boardCheck[yCord-1][xCord-1] == 'n') {
    board[yCord-1][xCord-1] = 'X';
    boardCheck[yCord-1][xCord-1] = 'y';
    } else  {
        bool invalid = 0;
        while(!invalid) {
        std::cout << "Invalid move. Try Again: " << std::endl;;
        Move();
        if(boardCheck[yCord-1][xCord-1] == 'n') {
             board[yCord-1][xCord-1] = 'X';
             boardCheck[yCord-1][xCord-1] = 'y';
             invalid=1;
        }
    }
    }
    
    boardShow();
    //Checking for winner x/draw
    bool winningEnd = Winning();
    if(winningEnd && win==0) { 
        win=1;
        std::cout << std::endl;
        std::cout << "Winner: X" << std::endl;
    }
    if(Draw() && win==0) {
        std::cout << "Draw" << std::endl;
        win = 1;
    }

    std::cout << std::endl;

    //O Moves
    if(win==0) {
        oMove();
        if(boardCheck[yCord-1][xCord-1] == 'n') {
    board[yCord-1][xCord-1] = 'O';
    boardCheck[yCord-1][xCord-1] = 'y';
    } else {
        bool invalid = 0;
        while(!invalid) {
        std::cout << "Invalid move. Try Again: " << std::endl;
        Move();
        if(boardCheck[yCord-1][xCord-1] == 'n') {
             board[yCord-1][xCord-1] = 'O';
             boardCheck[yCord-1][xCord-1] = 'y';
             invalid=1;
        }
    
        
    }
    }
        
        boardShow();
    //checking for winner O
        if(winningEnd && win==0) { 
            win=1;
            std::cout << std::endl;
            std::cout << "Winner: O" << std::endl;
        }

    }

    
}
//play again
std::string again;
    std::cout << "Play again? (y/n): ";
    std::cin >> again;
    if(again == "y") {
        return true;
    } else { return false; }
    std::cout << std::endl;
}

int main() {

std::cout << "Welcome in TicTacToe!" << std::endl;
std::cout << "Player moves: xCordinate yCordinate" << std::endl;
std::cout << "Board: " << std::endl;

bool end = 1; 
while(end == 1) {
    end = game();
}

return 0;
}

