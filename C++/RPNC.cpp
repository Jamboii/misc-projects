#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <stdint.h>
#include <stdlib.h>

#include "stack.hpp"

using namespace std;

int rpn(const string &expr)
{
    Stack values(10); // double stack with 10 values max
    istringstream iss(expr); // input string stream to operate on expression
    string token;
    int tokens = 0;
    while (iss >> token)
    {
        double tokenNum;
        if (istringstream(token) >> tokenNum) // if input of string classifies as double
        {
            values.push(tokenNum);
            tokens++;
        }
        else if (tokens < 2) // reached operation but not enough operands
        {
            cerr << "RPNC ERROR Invalid Expression: " << expr << endl;
            return 0;
        }
        else // reached operation and have enough operands
        {
            // pop last 2 operand inputs
            double secondOp = values.peek();
            values.pop();
            double firstOp  = values.peek();
            values.pop();
            
            // perform operation based on token
            if (token == "*")
                values.push(firstOp * secondOp);
            else if (token == "/")
                values.push(firstOp / secondOp);
            else if (token == "+")
                values.push(firstOp + secondOp);
            else if (token == "-")
                values.push(firstOp - secondOp);
            else if (token == "^")
                values.push(pow(firstOp,secondOp));
            else // operation not applicable
            {
                cerr << "RPNC ERROR Invalid Expression: " << expr << endl;
                return 0;
            }
            // set tokens to amount of operands still in the stack
            tokens = values.size();
        }
    }
    if (values.size() == 1)
        cout << expr << "\t\t\t   = " << values.peek() << endl;
    else
        cerr << "RPNC ERROR Invalid Expression: " << expr << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    ifstream fin;
    string src_filename;
    
    // Set up failsafe for correct usage of parameters
    if (argc > 2)
    {
        fprintf( stderr, "\nUsage: FileParser <src_filename>\n" );
        fprintf( stderr, "    where src_filename contains the file names to be processed\n" );
        exit(-1);
    }
    else if (argc == 2) // filename
        src_filename = argv[1];
    else // prompt user for input of file
    {
        cout << "Input an expressions file: ";
        cin  >> src_filename;
    }
    
    // check to make sure file input is correct
    fin.open(src_filename);
    if (fin.fail())
    {
        cout << "Input file opening failed. Make sure you input the name of the file that contains the names of files to be processed" << endl;
        return 1;
    }
    
    // Display opening message
    cout << "-----------------------------------------------------" << endl;
    cout << "File " << src_filename << " opened successfully"       << endl;
    cout << "-----------------------------------------------------" << endl;
    
    string expr; // get expression
    cout << "+++++++++++++++++++++++++++++++" << endl;
    while (getline(fin,expr))
    {
        cout << "Evaluating expression: " << expr << endl;
        rpn(expr); // Evaluate expression in text file using Reverse Polish Notation
        cout << "+++++++++++++++++++++++++++++++" << endl;
    }
    
    return 0;
}

