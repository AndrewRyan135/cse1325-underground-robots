#include "order.h"
#include <fstream>
#include <iostream>

Order :: Order(int _order_number, string _date, Robot_model _robot_model, int _quantity,
	       Customer _customer, int _status, Sales_associate _sales_associate) :
	       order_number(_order_number), date(_date), robot_model(_robot_model),
	       quantity(_quantity), customer(_customer), status (_status),
	       sales_associate(_sales_associate){}

double Order :: robot_cost()
{
	return quantity * robot_model.cost();
}
//getters
int Order :: get_order_number()
{
    return order_number;
}
string Order :: get_date()
{
    return date;
}
Robot_model Order :: get_robot_model()
{
    return robot_model;
}
int Order :: get_quantity()
{
    return quantity;
}
Customer Order :: get_customer()
{
    return customer;
}
int Order :: get_status()
{
    return status;
}
string Order::to_string()
{
	stringstream os;
	os << "Order number:\t\t" << order_number <<'\n' << "Date:\t\t\t" << date
	   << '\n' << "Robot Model:\t\t" << robot_model.get_name() << '\n'
	   << "Quantity:\t\t" << quantity << '\n' << "Customer name:\t\t" << customer.get_name()
	   << '\n' << "Status:\t\t\t" << status << '\n' << "Sales associate name:\t" << sales_associate.get_name()
	   << '\n';
	return os.str();
}
void Order :: set_status(int new_status)
{
    status = new_status;
}
string Order :: status_to_string()
{
    switch(status)
    {
    case 1:
        {
            return "New Order";
        }
    case 2:
        {
            return "Robot Built";
        }
    case 3:
        {
            return "Invoice Sent";
        }
    case 4:
        {
            return "Payment Received";
        }
    case 5:
        {
            return "Robot Shipped";
        }
    }
    return "Unknown Status";
}
Sales_associate Order :: get_sales_associate()
{
    return sales_associate;
}

void Order :: save_order(ostream& ofs)
{
    ofs << "9" << endl
    << order_number << endl
    << date << endl
    << robot_model.get_model_number() << endl
    << quantity << endl
    << customer.get_customer_number() << endl
    << status << endl
    << sales_associate.get_employee_number() << endl;
}
