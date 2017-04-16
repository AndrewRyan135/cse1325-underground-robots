#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include <fstream>
#include <iostream>
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
    string get_name(){return name;};
    int get_model_number(){return model_number;};
    double get_cost(){return cost;};
    string get_description(){return description;};
    string get_image_filename(){return image_filename;};
    void save_part(ostream& ofs);
};

class Head : public Robot_part{
private:
    double power;
public:
    Head(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power);
    string to_string();
    double get_power(){return power;};
    void save_head(ostream& ofs);
};

class Torso : public Robot_part{
private:
    int battery_compartments;
    int max_arms;
public:
    Torso(string _name, int _model_number, double _cost, string _description,
            string _image_filename, int _battery_compartments, int _max_arms);
    string to_string();
    int get_battery_compartments(){return battery_compartments;};
    int get_max_arms(){return max_arms;};
    void save_torso(ostream& ofs);
};

class Arm : public Robot_part{
private:
    double max_power;
public:
    Arm(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power);
    string to_string();
    double get_max_power(){return max_power;};
    void save_arm(ostream& ofs);
};

class Locomotor : public Robot_part{
private:
    double max_power;
public:
    Locomotor(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _max_power);
    string to_string();
    double get_max_power(){return max_power;};
    void save_locomotor(ostream& ofs);
};

class Battery : public Robot_part{
private:
    double power_availible;
    double max_energy;
public:
    Battery(string _name, int _model_number, double _cost, string _description,
            string _image_filename, double _power_availible, double _max_energy);
    string to_string();
    double get_power_availible(){return power_availible;};
    double get_max_energy(){return max_energy;};
    void save_battery(ostream& ofs);
};

class Robot_model{
private:
    string name;
    int model_number;
    Torso torso;
    Head head;
    Locomotor locomotor;
    Arm arm;
    Battery battery;
public:
    Robot_model(string _name, int _model_number, Torso _torso,
        Head _head, Locomotor _locomotor, Arm _arm, Battery _battery);
    string to_string();
    double cost();
    double max_speed();
    double max_battery_life();
    void save_robot_model(ostream& ofs);
    int get_model_number(){return model_number;};

};
#endif
