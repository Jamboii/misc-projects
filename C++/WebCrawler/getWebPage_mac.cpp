#include <errno.h>  
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <iostream>

using namespace std;

// "BSIZE" is the size of the buffer we use to read from the socket. 

int const BSIZE = 4096;

// Get the web page and return it in the last argument
int getWebPage (string host, string page, string &html)
{
    
    struct addrinfo hints, *res, *res0;
    char * msg;
    int    sp;  // the socket pointer
    string tempString;
	int    returnCode = 0;

    const char * format =
        "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: fetch.c\r\n\r\n";
    
    html = "";

    // Don't specify what type of internet connection. 
    memset (&hints, 0, sizeof (hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    // Translate the host name to an ip address
    if (getaddrinfo (host.c_str(), "http", &hints, &res0) != 0)
        returnCode = 1;
    
    sp = -1;
    for (res = res0; res != 0 & returnCode == 0; res = res->ai_next) {
        sp = socket (res->ai_family, res->ai_socktype, res->ai_protocol);
        
        if (sp < 0)
            returnCode = 2;
        
        if (connect (sp, res->ai_addr, res->ai_addrlen) < 0) {
            close (sp);
            returnCode = 3;
        }
        
        break;
    }
    
    // Return and error if we cannot get a socket
    if (returnCode == 0 & sp < 0 )
        returnCode = 4;

	// Format the request
	if (returnCode == 0) {
		if (asprintf (&msg, format, page.c_str(), host.c_str()) < 0)
			returnCode = 5;
    }
	
    // Send the request. 
    if (returnCode == 0) {
		if (send (sp, msg, strlen (msg), 0) < 0)
			returnCode = 6;
    }
	
    while (returnCode == 0) {
	
        int bytes;          // The number of bytes received. 
        char buf[BSIZE+10]; // Our receiving buffer.
	
	    // Get "BSIZE" bytes from the socket, sp 
        bytes = recvfrom (sp, buf, BSIZE, 0, 0, 0);
	
	    // Stop once there is nothing left to read
        if (bytes == 0) {
            break;
        }
        
        if (bytes ==  -1)
            returnCode = 7;
        
        buf[bytes] = '\0';
        tempString = string(buf);
        html = html + tempString;
    }
    
	// Close the socket and free any memory we allocated
    close        (sp);
    free         (msg);
    freeaddrinfo (res0);
    
    return returnCode;
    
}
