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
Sales_associate Order :: get_sales_associate()
{
    return sales_associate;
}
//File insertion friend function
ostream& operator<<(ostream& os, const Order x)
{
    os << x.order_number() << endl;
    os << x.date() << endl;
    os << x.robot_model() << endl;
    os << x.quantity() << endl;
    os << x.customer() << endl;
    os << x.status() << endl;
    os << x.sales_associate() << endl;
    return os;
}
//File extraction friend function
istream& operator>>(istream& is, Order x)
{
    is >> x.order_number >> x.date >> x.robot_model >> x.quantity >> x.customer >> x.status >> x.sales_associate;
    return is;
}
