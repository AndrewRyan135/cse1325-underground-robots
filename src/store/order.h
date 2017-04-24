#ifndef ORDER_H
#define ORDER_H
#include "robot.h"
#include "customer.h"
#include "sales_associate.h"
#include <fstream>
#include <iostream>
using namespace std;

class Order
{
	public:
	  Order(int _order_number, string _date, Robot_model _robot_model, int _quantity,
		Customer _customer, int _status, Sales_associate _sales_associate);
	  double robot_cost();
	  double extended_price();
	  //getters
	  int get_order_number();
	  string get_date();
	  Robot_model get_robot_model();
	  int get_quantity();
	  Customer get_customer();
	  int get_status();
	  string to_string();
	  void set_status(int new_status);
	  string status_to_string();
	  Sales_associate get_sales_associate();
	  void save_order(ostream& ofs);

	private:
	  int order_number;
	  string date;
	  Robot_model robot_model;
	  int quantity;
	  Customer customer;
	  int status;
	  Sales_associate sales_associate;
};

#endif
