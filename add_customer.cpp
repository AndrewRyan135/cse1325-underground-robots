#include "add_customer.h"

string Customer::to_string()
{
	string output = "";
	output = "\nCustomer info: \n\n";
	output = output + "Name: " + name + "\n";
	
	string str;
	ostringstream temp;
	temp<<number;
	str = temp.str();

	output = output + "Number: " + str + "\n";

	output = output + "Phone number: " + phonenumber + "\n";

	output = output + "E-mail: " +email + "\n";

	return output;
}
