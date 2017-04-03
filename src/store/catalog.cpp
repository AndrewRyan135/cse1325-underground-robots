#include "catalog.h"
#include <string>
#include <iostream>
#include <sstream>
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

string Catalog::robot_model_to_string(int model_index)
{
	return robot_model_vector[model_index].to_string();
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

int Catalog::model_vector_size()
{
	return robot_model_vector.size();
}

int Catalog::head_vector_size()
{
	return head_part_vector.size();
}

int Catalog::torso_vector_size()
{
	return torso_part_vector.size();
}

int Catalog::arm_vector_size()
{
	return arm_part_vector.size();
}

int Catalog::locomotor_vector_size()
{
	return locomotor_part_vector.size();
}

int Catalog::battery_vector_size()
{
	return battery_part_vector.size();
}

Robot_model Catalog::get_model(int model_index)
{
	return robot_model_vector[model_index];
}

Head Catalog::get_head(int head_index)
{
	return head_part_vector[head_index];
}

Torso Catalog::get_torso(int torso_index)
{
	return torso_part_vector[torso_index];
}

Arm Catalog::get_arm(int arm_index)
{
	return arm_part_vector[arm_index];
}

Locomotor Catalog::get_locomotor(int locomotor_index)
{
	return locomotor_part_vector[locomotor_index];
}

Battery Catalog::get_battery(int battery_index)
{
	return battery_part_vector[battery_index];
}

string Catalog::catalog_to_string()
{
	stringstream os;
	for (int i = 0; i < head_vector_size(); i++) {
		os << head_to_string(i);
	}
	for (int i = 0; i < torso_vector_size(); i++) {
		os << torso_to_string(i);
	}
	for (int i = 0; i < arm_vector_size(); i++) {
		os << arm_to_string(i);
	}
	for (int i = 0; i < locomotor_vector_size(); i++) {
		os << locomotor_to_string(i);
	}
	for (int i = 0; i < battery_vector_size(); i++) {
		os << battery_to_string(i);
	}
}

void Catalog :: save_catalog(ostream& ofs)
{
	for (int i = 0; i < head_vector_size(); i++) {
		(get_head(i)).save_head(ofs);
		ofs << "-1" << endl;
	}
	for (int i = 0; i < torso_vector_size(); i++) {
		(get_torso(i)).save_torso(ofs);
		ofs << "-1" << endl;
	}
	for (int i = 0; i < arm_vector_size(); i++) {
		(get_arm(i)).save_arm(ofs);
		ofs << "-1" << endl;
	}
	for (int i = 0; i < locomotor_vector_size(); i++) {
		(get_locomotor(i)).save_locomotor(ofs);
		ofs << "-1" << endl;
	}
	for (int i = 0; i < battery_vector_size(); i++) {
		(get_battery(i)).save_battery(ofs);
		ofs << "-1" << endl;
	}
	for (int i = 0; i < model_vector_size(); i++) {
		(get_model(i)).save_robot_model(ofs);
		ofs << "-1" << endl;
	}
}



