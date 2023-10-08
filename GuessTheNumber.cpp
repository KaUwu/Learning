#include <iostream>

int a = 0;

bool guessing() {

    std::cout << std::endl;
    std::cout << "Your guess: ";

    int number = rand() % 10;

    int guess;
    std::cin >> guess;

    if(number == guess) {
        return true;
        std::cout << std::endl;
    } else {
        return false;
        std::cout << std::endl;
    }

}



int main() {
    std::cout << "Guess the number 0-10" << std::endl;
    std::cout << std::endl;

    for(int x;x!=(x+1);x++) {
    if(guessing()) {
        std::cout << "You guessed it!";
    } else {
        std::cout << "Wrong!" << std::endl;
    }
    }

}