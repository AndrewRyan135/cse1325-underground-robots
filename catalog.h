#ifndef CATALOG_H
#define CATALOG_H
#include <vector>
#include "customer.h"
#include "sales_associate.h"
#include "robot.h"
using namespace std;

class Catalog
{
	public:
	void add_model(Robot_model model);
	void add_customer(Customer cus);
	void add_associate(SalesAssociate ass);
	string customer_to_string(int customer_number);
	private:
	vector<Robot_model> robot_model_vector;
	vector<Customer> customer_vector;
	vector<SalesAssociate> associate_vector;
};

#endif
