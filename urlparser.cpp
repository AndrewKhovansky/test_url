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
	//Define the dynamic array variable of strings
    std::vector<std::string>  outputArray;

    //Construct a stream from the string
    std::stringstream streamData(input);

    /*
    Declare string variable that will be used
    to store data after split
    */
    std::string val;

    /*
    The loop will iterate the splitted data and
    insert the data into the array
    */
    while (std::getline(streamData, val, '/')) {
        outputArray.push_back(val);
    }
								 
	return outputArray[index];
								 
								 
}