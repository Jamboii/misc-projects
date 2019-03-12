#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "linkedlist.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin; // Initiate input stream and await argument
    string src_filename;
    
    // Set up failsafe for correct usage of parameters
    if (argc != 2)
    {
        fprintf( stderr, "\nUsage: namefinder_linkedlist <src_filename>\n" );
        exit(-1);
    }
    
    src_filename = argv[1];
    
    fin.open( src_filename ) ; // Open the source file input
    if (fin.fail( )) // Ensure failsafe for failed opening
    {
        cout << "Input file opening failed. Make sure you input the name of the file that contains the names of files to be processed" << endl;
        exit(-1);
    }
    
    linkedlist names;   // Contain names of text file
    string line;        // Temporarily save each line of text file to input into vector
    ifstream file(src_filename);
    
    while ( getline(file,line) ) // Go through entire text file and stop at the end
    {
        transform(line.begin(), line.end(), line.begin(), ::toupper); // Convert name to uppercase
        names.create_node(line); // Add name to linked list
    }
    
    int hits = 0;   // Increment for a correct search
    int misses = 0; // Increment for an incorrect search
    string input;   // Input variable
    names.display();
    
    while ( input != "done" ) // Let user continuously enter names to find until "done"
    {
        cout << "Please enter a name to find : ";
        cin >> input;
        string in_upper = input;
        transform(in_upper.begin(), in_upper.end(), in_upper.begin(), ::toupper); // Convert temp variable for ease of searching
        bool found = names.search(in_upper); // Search through linked list for matching input
        if (found)
        {
            hits += 1;
            cout << input << " found" << endl;
        }
        else if ( input == "done" ) // In the case that the user is done with the program, add whitespace
        {
            cout << endl;
        }
        else // Input string is not in the vector
        {
            misses += 1;
            cout << input << " not found" << endl;
        }
    }
    
    // Process summary
    cout << "---------- Summary ----------" << endl;
    cout << "There were " << hits   << " successful searches"   << endl;
    cout << "There were " << misses << " unsuccessful searches" << endl;
    cout << "---------- End ----------" << endl;
    
    return 0;
}
