#include <iostream>


class NumberGuesser {
private:
    int attempts;
    int numberToGuess;
    bool isGameOver;
    int maxAttempts;
    int guessMin;
    int guessMax;

public:
    NumberGuesser(int _maxAttempts = 5, int _guessMin = 0, int _guessMax = 10);
    void restartGame();
    void guessNumber();
    bool surrender();

    int getAttempts() const {
        return attempts;
    }

    bool getIsGameOver() const {
        return isGameOver;
    }



};
