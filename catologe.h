#ifndef CATOLOGE_H
#define CATOLOGE_H
#include <vector>
#include "customer.h"
//#include "robot.h"
//#include <add warrens robot model .h file>

class Catologe
{
	public:
	//void add_model(Robot_model model);
	void add_customer(Customer cus);
	string customer_to_string(int customer_number);
	private:
	//vector<Robot_model> robot_model;
	vector<Customer> customer;
};

#endif