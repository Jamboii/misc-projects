/*******************************************************
* Name      : Alex Benasutti			
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Object Oriented Programming
*     
* The code for a method looks like the code you've written
* with the following differences:
*    1) The method name has the format..   Class::Method
*    2) The method can access any private of public data
*       defined for the class. (e.g. "radius" in this example)
*    3) The constructor methods have no return data type.
********************************************************/
#include <iostream> 
#include <string>
#include "circle.h"  // the definion of our Circle class

using namespace std;

/****************************************************
* The code for all the Circle methods that set data.
*****************************************************/
void Circle::setRadius (double newRadius) {
   
   if (newRadius >= 0){
	   radius = newRadius; 
   }
   return;
}

void Circle::setDiameter (double newDiameter) {
    if (newDiameter >= 0){
        radius = newDiameter / 2;
    }
    return;
}

void Circle::setColor(string newColor) {
   color = newColor;
   return;
}

/******************************************************
* The code for all the Circle methods that return data.
*******************************************************/
double Circle::getRadius() const {
   return radius;
}

double Circle::getDiameter() const {
   return (radius*2);
}

double Circle::getArea() const {
   return (pi*radius*radius);
}

double Circle::getCircumference() const {
   return (pi * getDiameter());
}

string Circle::getColor() const {
   return color;
}

void Circle::print() const {
   cout << "          color: " << getColor()         << endl;
   cout << "         radius: " << getRadius()        << endl;
   cout << "       diameter: " << getDiameter()      << endl;
   cout << "  circumference: " << getCircumference() << endl;
   cout << "           area: " << getArea()          << endl;
}

/******************************************************
* The code for all the constructors
*
* The constructors are special in that there is no 
*     return data type for the method.  The method
*     name for constructors is the same name as the class. 
*******************************************************/
Circle::Circle()  {
   radius = 0;
   pi     = 3.14159;
   color  = "black";
}

Circle::Circle(double theRadius)  {
   radius = theRadius;
   pi     = 3.14159;
   color  = "black";
}

Circle::Circle(double theRadius, string theColor)  {
   radius = theRadius;
   pi     = 3.14159;
   color  = theColor;
}

/******************************************************
* The code for all the operators 
*******************************************************/
Circle Circle::operator+(Circle op2) {
	// Create a new circle using the original cirle as a start
	Circle result = Circle (radius, color);
	
	// Increase the radius based on the 2nd circle operand
	result.radius = radius + op2.radius;
	
	// return the new Circle
	return result;
}

Circle Circle::operator+(int op2) {
	// Create a new circle using the original cirle as a start
	Circle result = Circle (radius, color);
	
	// Increase the radius based on the 2nd integer operand
	result.radius = radius + op2;
	
	// return the new Circle
	return result;
}

Circle Circle::operator+(double op2) {
    // Create a new circle using the original cirle as a start
    Circle result = Circle (radius, color);
    
    // Increase the radius based on the 2nd integer operand
    result.radius = radius + op2;
    
    // return the new Circle
    return result;
}
