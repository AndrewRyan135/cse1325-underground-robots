#include "catologe.h"

string Catologe::customer_to_string()
{
	return customer[customer_number].to_string();
}

void Catologe::add_customer(Customer cus)
{
	customer.push_back(cus);
}
