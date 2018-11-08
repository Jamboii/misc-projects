/*******************************************************
* Name      : Alex Benasutti
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: In Class Assignment #4
********************************************************/
#include <iostream>

using namespace std;


void DisplayMenu();
void GuessANumber();

int main () {
    DisplayMenu();
	return 0;
}

void DisplayMenu() {
    int choice = 0; //initialize choice option
    while (choice != 2) {
        cout << "1) Guess a number\n2) Quit\nPlease make a choice: ";
        cin >> choice;
        if (choice == 1)
            GuessANumber();
        //Else, the program stops
    }
}

void GuessANumber() {
    srand (time(NULL));
    int randomNum = rand() % 50, guess, guessLimit = 0; //Range of 0 to 50
    cout << "I'm thinking of a number between 1 and 50. Try to guess it.";
    while (guess != randomNum && guessLimit < 4) {
        cout << "\nWhat is your guess? ";
        cin >> guess;
        guessLimit++; //increment guesses taken
        if (guess < randomNum)
            cout << "\nIncorrect. Your guess was too low. Guesses left: " << 4-guessLimit;
        else if (guess > randomNum)
            cout << "\nIncorrect. Your guess was too high. Guesses left: " << 4-guessLimit;
    }
    
    if (guessLimit < 4) //Loop has ended for one of two reasons: you won or you lost
        cout << "\nCongratulations, your number was " << randomNum << "\n";
    else
        cout << "\nYou used all of your guesses. The actual number was " << randomNum << "\n";
}

