#include "Includes.h"

// Constructors
util_meths::util_meths()
{
	_filename = "";
}

// Setter
void util_meths::setFilename(string new_filename)
{
	 _filename = "";
}

// Methods
void util_meths::cfout(string str)
{
	if (str == "endl")
	{
		cout << endl;
	}

	cout << str;
}
