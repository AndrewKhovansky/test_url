enum Method
{
	MethodNONE,
	MethodPOST,
	MethodGET,
	MethodDELETE,
	MethodPUT,
};


class URLParser
{
	std::string input;
	
public:
	URLParser(const char* instring);
	
	enum Method get_method(void);
	std::string get_element(int index);
	
};

