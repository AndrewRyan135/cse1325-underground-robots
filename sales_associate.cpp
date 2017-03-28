#include "sales_associate.h"

string SalesAssociate::to_string()
{
	stringstream os;
	os << "Sales Associate Info:" << "\n" << "Name: " << _name << "\n"
	   << "Employee Number: " << _employee_number << "\n";
	   return os.str();
}
