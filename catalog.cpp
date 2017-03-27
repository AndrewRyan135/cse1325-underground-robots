#include "catalog.h"

void Catalog::add_model(Robot_model model)
{
	robot_model_vector.push_back(model);
}

void Catalog::add_part(Robot_part part)
{
	robot_part_vector.push_back(part);
}

string Catalog::part_to_string(int index)
{
	return robot_part_vector[index].to_string();
}
int Catalog::part_vector_size()
{
	return robot_part_vector.size();
}

string Catalog::customer_to_string(int customer_number)
{
	return customer_vector[customer_number].to_string();
}

void Catalog::add_customer(Customer cus)
{
	customer_vector.push_back(cus);
}

void Catalog::add_associate(SalesAssociate ass)
{
	associate_vector.push_back(ass);
}
