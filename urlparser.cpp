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
#include <sstream>   
#include <map>
#include "urlparser.h"
using namespace std;



URLParser::URLParser(const char* instring) //Constructor
{
	input = std::string(instring); //Init an input string (convert from const char* to std::string)
}


enum Method URLParser::get_method(void) //URL method parser
{
	std::string token = input.substr(0, input.find(" ")); //Get a substring from begin to a ' ' delimiter
	
	if (token == "GET") return MethodGET;
	else if (token == "POST") return MethodPOST;
	else if (token == "PUT") return MethodPUT;
	else if (token == "DELETE") return MethodDELETE;
	
	return MethodNONE; //No method
}


std::string URLParser::get_element(int index) //Get an element 
{
    std::vector<std::string>  strarray; //Init an output vector (array of strings)
    std::stringstream streamData(input); //Create stringstream
    std::string val;

    while (std::getline(streamData, val, '/')) //Get lines from stringstream to a val variable. '/' is a delimiter 
	{
        strarray.push_back(val); //Append value to the end of array
    }
				
    if(strarray.size() < (index + 4)) //Check bounds. Skip three '/' delimiters (two after http: and one after domain name)
	{
		return "";
	}
		
	return strarray[index + 3]; //Skip three '/' delimiters
}


std::map<std::string,std::string> URLParser::get_keys_values()
{
	
	std::map<std::string,std::string> outmap;
	
	if(input.length() == 0)
		return outmap;
	
	
	std::string arg_begin = input.substr(input.find("&") + 1, (input.length()-1)); //Get a substring starting after "&" symbol
	
	
}