#ifndef ORDER_H
#define ORDER_H 
#include "robot.h"
#include "customer.h"
#include "sales_associate.h"
using namespace std;

class Order
{
	public:
	  Order(int _order_number, string _date, Robot_model _robot_model, int _quantity,
		Customer _customer, int _status, SalesAssociate _sales_associate);
	  double robot_cost();
	  double extended_price();
	private:
	  int order_number;
	  string date;
	  Robot_model robot_model;
	  int quantity;
	  Customer customer;
	  int status;
	  SalesAssociate sales_associate;
};

#endif
