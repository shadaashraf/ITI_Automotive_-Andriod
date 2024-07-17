#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime> 

class BattleGame {
private:
    std::vector<std::vector<bool>> board;
    int guesses;
    int MaxGuesses;
    int LocationY;
    int LocationX;

public:
    BattleGame(int maxguesses) : board(5, std::vector<bool>(5, false)), guesses(0), MaxGuesses(maxguesses) {
        srand(time(0));
        int row = rand() % board.size();
        int col = rand() % board[0].size();
        board[row][col] = true;
        LocationX = row;
        LocationY = col;
    }

    void getTheTrue() {
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (board[r][c] == true) {
                    LocationX = r;
                    LocationY = c;
                    return;
                }
            }
        }
    }

    int ReturnGuesses() {
        return guesses;
    }

    bool GameOver() {
        return guesses == MaxGuesses;
    }

    bool guess(int x, int y) {
        guesses++;
        if (x == LocationX && y == LocationY) {
            std::cout << "You guessed correctly!" << std::endl;
            return true;
        }
        else if (x == LocationX - 1) {
            std::cout << "Close! Try again." << std::endl;
            return false;
        }
        else {
            std::cout << "Not even close. Try again." << std::endl;
            return false;
        }
    }
};

int main() {
    BattleGame BG(5);
    BG.getTheTrue(); 
    int guessX, guessY;
    
    std::cout << "Guess the coordinates of the battleship (0-4 for both X and Y): " << std::endl;
    std::cin >> guessX >> guessY;
    
    while (!BG.GameOver()) {
        if (BG.guess(guessX, guessY)) {
            break;
        }
        std::cout << "Try again!" << std::endl;
        std::cin >> guessX >> guessY;
    }

    return 0;
}

