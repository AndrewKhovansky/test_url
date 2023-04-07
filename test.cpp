#include <stdio.h>
#include <iostream>
#include <string>

#include "urlparser.h"
using namespace std;
 


int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Nothing to parse\r\n";
		return 1;
	}
	
	
	if(argc < 3)
	{
		cout << "No element index given\r\n";
		return 1;
	}
	
	int index = atoi(argv[2]);
	
	
	
	URLParser parser(argv[1]);
	
	
	enum Method method = parser.get_method();
	
	if(method == MethodPUT) cout << "Method: PUT\r\n";
	if(method == MethodGET) cout << "Method: GET\r\n";
	if(method == MethodPOST) cout << "Method: POST\r\n";
	if(method == MethodDELETE) cout << "Method: DELETE\r\n";
	if(method == MethodNONE) cout << "Method: NONE\r\n";
	
	cout << parser.get_element(index);
	
	return 1;
}