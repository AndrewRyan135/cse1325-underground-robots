#include "robot.h"

Robot_model :: Robot_model(string _name, int _model_number, Robot_part _torso, 
        Robot_part _head, Robot_part _locomotor, Robot_part _arm, Robot_part _battery) : 
name(_name), model_number(_model_number), torso(_torso), head(_head), locomotor(_locomotor),
        arm(_arm), battery(_battery){}
double Robot_model :: cost(){}
double Robot_model :: max_speed(){}
double Robot_model :: max_battery_life(){}

Robot_part :: Robot_part(string _name, int _model_number, double _cost, string _description,
            string _image_filename) : name(_name), model_number(_model_number),
                    cost(_cost), description(_description), image_filename(_image_filename){}

Head :: Head(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power(_power){}

Torso :: Torso(string _name, int _model_number, double _cost, string _description,
            string _image_filename, int _battery_compartments, int _max_arms) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms){}

Arm :: Arm(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), max_power(_max_power){}

Locomotor :: Locomotor(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), max_power(_max_power){}

Battery :: Battery(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power_availible, double _max_energy) : Robot_part(_name, _model_number,
                    _cost, _description, _image_filename), power_availible(_power_availible), max_energy(_max_energy){}
