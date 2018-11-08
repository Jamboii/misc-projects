/*************************************************************
* Name      : Alex Benasutti
* Class     : CSC 215-02
* When      : Fall 2017
* Professor : Domen
* 
* Assignment: Mini Web Browser
*
* Description: This starting example will take a website and
*              a web page and display it's web page as a text
*              string.  Listed below is how to compile it on
*			   either Mac or Windows.  You will need another
*			   C++ code file from Canvas to get this example 
*              to work.
*
* Mac    : g++ browser.cpp getWebPage_mac.cpp -o web
* Windows: g++ browser.cpp getWebPage_win.cpp -o web.exe -lws2_32
* 
**************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// The getWebPage() function  will take a website and a web 
// page and return the web page as an HTML string. The return 
// value will be zero if everything was successful or non-zero
// if some error occurred.
int getWebPage (string WebSite, string WebPage, string& HTMLString);

string Trim(string link);

string NewPage(string link);

vector<string> GetLinks(string html);

int main() {
	string html = NewPage("www.msn.com/");
    vector<string> firstLinks = GetLinks(html); //set vector of first layer hyperlinks
    
    for (int i=0;i<firstLinks.size();i++) {
        string newHtml = NewPage(firstLinks[i]); //Links from first iteration get used for second
        vector<string> secondLinks = GetLinks(newHtml); //Create data for second iteration of links
        cout << "\nLink #" << (i+1) << ": "; //Display links once second loop is done
        cout << firstLinks[i] << endl;
        for (int j=0;j<secondLinks.size();j++)
            cout << "\t" << secondLinks[j] << endl; //Print links inside of first hyperlink
    }
} // end of main()

string Trim(string linkString) { //Find certain qualities about the hyperlink and change accordingly
    string checks[] = {"#","https://","//","/","http://",".com/"};
    for (int i=0;i<5;i++) { //Link trimming
        int checker = linkString.find(checks[i]);
        if (checker != string::npos) { // Check for parts of the string that SHOULDN'T be there
            switch (i) {
                case 0: // Starts with "#"
                    linkString.erase(0,5);
                    break;
                case 1: // Starts with "https://"
                    linkString.erase(0,8);
                    break;
                case 2: // Starts with "//"
                    if (checker == 0) {
                        linkString.erase(0,2);
                    }
                    break;
                case 3: // Starts with "/"
                    if (checker == 0) {
                        linkString.insert(0,"www.msn.com");
                    }
                    break;
                case 4: // Starts with "http://"
                    linkString.erase(0,7);
                    break;
            }
        }
    }
    if (linkString.find(checks[5]) == string::npos) // Check for parts of the string that SHOULD be there
        linkString.append("/");
    return linkString;
}

string NewPage(string linkString) { // Opens new hyperlink
    string html = "";
    int split = linkString.find(".com")+4; // Find area to split between website and webpage
    string website = linkString.substr(0,split), webpage = linkString;
    int checkMe = website.find("www.");
    webpage = webpage.erase(0,split); // Declaring webpage as a substring gave me an error
    int result = getWebPage(website,webpage,html);
    if (result == 0)
        return html;
    else {
        cout << "Error " << result << " getting webpage for "
        << linkString << endl;
        return 0;
    }
}

vector<string> GetLinks(string html) {
    vector<string> links;
    int init = 1, fin = 0;
    while (true) { //continue loop until told to break
        fin = html.find("<a",fin);
        init = html.find("href=\"",fin); //find link start
        if (init == string::npos) //if theres no more links then break
            break;
        fin = html.find("\"",init+6); //final part of link is located where the next quotation is
        string linkString = html.substr(init+6,fin-init-6); //set link to variable
        linkString = Trim(linkString); //search link for wanted/unwanted information so it can be displayed properly
        
        if (linkString.length() > 2)//Check to make sure trimmed link isn't empty
            links.push_back(linkString); //Add first hyperlink to vector
    }
    return links;
}
