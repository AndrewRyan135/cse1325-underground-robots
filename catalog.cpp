#include "catalog.h"

string Catalog::customer_to_string(int customer_number)
{
	//return customer[customer_number].to_string();
}

void Catalog::add_customer(Customer cus)
{
	customer_vector.push_back(cus);
}

void Catalog::add_associate(SalesAssociate ass)
{
	associate_vector.push_back(ass);
}
