#ifndef CATOLOGE_H
#define CATOLOGE_H
#include <vector>
#include "add_customer.h"
//#include <add warrens robot model .h file>

class Catologe
{
	public:
	//void add_model(Robot_model model);
	void add_customer(Customer cus);

	private:
	//vector<Robot_model> robot_model;
	vector<Customer> customer;
};

#endif
