#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin; // Initiate input stream and await argument
    string src_filename;
    
    // Set up failsafe for correct usage of parameters
    if (argc != 2)
    {
        fprintf( stderr, "\nUsage: namefinder_vector <src_filename>\n" );
        exit(-1);
    }
    
    src_filename = argv[1];
    
    fin.open( src_filename ) ;
    if (fin.fail( ))
    {
        cout << "Input file opening failed. Make sure you input the name of the file that contains the names of files to be processed" << endl;
        exit(-1);
    }
    
    vector<string> names;   // Contain names of text file
    string line;            // Temporarily save each line of text file to input into vector
    ifstream file(src_filename);
    
    while ( getline(file,line) ) // Go through entire text file and stop at the end
    {
        names.push_back(line); // Add each name to the vector
    }
    
    int hits = 0;   // Increment for a correct search
    int misses = 0; // Increment for an incorrect search
    string input;   // Input variable
    
    while ( input != "done" ) // Let user continuously enter names to find until "done"
    {
        cout << "Please enter a name to find : ";
        cin >> input;
        if (find(names.begin(),names.end(),input)!=names.end()) // Search through vector for input string
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
    
}
