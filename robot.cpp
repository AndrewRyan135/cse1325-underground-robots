#include "robot.h"
#include <string>
#include <iostream>
#include <sstream>

Robot_part :: Robot_part(string _name, int _model_number, double _cost, string _description,
            string _image_filename) : name(_name), model_number(_model_number),
                    cost(_cost), description(_description), image_filename(_image_filename){}

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

Battery :: Battery(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power_availible, double _max_energy) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power_availible(_power_availible), max_energy(_max_energy){}
string Head::to_string()
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

Robot_model :: Robot_model(string _name, int _model_number, Robot_part _torso, 
        Robot_part _head, Robot_part _locomotor, Robot_part _arm, Robot_part _battery) : 
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
double Robot_model :: cost(){}
double Robot_model :: max_speed(){}
double Robot_model :: max_battery_life(){}
