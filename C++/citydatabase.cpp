#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class city{ // create node for city
public:
    string name;
    int x;
    int y;
    city *left;
    city *right;
    bool deleted;
};

class database{ // binary tree database
    // behind the scenes methods for inputting/searching data
private:
    city *root;
    // input contents of city struct based on parameters from public method
    void insert(city *&temp, string name, int x, int y){
        if(temp == NULL){
            temp = new city();
            temp->name = name;
            temp->x = x;
            temp->y = y;
            temp->left = NULL;
            temp->right = NULL;
            temp->deleted = false;
        }
        else{ // place node based on city name in comparison to root
            if(name < temp->name){
                insert(temp->left, name, x, y);
            }
            else if(name > temp->name){
                insert(temp->right, name, x, y);
            }
            else{
                if(temp->deleted == true){
                    temp->deleted = false;
                    temp->x = x;
                    temp->y = y;
                }
                else{
                    insert(temp->right, name, x, y);
                }
            }
        }
    }
    /* input city name and find where it is in the tree by recursively checking each node
     based on whether the searched name's value is bigger or smaller than the one being checked */
    city *findByName(city *temp, string name){
        if(temp != NULL){
            if(temp->name == name) return (temp->deleted == false ? temp : findByName(temp->right, name));
            else if(name < temp->name) return findByName(temp->left, name);
            else if(name > temp->name) return findByName(temp->right, name);
        }
        else{ // city cannot be found
            return NULL;
        }
    }
    /* input x and y coordinates and find those coordinates in the tree by recursively checking
       each set of coordinates */
    city *findByCoordinates(city *temp, int x, int y){
        if(temp == NULL){
            return NULL;
        }
        else{
            city *ret = NULL;
            if(temp->x == x && temp->y == y){
                if(temp->deleted == false){
                    ret = temp;
                }
            }
            if(ret == NULL){
                ret = findByCoordinates(temp->left, x, y);
            }
            if(ret == NULL){
                ret = findByCoordinates(temp->right, x, y);
            }
            return ret;
        }
    }
public:
    // base constructor for bst
    database(){
        root = NULL;
    }
    // transform every inserted name into uppercase for easier searching
    void insert(string name, int x, int y){
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        insert(root, name, x, y);
    }
    // return the city class that corresponds to the name being searched
    void searchByName(string name){
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        city *found = findByName(root, name);
        if(found == NULL){
            cout << "No record found for " << name << endl;
        }
        else{
            cout << "Record found for " << found->name << " with coordinates (" << found->x << ", " << found->y << ")" << endl;
        }
    }
    // return the city class that corresponds to the coordinates being searched
    void searchByCoordinates(int x, int y){
        city *found = findByCoordinates(root, x, y);
        if(found == NULL){
            cout << "No city found with coordinates (" << x << ", " << y << ")" << endl;
        }
        else{
            cout << "Record found for " << found->name << " with coordinates (" << found->x << ", " << found->y << ")" << endl;
        }
    }
    // find the city class by name and set its deleted attribute to true to no longer see it when searching
    void deleteByName(string name){
        city *found = findByName(root, name);
        if(found == NULL){
            cout << "No record found for " << name << endl;
        }
        else{
            cout << "City " << found->name << " found at (" << found->x << ", " << found->y << ") has been deleted" << endl;
            found->deleted = true;
        }
    }
    // find the city class by coordinates and set its deleted attribute to true to no longer see it when searching
    void deleteByCoordinates(int x, int y){
        city *found = findByCoordinates(root, x, y);
        if(found == NULL){
            cout << "No city found with coordinates (" << x << ", " << y << ")" << endl;
        }
        else{
            cout << "City " << found->name << " found at (" << found->x << ", " << found->y << ") has been deleted" << endl;
            found->deleted = true;
        }
    }
};

int main(int argc, char* argv[]){
    ifstream fin;
    string src_filename;
    
    // Set up failsafe for correct usage of parameters
    if (argc > 2)
    {
        fprintf( stderr, "\nUsage: Project4 <src_filename>\n" );
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
    cout << "CITY DB: " << src_filename << " opened successfully"   << endl;
    cout << "-----------------------------------------------------" << endl;
    
    string line; // get set of data
    cout << "-----------------------------------------------------" << endl;
    cout << "Database Contents:"                                    << endl;
    cout << "-----------------------------------------------------" << endl;
    database bst; // initialize bst
    while (getline(fin,line)) // take a line from cities file
    {
        stringstream ss(line);
        string token, city;
        int val = 0, x, y;
        cout << line << endl;
        while (getline(ss,token,',')) // separate that line of data by its commas
        {
            if (val == 0) // city
                city = token;
            else if (val == 1) // x coord
                x = stoi(token);
            else if (val == 2) // y coord
            {
                y = stoi(token);
                bst.insert(city, x, y); // insert new city into bst
            }
            val++;
        }
    }
    
    // Search "engine"
    int input;
    while (1)
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Search options: 1 - by City Name, 2 - by Coordinates, 3 - EXIT: ";
        cin  >> input;
        if (input == 1) // Search by City Name
        {
            string city;
            cout << "Enter a city name: ";
            cin  >> city;
            bst.searchByName(city);
        }
        else if (input == 2) // Search by Coordinates
        {
            int x,y;
            cout << "Enter x coordinate: ";
            cin  >> x;
            cout << "Enter y coordinate: ";
            cin  >> y;
            bst.searchByCoordinates(x,y);
        }
        else if (input == 3) // EXIT
        {
            break;
        }
        else // Some other integer
        {
            cout << "Incorrect input" << endl;
        }
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "End of Run" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    return 0;
}
