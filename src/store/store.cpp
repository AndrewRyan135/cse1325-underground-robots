#include "store.h"
#include "utility.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>



Store :: Store() : catalog(){}

void Store :: save(string filename)
{
    ofstream ofs(filename.c_str());
	catalog.save_catalog(ofs);
    for(int i = 0; i < customers.size(); i++){
        customers.at(i).save_customer(ofs);
    }
    for(int i = 0; i < sales_associates.size(); i++){
        sales_associates.at(i).save_sales_associate(ofs);
    }
    for(int i = 0; i < orders.size(); i++){
        orders.at(i).save_order(ofs);
    }
    ofs << "0" << endl;
    ofs.close();
}


void Store :: open(string filename)
{
    Head *head;
    Arm *arm;
    Torso *torso;
    Locomotor *locomotor;
    Battery *battery;
    Robot_model *robot_model;
    Customer *customer;
    Sales_associate *sales_associate;
    Order *order;
    ifstream ifs(filename.c_str());
    while(!ifs.eof()){
        switch(get_int(ifs))
        {
            case 0:
                {
                    return;
                }
            case 1:
                {
                    head = new Head(
                                    get_string(ifs),
                                    get_int(ifs),
                                    get_double(ifs),
                                    get_string(ifs),
                                    get_string(ifs),
                                    get_double(ifs)
                                );
                    catalog.add_head(*head);
                    break;
                }
            case 2:
                {
                    torso = new Torso(
                                    get_string(ifs),
                                    get_int(ifs),
                                    get_double(ifs),
                                    get_string(ifs),
                                    get_string(ifs),
                                    get_int(ifs),
                                    get_int(ifs)
                                );
                    catalog.add_torso(*torso);
                    break;
                }
            case 3:
                {
                    arm = new Arm(
                                get_string(ifs),
                                get_int(ifs),
                                get_double(ifs),
                                get_string(ifs),
                                get_string(ifs),
                                get_double(ifs)
                            );
                    catalog.add_arm(*arm);
                    break;
                }
            case 4:
                {
                    locomotor = new Locomotor(
                                get_string(ifs),
                                get_int(ifs),
                                get_double(ifs),
                                get_string(ifs),
                                get_string(ifs),
                                get_double(ifs)
                            );
                    catalog.add_locomotor(*locomotor);
                    break;
                }
            case 5:
                {
                    battery = new Battery(get_string(ifs),
                                get_int(ifs),
                                get_double(ifs),
                                get_string(ifs),
                                get_string(ifs),
                                get_double(ifs),
                                get_double(ifs)
                            );
                    catalog.add_battery(*battery);
                    break;
                }
            case 6:
                {
                    string name = get_string(ifs);
                    int model_number = get_int(ifs);
                    int torso_number = get_int(ifs);
                    int head_number = get_int(ifs);
                    int locomotor_number = get_int(ifs);
                    int arm_number = get_int(ifs);
                    int battery_number = get_int(ifs);
                    for(int i = 0; i < catalog.torso_vector_size(); i++){
                        if(torso_number == catalog.get_torso(i)->get_model_number()){
                            torso = catalog.get_torso(i);
                            break;
                        }
                    }
                    for(int i = 0; i < catalog.head_vector_size(); i++){
                        if(head_number == catalog.get_head(i)->get_model_number()){
                            head = catalog.get_head(i);
                            break;
                        }
                    }
                    for(int i = 0; i < catalog.locomotor_vector_size(); i++){
                        if(locomotor_number == catalog.get_locomotor(i)->get_model_number()){
                            locomotor = catalog.get_locomotor(i);
                            break;
                        }
                    }
                    for(int i = 0; i < catalog.arm_vector_size(); i++){
                        if(arm_number == catalog.get_arm(i)->get_model_number()){
                            arm = catalog.get_arm(i);
                            break;
                        }
                    }
                    for(int i = 0; i < catalog.battery_vector_size(); i++){
                        if(battery_number == catalog.get_battery(i)->get_model_number()){
                            battery = catalog.get_battery(i);
                            break;
                        }
                    }
                    robot_model = new Robot_model(name, model_number, *torso, *head, *locomotor, *arm, *battery);
                    catalog.add_model(*robot_model);
                }
            case 7:
                {
                    customer = new Customer(
                        get_string(ifs),
                        get_int(ifs),
                        get_string(ifs),
                        get_string(ifs)
                    );
                    add_customer(*customer);
                    break;
                }
            case 8:
                {
                    sales_associate = new Sales_associate(get_string(ifs), get_int(ifs));
                    add_sales_associate(*sales_associate);
                    break;
                }
            case 9:
                {
                    int order_number = get_int(ifs);
                    string date = get_string(ifs);
                    int robot_model_number = get_int(ifs);
                    for(int i = 0; i < catalog.robot_model_vector_size(); i++){
                        if(robot_model_number == catalog.get_model(i)->get_model_number()){
                            robot_model = catalog.get_model(i);
                            break;
                        }
                    }
                    int quantity = get_int(ifs);
                    int customer_number = get_int(ifs);
                    for(int i = 0; i < customers.size(); i++){
                        if(customer_number == customers.at(i).get_customer_number()){
                        customer = &(customers.at(i));
                        break;
                        }
                    }
                    int status = get_int(ifs);
                    int sales_associate_number = get_int(ifs);
                    for(int i = 0; i < sales_associates.size(); i++){
                        if(sales_associate_number == sales_associates.at(i).get_employee_number()){
                        sales_associate = &(sales_associates.at(i));
                        break;
                        }
                    }
                    order = new Order(order_number, date, *robot_model, quantity, *customer, status, *sales_associate);
                    add_order(*order);
                }
            //default:
               // {
                   // cerr << "Incorrect input obtained while reading file." << endl;
                   // exit(0);
               // }
        }
    }

}


void Store :: add_catalog(Catalog new_catalog)
{
    catalog = new_catalog;
}
void Store :: add_customer(Customer customer)
{
    customers.push_back(customer);
}
void Store :: add_sales_associate(Sales_associate sales_associate)
{
    sales_associates.push_back(sales_associate);
}
void Store :: add_order(Order order)
{
    orders.push_back(order);
}

int Store::order_vector_size()
{
	return orders.size();
}

int Store::customers_size()
{
	return customers.size();
}

int Store::sales_associates_size()
{
	return sales_associates.size();
}

string Store::order_to_string(int index)
{
	return orders[index].to_string();
}

string Store::customer_to_string(int index)
{
    return customers[index].to_string();
}

string Store::sales_associates_to_string(int index)
{
    return sales_associates[index].to_string();
}

Customer* Store::get_customer(int index)
{
	return &customers[index];
}

Sales_associate* Store::get_associate(int index)
{
	return &sales_associates[index];
}

Catalog* Store :: get_catalog()
{
    return &catalog;
}


