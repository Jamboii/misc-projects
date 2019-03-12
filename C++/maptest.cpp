#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class MyMap
{

  private:
 
    int MAX = 13;
    vector<string> data[13];
    int collCount[13];
    int size;
    hash<string> hasher;


  public:

    MyMap()
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
       if (collCount[hash] == 0)
       {
          cout << "Hash collision, hash = " <<  hash << " for " << value << " added to map" << endl;
       }
       else
       {
          cout << "++ Added to map, hash = " <<  hash << " for " << value << endl;
       }  
       data[hash].push_back(value);
       collCount[hash]++;
    }

    vector<string> get(string value)
    {
       long hash = hasher(value);
       if (hash < 0)
       {
          hash = -hash;
       }
       hash = hash % MAX;
       return data[hash];         
    } 

     
    void show()
    {
       cout << "++++++++++++ MAP CONTENTS +++++++++++++" << endl;
       for (int i = 0; i < MAX; i++)
       {
          cout << "HASH: " << i << " collisions: " << collCount[i] << " DATA: " << endl;
          //vector<string>::iterator sVar = data[i].begin();
          //while(sVar != data[i].end() )
          //{
          //  cout << *sVar << " ";
          //  sVar++;
          //}
       }
    }
};

int main(int argc, char *argv[])
{
    MyMap m;
    string value;
    string filename;
    bool done = false;
 
    if (argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        cout << "Error: File not found - " << filename << endl;
        return 1; 	
    }

    // Create input file stream and check for errors

    ifstream infile(filename);
    if (infile.fail())
    {
        cout << "Error: Can't open file - " << filename << endl;
        return 2;
    }
    else
    {
        cout << "File " << filename << " opened successfully" << endl;
    }

    // Read file and store names in vector
    while (!done)
    {
        infile >> value;
        if (infile.eof() == true)
        {
            done = true;
        }
        else
        {
            m.add(value);
        }
    }

    // close file
    infile.close();
    
    string search = "still";
    
    m.show();
    
    vector<string> thing = m.get(search);
    
    for (int i=0;i<thing.size();i++)
    {
        cout << thing.at(i) << endl;;
    }
}
