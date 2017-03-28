#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class SalesAssociate
{
	public :
		SalesAssociate(string name, int employee_number) : _name(name), _employee_number(employee_number) {}
		string to_string();
	private :
		string _name;
		int _employee_number;
};

