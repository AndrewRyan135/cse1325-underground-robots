#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "robot.h"
using namespace std;

class Customer
{
	public:
	  Customer(string c_name, int c_number, string c_phonenumber, string c_email) :
	  name(c_name), number(c_number), phonenumber(c_phonenumber), email(c_email) {}
	  string to_string();
	  string name();
	  void save_customer(ostream& ofs);
	  int get_customer_number();

	private:
	  string name;
	  int number;
	  string phonenumber;
	  string email;
	  //Robot_model customer_order;
};
