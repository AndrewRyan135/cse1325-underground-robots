#include "robot.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

Robot_part :: Robot_part(string _name, int _model_number, double _cost, string _description,
            string _image_filename) : name(_name), model_number(_model_number),
                    cost(_cost), description(_description), image_filename(_image_filename){}


//file insertion
void Robot_part :: save_part(ostream& ofs)
{
    ofs << name << endl
    << model_number << endl
    << cost << endl
    << description << endl
    << image_filename << endl;
}

Head :: Head(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power(_power){}
string Head::to_string()
{
    stringstream os;
    os << "Name: " << Robot_part::get_name() << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Power: " << power << "\n";
    return os.str();
}

string Head::name() {return Robot_part::get_name();}

void Head :: save_head(ostream& ofs)
{
    ofs << "1" << endl;
    save_part(ofs);
    ofs << power << endl;
}

Torso :: Torso(string _name, int _model_number, double _cost, string _description,
            string _image_filename, int _battery_compartments, int _max_arms) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms){}
string Torso::to_string()
{
    stringstream os;
    os << "Name: " << Robot_part::get_name() << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Battery Compartments: " << battery_compartments << "\n";
    return os.str();
}

string Torso::name() {return Robot_part::get_name();}

void Torso :: save_torso(ostream& ofs)
{
    ofs << "2" << endl;
    save_part(ofs);
    ofs << battery_compartments << endl
    << max_arms << endl;
}

Arm :: Arm(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), max_power(_max_power){}
string Arm::to_string()
{
    stringstream os;
    os << "Name: " << Robot_part::get_name() << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Max Power: " << max_power << "\n";
    return os.str();
}

string Arm::name() {return Robot_part::get_name();}

void Arm :: save_arm(ostream& ofs)
{
    ofs << "3" << endl;
    save_part(ofs);
    ofs << max_power << endl;
}

Locomotor :: Locomotor(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), max_power(_max_power){}
string Locomotor::to_string()
{
    stringstream os;
    os << "Name: " << Robot_part::get_name() << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Max Power: " << max_power << "\n";
    return os.str();
}

string Locomotor::name() {return Robot_part::get_name();}

void Locomotor :: save_locomotor(ostream& ofs)
{
    ofs << "4" << endl;
    save_part(ofs);
    ofs << max_power << endl;
}

Battery :: Battery(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power_availible, double _max_energy) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power_availible(_power_availible), max_energy(_max_energy){}
string Battery::to_string()
{
    stringstream os;
    os << "Name: " << Robot_part::get_name() << "\n"
       << "Model Number: " << model_number << "\n"
       << "Cost: " << cost << "\n"
       << "Description: " << description << "\n"
       << "Image Filename: " << image_filename << "\n"
       << "Power Available: " << power_availible << "\n"
       << "Max Energy: " << max_energy << "\n";
    return os.str();
}

string Battery::name() {return Robot_part::get_name();}

void Battery :: save_battery(ostream& ofs)
{
    ofs << "5" << endl;
    save_part(ofs);
    ofs << power_availible << endl
    << max_energy << endl;
}

Robot_model :: Robot_model(string _name, int _model_number, Torso _torso,
        Head _head, Locomotor _locomotor, Arm _arm, Battery _battery) :
name(_name), model_number(_model_number), torso(_torso), head(_head), locomotor(_locomotor),
        arm(_arm), battery(_battery){}
string Robot_model::to_string()
{
    stringstream os;
    os << "Name: \t\t\t" << name << "\n"
       << "Model Number: \t\t" << model_number << "\nHead Part Name: \t"
       << head.name() << "\nTorso Part Name: \t" << torso.name() << "\nArm Part Name: \t\t"
       << arm.name() << "\nLocomotor Part Name: \t" << locomotor.name() << "\nBattery Part Name: \t"
       << battery.name() << "\n";
       return os.str();
}

string Robot_model::get_name() {return name;}

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
    ofs << "6" << endl
    << name << endl
    << model_number << endl
    << torso.get_model_number() << endl
    << head.get_model_number() << endl
    << locomotor.get_model_number() << endl
    << arm.get_model_number() << endl
    << battery.get_model_number() << endl;
}

double Robot_model :: max_speed(){}
double Robot_model :: max_battery_life(){}

