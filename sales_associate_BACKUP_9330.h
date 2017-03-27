#pragma once
#include <iostream>
#include <string>
#include <sstream>
<<<<<<< HEAD
using namespace std
=======
using namespace std;
>>>>>>> 0554bcd7b3fe0ce08d899d1bc452f14d3cda3785

class SalesAssociate
{
	public :
		SalesAssociate(string name, int employee_number) : _name(name), _employee_number(employee_number) {}
		string to_string();
	private :
		string _name;
		int _employee_number;
};

