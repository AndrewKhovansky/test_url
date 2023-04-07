#include <stdio.h>
#include <iostream>
#include <string>

#include "urlparser.h"
using namespace std;
 


int main(int argc, char *argv[])
{
	if(argc < 3) //Check for arguments
	{
		cout << "Not enough arguments\r\n";
		return 1;
	}
	
	int index = atoi(argv[2]); //Index of element
	
	
	
	URLParser parser(argv[1]); //Construct parser with an input string
	
	
	enum Method method = parser.get_method(); //Get method 
	
	if(method == MethodPUT) cout << "Method: PUT\r\n";
	if(method == MethodGET) cout << "Method: GET\r\n";
	if(method == MethodPOST) cout << "Method: POST\r\n";
	if(method == MethodDELETE) cout << "Method: DELETE\r\n";
	if(method == MethodNONE) cout << "Method: NONE\r\n";
	
	cout << parser.get_element(index) << "\r\n";
	
	return 1;
}