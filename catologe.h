#ifndef CATOLOGE_H
#define CATOLOGE_H
#include <vector>
#include "customer.h"
#include "sales_associate.h"
//#include "robot.h"
//#include <add warrens robot model .h file>
//using namespace std;
class Catologe
{
	public:
	//void add_model(Robot_model model);
	void add_customer(Customer cus);
	void add_assocaite(SalesAssociate ass);
	string customer_to_string(int customer_number);
	private:
	//vector<Robot_model> robot_model;
	vector<Customer> customer_vector;
	vector<SalesAssociate> associate_vector;
};

#endif
