/*******************************************************
* Name      : Alex Benasutti
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Homework 1
********************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
    srand (time(NULL));
    int randomNum = rand() % 50, guess, guessLimit = 0; //Range of 0 to 50
    string order[4] = {"first", "second", "third", "fourth"}; //Create an array to determine the amount of guesses
    
    printf("I'm thinking of a number between 1 and 50. Try to guess it.");
    do {
        cout << "\nWhat is your " << order[guessLimit] << " guess? ";
        cin >> guess;
        guessLimit++; //increment guesses taken
        if (guess < randomNum)
            cout << "\nIncorrect. Your guess was too low. Guesses left: " << 4-guessLimit;
        else if (guess > randomNum)
            cout << "\nIncorrect. Your guess was too high. Guesses left: " << 4-guessLimit;
        
    } while (guess != randomNum && guessLimit < 4); //Repeat loop so long as you keep getting a wrong answer or you still have guesses
        
        if (guessLimit < 4) //Loop has ended for one of two reasons: you won or you lost
            cout << "\nCongratulations, your number was " << randomNum << "\n";
        else
            cout << "\nYou used all of your guesses. The actual number was " << randomNum << "\n";

	return 0;
	
} // end of main()

