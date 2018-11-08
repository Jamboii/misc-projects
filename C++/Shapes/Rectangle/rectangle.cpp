/*******************************************************
* Name      : Alex Benasutti			
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Homework #3
********************************************************/
#include <iostream> 
#include <string>
#include "rectangle.h"

using namespace std;

//Rectangle set data
void Rectangle::setLength (double newLength) {
   
   if (newLength >= 0){
	   length = newLength;
   }
   return;
}

void Rectangle::setWidth (double newWidth) {
    if (newWidth >= 0){
        width = newWidth;
    }
    return;
}

//Rectangle return data
double Rectangle::getLength() const {
   return length;
}

double Rectangle::getWidth() const {
   return width;
}

double Rectangle::getArea() const {
   return (length*width);
}

double Rectangle::getPerimeter() const {
    if ((length > 0) && (width > 0))
        return (2*length+2*width);
    else
        return 0;
}

void Rectangle::print() const {
   cout << "         length: " << getLength()        << endl;
   cout << "          width: " << getWidth()         << endl;
   cout << "      perimeter: " << getPerimeter()     << endl;
   cout << "           area: " << getArea()          << endl;
}

//Constructors
Rectangle::Rectangle()  {
   length = 0;
   width  = 0;
}

Rectangle::Rectangle(double theLength, double theWidth)  {
   length = theLength;
    width = theWidth;
}

//Operators
Rectangle Rectangle::operator+(Rectangle op2) {
	// New rectangle with original as start
	Rectangle result = Rectangle (length, width);
	
	// Increase dimensions based on 2nd rectangle operand
	result.length = length + op2.length;
    result.width  = width + op2.width;
	
	// return new rectangle
	return result;
}
