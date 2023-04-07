/*
 * testurl.cpp
 *
 *  Created on: 7 апр. 2023 г.
 *      Author: khova
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>      // std::istringstream
#include "urlparser.h"
using namespace std;



URLParser::URLParser(const char* instring)
{
	input = std::string(instring);
	
}


enum Method URLParser::get_method(void)
{
	std::string token = input.substr(0, input.find(" "));
	
	if (token == "GET") return MethodGET;
	else if (token == "POST") return MethodPOST;
	else if (token == "PUT") return MethodPUT;
	else if (token == "DELETE") return MethodDELETE;
	
	return MethodNONE;
}


std::string URLParser::get_element(int index)
{
    std::vector<std::string>  strarray;
    std::stringstream streamData(input);
    std::string val;

    while (std::getline(streamData, val, '/')) {
        strarray.push_back(val);
    }
				
    if(strarray.size() < (index + 4))
	{
		return "";
	}


				
	return strarray[index + 3];
								 
								 
}