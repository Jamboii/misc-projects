/*******************************************************
* Name      : Alex Benasutti		
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Homework #3
********************************************************/
#include <string> 
using namespace std;

class Rectangle {
    
    // Private Data
	private:
		double length;
		double width;
		
    // Public Methods
	public:
		// Constructors
		Rectangle ();
        Rectangle (double theLength, double theWidth);
		
		// Set Data Methods
		void   setLength (double newLength);
        void   setWidth (double newWidth);
		
        // Return Data Methods
		void   print           () const;
		double getLength       () const;
		double getWidth        () const;
		double getPerimeter    () const;
		double getArea         () const;

		// Operators to be used with Rectangle objects
		Rectangle operator+(Rectangle op2);
};
