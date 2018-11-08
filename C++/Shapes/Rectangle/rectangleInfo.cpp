/************************************************************
* Name      : Alex Benasutti			
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Homework #3
*************************************************************/
#include <iostream> 
using namespace std;
#include "rectangle.h"

int main() {
    //Declare rectangles
	Rectangle rectangle1;
	Rectangle rectangle2 = Rectangle(5,4);
    Rectangle rectangle3;
	
    //Show information of rectangles
	cout << "Rectangle1's infomation:"  << endl;
	rectangle1.print();
	cout << endl;
 
	cout << "Rectangle2's infomation:"  << endl;
	rectangle2.print();
    cout << endl;

	rectangle1.setLength(2);
    rectangle1.setWidth(3);
	
	cout << "Rectangle1's new infomation:"  << endl;
	rectangle1.print();
	cout << endl;
    
    rectangle3 = rectangle1 + rectangle2;
    cout << "Rectangle3's infomation:"  << endl;
    rectangle3.print();
    cout << endl;

   return 0;
   
} // end of main()
