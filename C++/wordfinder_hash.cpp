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

class HashMap
{
    
private:
    
    int MAX = 13;
    linkedlist data[13];
    int collCount[13];
    int size;
    hash<string> hasher;
    
public:
    
    HashMap()
    {
        for (int i = 0; i < MAX; i++)
            collCount[i] = 0;
    }
    
    void add(string value)
    {
        long hash = hasher(value);
        if (hash < 0)
        {
            hash = -hash;
        }
        hash = hash % MAX;
        data[hash].create_node(value);
        //data[hash].display();
        //data[hash].push_back(value);
        collCount[hash]++;
    }
    
    bool see(string value)
    {
        bool found = false;
        long hash = hasher(value);
        if (hash < 0)
        {
            hash = -hash;
        }
        hash = hash % MAX;
        if (data[hash].search(value) == true)
        {
            cout << value << " found at hash " << hash << endl;
            return true;
        }
        else
        {
            cout << value << " not found" << endl;
            return false;
        }
    }
};

int main(int argc, char *argv[])
{
    ifstream fin; // Initiate input stream and await argument
    string src_filename;
    
    // Set up failsafe for correct usage of parameters
    if (argc != 2)
    {
        fprintf( stderr, "\nUsage: wordfinder_hash <src_filename>\n" );
        exit(-1);
    }
    
    src_filename = argv[1];
    
    fin.open( src_filename ) ; // Open the source file input
    if (fin.fail( )) // Ensure failsafe for failed opening
    {
        cout << "Input file opening failed. Make sure you input the name of the file that contains the words to be processed" << endl;
        exit(-1);
    }
    
    cout << "-----------------------------------------------------" << endl;
    cout << "File " << src_filename << " opened successfully"       << endl;
    cout << "-----------------------------------------------------" << endl;
    
    HashMap words;      // Contain words of text file
    string word;        // Temporarily save each line of text file to input into vector
    ifstream file(src_filename);
    bool done = false;
    
    while (!done) // Go through entire text file and stop at the end
    {
        file >> word;
        if (file.eof() == true)
        {
            done = true;
        }
        else
        {
            word.erase(remove_if (word.begin (), word.end (), ::ispunct), word.end()); // Remove puncuation
            transform(word.begin(), word.end(), word.begin(), ::toupper); // Convert line to uppercase
            words.add(word);
        }
    }
    
    int hits = 0;   // Increment for a correct search
    int misses = 0; // Increment for an incorrect search
    string input;   // Input variable
    
    while (1) // Let user continuously enter names to find until "done"
    {
        cout << "Please enter a target word: ";
        cin >> input;
        string in_upper = input;
        transform(in_upper.begin(), in_upper.end(), in_upper.begin(), ::toupper);
        bool found = false;
        
        if ( in_upper == "SEE-YA" ) // In the case that the user is done with the program, add whitespace
        {
            // Process summary
            cout << "---------- Summary ----------" << endl;
            cout << "There were " << hits   << " successful searches"   << endl;
            cout << "There were " << misses << " unsuccessful searches" << endl;
            cout << "---------- End ----------" << endl;
            break;
        }
        
        found = words.see(in_upper); // Search through hash table for matching input
        if (found)
            hits += 1;
        else // Input string is not in the hash table
            misses += 1;
    }
    return 0;
}
