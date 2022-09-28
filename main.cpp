#include <iostream>

bool checkWin(char board[], char plyChar) {
    //Check the lines
    for (int i = 0; i < 9; i++) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] == plyChar) {
            return true;
        }
    }

    //Check the columns
    for (int i = 0; i < 3; i += 3) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] == plyChar) {
            return true;
        }
    }

    //Check diagonals
    if (board[0] == board[4] && board[0] == board[8] && board[0] == plyChar) {
        return true;
    } else if (board[2] == board[4] && board[2] == board[6] && board[2] == plyChar) {
        return true;
    }

    //If nothing match
    return false;
}

void displayBoard(char board[]){
    for(int i = 0; i < 9; i+=3)
    {
        std::cout << "\t" << board[i] << "\t" << board[i+1] << "\t" << board[i+2] << std::endl;
    }
}

int convertInputToInt(char input)
{
    //Check if the input is a number between 1 and 8
    if (input >= 48 && input <= 56){
        return int(input - 48);
    }

    //Return -1 if not a number
    return -1;
}

int main() {
    //Variables
    char boardChar[9] = {'.','.','.','.','.','.','.','.','.'};
    char playerChar = 'O';
    bool notValidInput;

    //Main code
    do {
        //Change the actual player
        if(playerChar == 'X'){
            playerChar = 'O';
        } else{
            playerChar = 'X';
        }

        //Set not valid input to true
        notValidInput = true;

        do {
            //Ask the player to play
            if (playerChar == 'X') {
                std::cout << "C'est au joueur 1 de jouer : " << std::endl;
            } else {
                std::cout << "C'est au joueur 2 de jouer : " << std::endl;
            }

            //Display the board
            displayBoard(boardChar);

            //Wait for the user input
            char input;
            std::cin >> input;

            //Convert the input into int
            int intInput = convertInputToInt(input);

            //if the input is valid
            if (intInput >= 0) {
                //Change the value of the board
                boardChar[intInput] = playerChar;
                notValidInput = false;
            }
            //if not
            else{
                std::cerr << "Entree invalide >:(";
            }
        } while (notValidInput);

    }while(!checkWin(boardChar, playerChar)); //Repeat until someone won

    //Display the winner
    if(playerChar == 'X') {
        std::cout << "Player 1 won!!!!!!";
    }
    else{
        std::cout << "Player 2 won!!!!!!";
    }


    return 0;
}


