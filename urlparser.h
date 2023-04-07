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
	std::string *input;
	
public:
	URLParser(const char* input);
	
	enum Method get_method(void);
	get_element(int index);
	
};

