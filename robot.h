#ifndef ROBOT_H
#define ROBOT_H
#include <string>
using namespace std;
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
    Robot_model();
    double cost();
    double max_speed();
    double max_battery_life();
    
};

class Robot_part{
protected:
    string name;
    int model_number;
    double cost;
    string description;
    string image_filename;
public:
    Robot_part();

class Head : public Robot_part{
private:
    double power;
public:
    Head();
};

class Torso : public Robot_part{
private:
    int battery_compartments;
    int max_arms;
public:
    Torso();
};

class Arm : public Robot_part{
private:
    double max_power;
public:
    Arm();
};

class Locomotor : public Robot_part{
private:
    double max_power;
public:
    Locomotor();
};

class Battery : public Robot_part{
private:
    double power_availible;
    double max_energy;
public:
    Battery();
};
#endif