#include "catologe.h"

string Catologe::customer_to_string(int customer_number)
{
	return customer[customer_number].to_string();
}

void Catologe::add_customer(Customer cus)
{
	customer_vector.push_back(cus);
}

void Catologe::add_associate(SalesAssociate ass)
{
	associate_vector.push_back(ass);
}
