#include "order.h"

Order :: Order(int _order_number, string _date, Robot_model _robot_model, int _quantity,
	       Customer _customer, int _status, SalesAssociate _sales_associate) : 
	       order_number(_order_number), date(_date), robot_model(_robot_model), 
	       quantity(_quantity), customer(_customer), status (_status), 
	       sales_associate(_sales_associate){}

double Order :: robot_cost()
{
	return quantity * robot_model.cost();
}

double Order :: extended_price()
{
	return 1.2 * quantity * robot_model.cost();
}
