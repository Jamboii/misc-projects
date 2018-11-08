/*******************************************************
* Name      : Alex Benasutti
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: In Class Assignment #10
********************************************************/
#include <iostream>
 
using namespace std;

int main(){
    const string search = "peter piper picked a peck of pickled peppers"; //delcare final string
    int init = 1, fin = 0; //set initial and final substring variables
    while (true) { //continue loop until told to break
        init = search.find("pi",fin); //find "pi"
        if (init == string::npos) //if theres no "pi" then break
            break;
        fin = search.find(" ",init); //final part of word is located where the next empty space is
        cout << search.substr(init,fin-init) << endl; //output word
    }
    return 0;
}

