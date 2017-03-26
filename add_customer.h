#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <sstream>
using namespace std;

class Customer
{
	public:
	  Customer(string c_name, int c_number, string c_phonenumber, string c_email) :
	  name(c_name), number(c_number), phonenumber(c_phonenumber), email(c_email) {}	 
		
	  //string get_name();
	  //int get_number();
	  //string get_phonenumber();
	  //string get_email();
	  string to_string();
	private:
	  string name;
	  int number;
	  string phonenumber;
	  string email;
	
};

#endif
