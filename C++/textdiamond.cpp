/*******************************************************
* Name      : Alex Benasutti
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: In Class Assignment #3
********************************************************/
#include <iostream>

using namespace std;

int main () {
    //Declare main constants
    const char SPACE = ' ', X = 'x';
    int spaceBetween = 18, spaceOutside = 0, holder;
    
    //Display the first ten rows of "X"
    for (int i=1;i<=9;i++) {
        cout << "\n";
        for (int j=0;j<spaceOutside;j++)
            cout << SPACE;
        cout << X;
        for (int k=0;k<spaceBetween;k++)
            cout << SPACE;
        cout << X;
        spaceBetween-=2;
        spaceOutside+=1;
    }
    cout << "\n         xx";
    //Display the last ten rows of "X"
    for (int n=9;n>=0;--n) {
        cout << "\n";
        for (int j=0;j<spaceOutside;j++)
            cout << SPACE;
        cout << X;
        for (int k=0;k<spaceBetween;k++)
            cout << SPACE;
        cout << X;
        spaceBetween+=2;
        spaceOutside-=1;
    }
    
	return 0;
}

