#include <iostream>
#include <vector>
#include <algorithm>

#include "NumberGuesser.h"

int main() {
    NumberGuesser game = NumberGuesser();

    while (game.getIsGameOver() == false) {
        game.guessNumber();

        if (game.getIsGameOver()) { 
            std::cout << "Do you want to continue playing? (yes/no): ";
            std::string response;
            std::cin >> response;
            if (response == "yes")
            {
                game.restartGame(); 
            }
            else if (response == "no")
            {
                std::cout << "Thank you for playing! Goodbye!" << std::endl;
                break;
            }
        }
        
    }
    return 0;
}
