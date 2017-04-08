#include "sales_associate.h"

string SalesAssociate::to_string()
{
	stringstream os;
	os << "Sales Associate Info:" << "\n" << "Name: " << _name << "\n"
	   << "Employee Number: " << _employee_number << "\n";
	   return os.str();
}

void SalesAssociate :: save_sales_associate(ostream& ofs)
{
    ofs << _name << "," << _employee_number << endl;
}

int SalesAssociate :: get_employee_number()
{
    return _employee_number;
}
