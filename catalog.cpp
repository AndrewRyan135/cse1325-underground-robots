#include "catalog.h"

void Catalog::add_model(Robot_model model)
{
	robot_model_vector.push_back(model);
}

void Catalog::add_head(Head head)
{
	head_part_vector.push_back(head);
}

void Catalog::add_torso(Torso torso)
{
	torso_part_vector.push_back(torso);
}

void Catalog::add_arm(Arm arm)
{
	arm_part_vector.push_back(arm);
}

void Catalog::add_locomotor(Locomotor locomotor)
{
	locomotor_part_vector.push_back(locomotor);
}

void Catalog::add_battery(Battery battery)
{
	battery_part_vector.push_back(battery);
}

void Catalog::add_customer(Customer cus)
{
	customer_vector.push_back(cus);
}

void Catalog::add_associate(SalesAssociate ass)
{
	associate_vector.push_back(ass);
}

string Catalog::customer_to_string(int customer_number)
{
	return customer_vector[customer_number].to_string();
}

string Catalog::head_to_string(int head_index)
{
	return head_part_vector[head_index].to_string();
}

string Catalog::torso_to_string(int torso_index)
{
	return torso_part_vector[torso_index].to_string();
}

string Catalog::arm_to_string(int arm_index)
{
	return arm_part_vector[arm_index].to_string();
}

string Catalog::locomotor_to_string(int locomotor_index)
{
	return locomotor_part_vector[locomotor_index].to_string();
}

string Catalog::battery_to_string(int battery_index)
{
	return battery_part_vector[battery_index].to_string();
}

int model_vector_size()
{
	return robot_model_vector.size();
}

int head_vector_size()
{
	return head_part_vector.size();
}

int torso_vector_size()
{
	return torso_part_vector.size();
}

int arm_vector_size()
{
	return arm_part_vector.size();
}

int locomotor_vector_size()
{
	return locomotor_part_vector.size();
}

int battery_vector_size()
{
	return battery_part_vector.size();
}




