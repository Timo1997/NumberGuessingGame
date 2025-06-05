#include <iostream>
#include "NumberGuesser.h"
#include <limits>
#include <ctime> 
#include <random>

NumberGuesser::NumberGuesser(int _maxAttempts, int _guessMin, int _guessMax) : attempts(0), isGameOver(false), maxAttempts(_maxAttempts), guessMin(_guessMin), guessMax(_guessMax){
    // Create a random device to seed the random engine to create a random number
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(guessMin, guessMax);
    numberToGuess = distrib(gen);

    // Initialize the number to guess guessMin  and guessMax
    numberToGuess = guessMin + rand() % (guessMax + 1); 
    std::cout << "Welcome to the Number Guesser game! Try to guess the number I'm thinking of between " << guessMin << " and " << guessMax << "." << std::endl;
    std::cout << "You can type 'surrender' to give up at any time." << std::endl;
    std::cout << "Guess a number (attempt 1): ";

}

void NumberGuesser::restartGame() {
    attempts = 0;
    isGameOver = false;
    numberToGuess = guessMin + rand() % (guessMax + 1); // Reset the number to guess
    std::cout << "The game has been restarted! Try to guess the new number between " << guessMin << " and " << guessMax << "." << std::endl;
    std::cout << "Guess a number (attempt 1): ";
}

void NumberGuesser::guessNumber() {
    
    int number = 0;
    std::cin >> number;
    //Check for valid input
    if (std::cin.fail() || number < guessMin || number > guessMax) {
        std::cin.clear(); // Fehlerzustand zurücksetzen
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Rest der Zeile verwerfen
        std::cout << "Invalid input. Please enter a valid number between " << guessMin << " and " << guessMax << "." << std::endl;
        std::cout << "\n";
        std::cout << "Guess a new number (attempt " << attempts + 1 << "): ";return;
    }



    attempts++;
    // Check if won
    if (number == numberToGuess) {
        std::cout << "Congratulations! You've guessed the number " << numberToGuess << " in " << attempts << " attempts." << std::endl;
        isGameOver = true;
        return;
    } 
    // Check if max attempts reached
    if (attempts >= maxAttempts) {
        isGameOver = true;
        std::cout << "You've used all your attempts! The number was " << numberToGuess << ". Better luck next time!" << std::endl;
        return;
    }

    //Check input number compared to the number to guess
   if (number < numberToGuess) {
        std::cout << "The number is higher than " << number << ". Try again!" << std::endl;
    } else if (number > numberToGuess) {
        std::cout << "The number is lower than " << number << ". Try again!" << std::endl;
    }

    std::cout << "\n";
    std::cout << "Guess a new number (attempt " << attempts + 1 << "): ";
}

bool NumberGuesser::surrender() {
    isGameOver = true;
    std::cout << "You surrendered! The number was " << numberToGuess << ". Better luck next time!" << std::endl;
    return isGameOver;
}

