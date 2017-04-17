#include "sales_associate.h"

string Sales_associate::to_string()
{
	stringstream os;
	os << "Sales Associate Info:" << "\n" << "Name: " << _name << "\n"
	   << "Employee Number: " << _employee_number << "\n";
	   return os.str();
}

string Sales_associate::name() {return _name;}

void Sales_associate :: save_sales_associate(ostream& ofs)
{
    ofs << "8" << endl
    << _name << endl
    << _employee_number << endl;
}

int Sales_associate :: get_employee_number()
{
    return _employee_number;
}
