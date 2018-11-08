/*******************************************************
* Name      : Alex Benasutti
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: In Class Assignment #2
********************************************************/
#include <iostream>

using namespace std;

int main () {
    //Declare main variables
    float total = 0, num, average;
    int numbers;
    
    //Ask for how long the loop will run
	cout << "How many numbers are you averaging? ";
    cin >> numbers;
    
    //Add all numbers together
    for (int i=1;i<=numbers;i++) {
        cout << "\n" << i << ": Insert a number: ";
        cin >> num;
        total = total + num;
    }
    
    //Find the average of the numbers
    average = total / numbers;
    cout << "The average is: " << average << "\n";
    
	return 0;
	
}

