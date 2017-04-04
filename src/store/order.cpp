#include "order.h"
#include <fstream>
#include <iostream>

Order :: Order(int _order_number, string _date, Robot_model _robot_model, int _quantity,
	       Customer _customer, int _status, SalesAssociate _sales_associate) :
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
SalesAssociate Order :: get_sales_associate()
{
    return sales_associate;
}

void Order :: save_order(ostream& ofs)
{
    ofs << order_number << "," << date << "," << robot_model.get_model_number() << ","
    << quantity << "," << customer.get_customer_number() << "," << status << ","
    << sales_associate.get_employee_number() << endl;
}
