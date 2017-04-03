#include "store.h"
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
    ofs.close();
}


void Store :: open(string filename)
{
    ifstream ifs(filename.c_str());
    string s;
    vector <string> data;
    //open heads
    while(1){
        if(!getline(ifs, s)){
        break;
        }
        if(s == "-1"){
            break;
        }
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

}

void Store :: open_arm(istream& ifs)
{
    string name;
    int model_number;
    double cost;
    string description;
    string image_filename;
    double max_power;
    //This doesnt work, but this is the idea
    //ifs >> name >> model_number >> cost >> image_filename >> max_power >> endl;
    Arm arm(name, model_number, cost, description, image_filename, max_power);
    catalog.add_arm(arm);
}


void Store :: add_catalog(Catalog new_catalog)
{
    catalog = new_catalog;
}


