/************************************************************
* Name      : Prof. Domen			
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Object Oriented Programming
*
* To compile this, you need also need circle.h and circle.cpp
* 
* g++ lecture18.cpp circle.cpp -o lecture18.exe
*
* In this example, "Circle" is the class.  circle1, circle2
* and circle3 are objects.
*************************************************************/
#include <iostream> 
using namespace std;
#include "circle.h"  // Include the definition for our Circle class

int main() {
	// Define three different circle's using our new Circle class
	// Each one uses a different one of the constructors we wrote.
	Circle circle1; 
	Circle circle2 = Circle(5);
	Circle circle3 = Circle(6,"red");
	Circle circle4;
	
	// Display the information about each circle
	// When you call the print() method, the code that was
	// written in the circle.cpp file for the print() 
	// method is executed.
	cout << "Circle1's infomation:"  << endl;
	circle1.print();
	cout << endl;
 
	cout << "Circle2's infomation:"  << endl;
	circle2.print();
    cout << endl;

	circle3.setRadius(-2);
	
	cout << "Circle3's infomation:"  << endl;
	circle3.print();
	cout << endl;
	
	circle4 = circle2 + circle3;
	cout << "Circle4's infomation:"  << endl;
	circle4.print();
	cout << endl;
    
    circle4.setDiameter(3);
	
	circle4 = circle4 + 5.3;
	cout << "Circle4's new infomation:"  << endl;
	circle4.print();
	cout << endl;
	
	
   return 0;
   
} // end of main()
