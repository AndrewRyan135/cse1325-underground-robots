#include "robot.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

Robot_part :: Robot_part(string _name, int _model_number, double _cost, string _description,
            string _image_filename) : name(_name), model_number(_model_number),
                    cost(_cost), description(_description), image_filename(_image_filename){}

//double Robot_part::get_cost()
//{
//	return cost;
//}
//getters
string Robot_part :: get_name()
{
    return name;
}
int Robot_part :: get_model_number()
{
    return model_number;
}
double Robot_part :: get_cost()
{
    return cost;
}
string Robot_part :: get_description()
{
    return description;
}
string Robot_part :: get_image_filename()
{
    return image_filename;
}
//file insertion
void Robot_part :: save_part(ostream& ofs)
{
    ofs << name << "," << model_number << "," << cost << "," << description << "," << image_filename << ",";
}

Head :: Head(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power(_power){}
string Head::to_string()
{
    stringstream os;
    os << "Name: " << name << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Power: " << power << "\n";
    return os.str();
}

double Head::get_power()
{
    return power;
}

void Head :: save_head(ostream& ofs)
{
    save_part(ofs);
    ofs << power << endl;
}

Torso :: Torso(string _name, int _model_number, double _cost, string _description,
            string _image_filename, int _battery_compartments, int _max_arms) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms){}
string Torso::to_string()
{
    stringstream os;
    os << "Name: " << name << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Battery Compartments: " << battery_compartments << "\n";
    return os.str();
}

int Torso :: get_battery_compartments()
{
    return battery_compartments;
}
int Torso :: get_max_arms()
{
    return max_arms;
}

void Torso :: save_torso(ostream& ofs)
{
    save_part(ofs);
    ofs << battery_compartments << "," << max_arms << endl;
}

Arm :: Arm(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), max_power(_max_power){}
string Arm::to_string()
{
    stringstream os;
    os << "Name: " << name << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Max Power: " << max_power << "\n";
    return os.str();
}

double Arm :: get_max_power()
{
    return max_power;
}

void Arm :: save_arm(ostream& ofs)
{
    save_part(ofs);
    ofs << max_power << endl;
}

Locomotor :: Locomotor(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), max_power(_max_power){}
string Locomotor::to_string()
{
    stringstream os;
    os << "Name: " << name << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Max Power: " << max_power << "\n";
    return os.str();
}

double Locomotor :: get_max_power()
{
    return max_power;
}

void Locomotor :: save_locomotor(ostream& ofs)
{
    save_part(ofs);
    ofs << max_power << endl;
}

Battery :: Battery(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power_availible, double _max_energy) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power_availible(_power_availible), max_energy(_max_energy){}
string Battery::to_string()
{
    stringstream os;
    os << "Name: " << name << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Power Available: " << power_availible << "\n"
       << "Max Energy: " << max_energy << "\n";
    return os.str();
}

double Battery :: get_power_availible()
{
    return power_availible;
}
double Battery :: get_max_energy()
{
    return max_energy;
}

void Battery :: save_battery(ostream& ofs)
{
    save_part(ofs);
    ofs << power_availible << "," << max_energy << endl;
}

Robot_model :: Robot_model(string _name, int _model_number, Torso _torso,
        Head _head, Locomotor _locomotor, Arm _arm, Battery _battery) :
name(_name), model_number(_model_number), torso(_torso), head(_head), locomotor(_locomotor),
        arm(_arm), battery(_battery){}
string Robot_model::to_string()
{
    stringstream os;
    os << "Name: " << name << "\n"
       << "Model Number: " << model_number << "\n"
       << torso.to_string() << "\n" << head.to_string() << "\n"
       << locomotor.to_string() << "\n" << arm.to_string() << "\n"
       << battery.to_string() << "\n";
       return os.str();
}

double Robot_model :: cost()
{
	double total = 0;
	total += head.get_cost();
	total += torso.get_cost();
	total += arm.get_cost();
	total += locomotor.get_cost();
	total += battery.get_cost();
	return total;
}

void Robot_model :: save_robot_model(ostream& ofs)
{
    ofs << name << "," << model_number << "," << torso.get_model_number() << "," <<
        head.get_model_number() << "," << locomotor.get_model_number() << "," << arm.get_model_number() <<
        "," << battery.get_model_number() << endl;
}

double Robot_model :: max_speed(){}
double Robot_model :: max_battery_life(){}
int Robot_model :: get_model_number()
{
    return model_number;
}
