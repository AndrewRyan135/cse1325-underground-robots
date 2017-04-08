#include "store.h"
#include "order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>



Store :: Store(){}

void Store :: save(string filename)
{
    ofstream ofs(filename.c_str());
	catalog.save_catalog(ofs);
    //save_orders(ofs);
    for(int i = 0; i < customers.size(); i++){
        customers.at(i).save_customer(ofs);
    }
    ofs << "-1" << endl;
    for(int i = 0; i < sales_associates.size(); i++){
        sales_associates.at(i).save_sales_associate(ofs);
    }
    ofs << "-1" << endl;
    for(int i = 0; i < orders.size(); i++){
        orders.at(i).save_order(ofs);
    }
    ofs << "-1" << endl;
    ofs.close();
}


void Store :: open(string filename)
{
    string s;
    ifstream ifs(filename.c_str());
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_head(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_torso(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_arm(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_locomotor(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_battery(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_model(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_customer(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_sales_associate(s);
    }
    while(1){
        if(!getline(ifs, s)){
            break;
        }
        if(s == "-1"){
            break;
        }
        open_order(s);
    }

}
void Store :: open_head(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double power = stod(data.at(5));
    Head head(name, model_number, cost, description, image_filename, power);
    catalog.add_head(head);
    data.clear();

}
void Store :: open_torso(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    int battery_compartments = stoi(data.at(5));
    int max_arms = stoi(data.at(6));
    Torso torso(name, model_number, cost, description, image_filename, battery_compartments, max_arms);
    catalog.add_torso(torso);
    data.clear();

}

void Store :: open_arm(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double max_power = stod(data.at(5));
    Arm arm(name, model_number, cost, description, image_filename, max_power);
    catalog.add_arm(arm);
    data.clear();

}

void Store :: open_locomotor(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double max_power = stod(data.at(5));
    Locomotor locomotor(name, model_number, cost, description, image_filename, max_power);
    catalog.add_locomotor(locomotor);
    data.clear();

}

void Store :: open_battery(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double power_avaible = stod(data.at(5));
    double max_energy = stod(data.at(6));
    Battery battery(name, model_number, cost, description, image_filename, power_avaible, max_energy);
    catalog.add_battery(battery);
    data.clear();

}

void Store :: open_model(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double torso_number = stod(data.at(2));
    for(int i = 0; i < catalog.torso_vector_size(); i++){
        if(torso_number == catalog.get_torso(i).get_model_number()){
            torso_number = i;
            break;
        }
    }
    double head_number = stod(data.at(3));
    for(int i = 0; i < catalog.head_vector_size(); i++){
        if(head_number == catalog.get_head(i).get_model_number()){
            head_number = i;
            break;
        }
    }
    double locomotor_number = stod(data.at(4));
    for(int i = 0; i < catalog.locomotor_vector_size(); i++){
        if(locomotor_number == catalog.get_locomotor(i).get_model_number()){
            locomotor_number = i;
            break;
        }
    }
    double arm_number = stod(data.at(5));
    for(int i = 0; i < catalog.arm_vector_size(); i++){
        if(arm_number == catalog.get_arm(i).get_model_number()){
            arm_number = i;
            break;
        }
    }
    double battery_number = stod(data.at(6));
    for(int i = 0; i < catalog.battery_vector_size(); i++){
        if(battery_number == catalog.get_battery(i).get_model_number()){
            battery_number = i;
            break;
        }
    }
    Robot_model robot_model(name, model_number, catalog.get_torso(torso_number), catalog.get_head(head_number),
                             catalog.get_locomotor(locomotor_number), catalog.get_arm(arm_number), catalog.get_battery(battery_number));
    catalog.add_model(robot_model);
    data.clear();

}
void Store :: open_customer(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int number = stoi(data.at(1));
    string phonenumber = data.at(2);
    string email = data.at(3);
    Customer customer(name, number, phonenumber, email);
    add_customer(customer);
    data.clear();
}
void Store :: open_sales_associate(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int number = stoi(data.at(1));
    SalesAssociate sales_associate(name, number);
    add_sales_associate(sales_associate);
    data.clear();
}
void Store :: open_order(string s)
{
    vector <string> data;
    istringstream ss(s);
    while(ss){
        if(!getline(ss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    int order_number = stoi(data.at(0));
    string date = data.at(1);
    int robot_model_number = stoi(data.at(2));
    for(int i = 0; i < catalog.robot_model_vector_size(); i++){
        if(robot_model_number == catalog.get_model(i).get_model_number()){
            robot_model_number = i;
            break;
        }
    }
    int quantity = stoi(data.at(3));
    int customer_number = stoi(data.at(4));
    for(int i = 0; i < customers.size(); i++){
        if(customer_number == customers.at(i).get_customer_number()){
            customer_number = i;
            break;
        }
    }
    int status = stoi(data.at(5));
    int sales_associate_number = stoi(data.at(6));
    for(int i = 0; i < sales_associates.size(); i++){
        if(sales_associate_number == sales_associates.at(i).get_employee_number()){
            sales_associate_number = i;
            break;
        }
    }
    Order order(order_number, date, catalog.get_model(robot_model_number), quantity,
                 customers.at(customer_number), status, sales_associates.at(sales_associate_number));
    add_order(order);
    data.clear();
}

void Store :: add_catalog(Catalog new_catalog)
{
    catalog = new_catalog;
}
void Store :: add_customer(Customer customer)
{
    customers.push_back(customer);
}
void Store :: add_sales_associate(SalesAssociate sales_associate)
{
    sales_associates.push_back(sales_associate);
}
void Store :: add_order(Order order)
{
    orders.push_back(order);
}

Catalog Store :: get_catalog()
{
    return catalog;
}


