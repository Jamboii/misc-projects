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

//--------------------------------
// Word Structure
//--------------------------------
struct WordObj
{
    string value;            // the word text
    vector<int> linenumbers; // line numbers in file
};

//--------------------------------
// File Structure
//--------------------------------
struct FileObj
{
    string filename;        // the name of the file
    int wordcount;          // the number of words
    int linecount;          // the number of lines
    vector<WordObj> words;  // vector of words in the file
};

//--------------------------------
// Declare function prototypes
//--------------------------------
FileObj processFile(ifstream &infile, string filename);

vector<FileObj> run(ifstream &infile);

void displaySummary(vector<FileObj>);

void wordSearch(vector<FileObj>);

int main(int argc, char *argv[])
{
    ifstream fin;
    string src_filename;
    
    // Set up failsafe for correct usage of parameters
    if (argc != 2)
    {
        fprintf( stderr, "\nUsage: FileParser <src_filename>\n" );
        fprintf( stderr, "    where src_filename contains the file names to be processed\n" );
        exit(-1);
    }
    
    src_filename = argv[1];
    
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
    
    // Begin processing files found in argument file
    cout << "\n++++++ Processing the Input Files ++++++" << endl;
    
    // Store data for each file in a vector
    vector<FileObj> datafiles = run(fin);
    
    // Display summary of vector
    displaySummary(datafiles);
    
    fin.close();
    
    // Search for words through datafiles
    wordSearch(datafiles);
    
    return 0;
}

vector<FileObj> run(ifstream &infile)
{
    string filename;
    vector<FileObj> datafiles;
    
    // Process each line for each data file
    while ( getline(infile,filename) )
    {
        // Display name for data file
        cout << filename << endl;
        
        // Attempt opening data file
        ifstream file(filename);
        
        if (!file.fail())
        {
            // Process data file if successfully found and add to vector
            FileObj data = processFile(file, filename);
            datafiles.push_back(data);
            file.close();
            
            cout << "Finished processing " << filename << endl;
        }
        else
            cout << "FileParser1 error: Can't open file - " << filename << endl;
    }
    
    return datafiles;
}

FileObj processFile(ifstream &infile, string filename)
{
    string line;
    FileObj data;
    
    int wordcount = 0;
    int linecount = 0;
    
    // Add file name to data FileObj
    data.filename = filename;
    
    // Process each line of data file and record words, word counts, and line counts
    while (getline(infile, line))
    {
        // Remove punctuation from line
        line.erase(remove_if (line.begin (), line.end (), ::ispunct), line.end());
        // Force every line to upper case
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        linecount++;
        
        int pos = 0;
        int space = 0;
        
        // Process the words of the line
        while (pos != line.length())
        {
            // Find space char between two words. If end of line, default to length of line
            int old_pos = pos;
            space = ((int)line.find(" ",pos+1) > space) ? line.find(" ",pos+1) : line.length();
            
            // Initialize word
            string text = line.substr(pos,(space - pos));
            int length = space - pos;
            
            pos += text.length();
            
            // Remove unnecessary spaces
            text.erase(remove(text.begin(), text.end(), ' '), text.end());
            
            // Check if this word has been added before
            bool added = false;
            // Make sure this is a real word we're looking at and not a new line
            if (length - 1 == text.length() || (length == text.length() && old_pos == 0))
            {
                // Loop through words vectors for each word value
                for (int i=0;i<data.words.size();i++)
                {
                    // Word HAS been added already, break immediately
                    if (data.words.at(i).value == text)
                    {
                        data.words.at(i).linenumbers.push_back(linecount);
                        added = true;
                        break;
                    }
                }
                
                // Populate WordObj and add to data FileObj if NOT added
                if (!added)
                {
                    WordObj word;
                    word.value = text;
                    word.linenumbers.push_back(linecount);
                    
                    data.words.push_back(word);
                }
                wordcount++;
            }
        }
    }
    
    // Add word and line count to data FileObj
    data.wordcount = wordcount;
    data.linecount = linecount;
    
    infile.close();
    
    return data;
}

void displaySummary(vector<FileObj> files)
{
    // Display summary by iterating through files. If only 1 line or 1 word in file, change string
    cout << "-----------------------------------------------------" << endl;
    for (int i=0;i<files.size();i++)
    {
        cout << files.at(i).filename << "\thas " << files.at(i).linecount << (files.at(i).linecount > 1 ? " lines " : " line  ") << " and " << files.at(i).wordcount << ((files.at(i).wordcount > 1) ? " words" : " word") << endl;
    }
    cout << "-----------------------------------------------------" << endl;
}

void wordSearch(vector<FileObj> datafiles)
{
    string word;
    int hits = 0, misses = 0;
    // Ask for user-input until told otherwise
    while (1)
    {
        // Ask user for target word and force input as uppercase
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Please enter a target word: ";
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        
        // End loop; display summary of searches
        if (word == "BYE-BYE")
        {
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Total successful searches  : " << hits << endl;
            cout << "Total unsuccessful searches: " << misses << endl;
            cout << "END OF RUN" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            break;
        }
        
        // Loop through each data file for each search
        bool hit = false;
        for (int i=0;i<datafiles.size();i++)
        {
            cout << "-----------------------------------------------------" << endl;
            vector<int> linenums;
            // Loop through words vector of each file
            for (int j=0;j<datafiles.at(i).words.size()-1;j++)
            {
                // if theres a match
                if (datafiles.at(i).words.at(j).value == word)
                    linenums = datafiles.at(i).words.at(j).linenumbers;
            }
            // If linenums is populated, show there was a successful search
            if (linenums.size() > 0)
            {
                hit = true;
                cout << word << " found in file: " << datafiles.at(i).filename << endl;
                cout << "On lines: ";
                for (int k=0;k<linenums.size();k++)
                    cout << linenums.at(k) << " ";
                cout << endl;
            }
            else
                cout << word << " not found in file: " << datafiles.at(i).filename << endl;
        }
        if (hit)
            hits++;
        else
            misses++;
    }
}
