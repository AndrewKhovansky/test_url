/*
 * testurl.cpp
 *
 *  Created on: 7 апр. 2023 г.
 *      Author: khova
 */
 
#include <iostream>
#include <string>
#include "urlparser.h"
using namespace std;



URLParser::URLParser(const char* in_string)
{
	input = new std::string(in_string);
	
}


enum Method URLParser::get_method(void)
{
	std::string token = input->substr(0, input->find(" "));
	
	if (token == "GET") return MethodGET;
	else if (token == "POST") return MethodPOST;
	else if (token == "PUT") return MethodPUT;
	else if (token == "DELETE") return MethodDELETE;
	
	return MethodNONE;
}