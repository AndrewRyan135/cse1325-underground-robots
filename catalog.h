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
	void add_part(Robot_part part);
	void add_customer(Customer cus);
	void add_associate(SalesAssociate ass);
	int part_vector_size();
	string part_to_string(int index);
	string customer_to_string(int customer_number);
	private:
	vector<Robot_model> robot_model_vector;
	vector<Robot_part> robot_part_vector;
	vector<Customer> customer_vector;
	vector<SalesAssociate> associate_vector;
};

#endif
