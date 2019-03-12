#include <iostream>

using namespace std;

int main () {
    
    // Define input variables for calculating gross/net pay
    double payRate;
    int regHours;
    int weekHours;
    int dependents;
    
    // Define constant tax rates/values for deductables
    const double SSTAX = 0.06;  // Social Security Tax
    const double FITAX = 0.14;  // Federal Income Tax
    const double SITAX = 0.05;  // State Income Tax
    const double UDTAX = 10.00; // Union Dues Tax
    const double HITAX = 35.00; // Health Insurance (dependents > 3)
	
    // Allow user to give value to our input variables
	cout << "Welcome! What is the worker's Pay Rate: ";
    cin >> payRate;
    cout << "\nRegular Hours: ";
    cin >> regHours;
    cout << "\nWeekly Hours: ";
    cin >> weekHours;
    cout << "\nDependents: ";
    cin >> dependents;
    
    // Calculate gross/net pay and deductables based on input variables
    double grossPay = payRate * regHours + payRate * 1.5 * (weekHours - regHours); // 1.5x pay rate for overtime hours
    double ssDeduct = grossPay * SSTAX;
    double fiDeduct = grossPay * FITAX;
    double siDeduct = grossPay * SITAX;
    double netPay   = grossPay - ssDeduct - fiDeduct - siDeduct - UDTAX;
    
    // Output calculated gross/net pay
    cout.precision(2); // Set precision equal to the hundredths place for currency's sake
    cout << endl;
    cout << "Gross Pay ................ = $" << fixed << grossPay << endl;
    cout << "Social Security Tax ...... = $" << fixed << ssDeduct << endl;
    cout << "Federal Income Tax ....... = $" << fixed << fiDeduct << endl;
    cout << "State Income Tax ......... = $" << fixed << siDeduct << endl;
    cout << "Union Dues ............... = $" << fixed << UDTAX << endl;
    if (dependents >= 3) // 3 or more dependents incites a health insurance tax deductable
    {
        netPay -= 35;
        cout << "Health Insurance Tax ..... = $" << fixed << HITAX << endl;
    }
    cout << "Net Pay .................. = $" << fixed << netPay << endl;
	
	return 0;
	
} // end of main()

