#ifndef ROBOT_H
#define ROBOT_H
#include <string>
using namespace std;

class Robot_part{
protected:
    string name;
    int model_number;
    double cost;
    string description;
    string image_filename;
public:
    Robot_part(string _name, int _model_number, double _cost, string _description,
            string _image_filename);
};

class Head : public Robot_part{
private:
    double power;
public:
    Head(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power);
};

class Torso : public Robot_part{
private:
    int battery_compartments;
    int max_arms;
public:
    Torso(string _name, int _model_number, double _cost, string _description,
            string _image_filename, int _battery_compartments, int _max_arms);
};

class Arm : public Robot_part{
private:
    double max_power;
public:
    Arm(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power);
};

class Locomotor : public Robot_part{
private:
    double max_power;
public:
    Locomotor(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power);
};

class Battery : public Robot_part{
private:
    double power_availible;
    double max_energy;
public:
    Battery(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power_availible, double _max_energy);
};

class Robot_model{
private:
    string name;
    int model_number;
    Robot_part torso;
    Robot_part head;
    Robot_part locomotor;
    Robot_part arm;
    Robot_part battery;
public:
    Robot_model(string _name, int _model_number, Robot_part _torso, 
        Robot_part _head, Robot_part _locomotor, Robot_part _arm, Robot_part _battery);
    double cost();
    double max_speed();
    double max_battery_life();
    
};
#endif
