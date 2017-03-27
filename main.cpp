#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "catologe.h"
#include "customer.h"
#include "robot.h"
using namespace std;

Catologe catologe;

void create_part();

class View
{
	public :
	string get_menu()
	{
		stringstream os;
		os << "========================"
		   << "Robbie Robot Shop System"
		   << "========================"
		   << "\n"
		   << "\n1. Customer"
		   << "\n2. Sales Associate"
		   << "\n3. Product Manager"
		   << "\n4. Boss";
		return os.str();
	}
	void menu_choice(int cmd)
	{
		switch(cmd) {
			case 1 : cout << "Browse robot cataloge" << endl; break;
			case 2 : cout << "To be finish in later sprint" << endl; break;
			case 3 : cout << "1. Create robot part" << endl
					      << "2. Create new robot model" << endl; break;
			case 4 : cout << "1. Create new customer" << endl
				          << "2. Create new sales associate" << endl; break;
			default : cout << "Invalid Input" << endl; 
		}
	}
	string show_cataloge()
	{
		//print out the vector
	}
};

class Controller
{
	public :
		void menu_choice(int cmd)
		{
			cin >> cmd;
			switch(cmd) {
			case 1 : //call to print out cataloge 
			case 2 : 
			case 3 : cin >> cmd;
				     if (cmd == 1)
				     {
				 	 	create_part();
				     }
				     else if (cmd == 2)
				     {
				 	 	//new robot model
				     }
				     break;
			case 4 : cin >> cmd;
				     if (cmd == 1)
				     {
					     string name, phone_number, email;
					     int number;
					     cout << "Enter the customer's name: " << endl;
					     cin >> name;
					     cout << "Enter the customer's number: " << endl;
					     cin >> number;
					     cout << "Enter the customer's phone number: " << endl;
					     cin >> phone_number;
					     cout << "Enter the customer's email: " << endl;
					     cin >> email;
					     
					     Customer customer(name, number, phone_number, email);
					     cout << customer.to_string() << endl;
					     //catologe.add_customer(customer);
				 	     //new customer
				     }
				     else if (cmd == 2)
				     {
				 	     //new sales associate
				     }
			default : {}
			}
	       }

		private :
		int cmd;
};

int main()
{
	int cmd = 0;
	View view;
	Controller controller;
	cout << view.get_menu() << endl;
	cin >> cmd;
	view.menu_choice(cmd);
	controller.menu_choice(cmd);
}

void create_part()
{
	int cmd, _model_number, _battery_compartments, _max_arms;
	string _name, _description, _image_file;
	double _cost, _power, _max_power, _power_available, _max_energy;
	stringstream os;
	os << "1. Head" << "\n"
	   << "2. Torso" << "\n"
	   << "3. Arm" << "\n"
	   << "4. Locomotor" << "\n"
	   << "5. Battery";
	cout << os.str() << endl;
	cin >> cmd;
	switch(cmd) {
		case 1 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 cin >> _model_number;
				 cout << "Enter the cost of the part: " << endl;
				 cin >> _cost;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the mage file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the part power: " << endl;
				 cin >> _power;
				 Head stuff(_name,_model_number,_cost,_description,_image_file,_power);
				 break;}
		case 2 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 cin >> _model_number;
				 cout << "Enter the cost of the part: " << endl;
				 cin >> _cost;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the mage file name: " << endl;
				 cin >> _image_file; 
				 cout << "Enter the number of battery compartments: " << endl;
				 cin >> _battery_compartments;
				 cout << "Enter the number of arms: " << endl;
				 cin >> _max_arms;
				 Torso stuff2(_name,_model_number,_cost,_description,_image_file,_battery_compartments,_max_arms);
				 break;}
		case 3 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 cin >> _model_number;
				 cout << "Enter the cost of the part: " << endl;
				 cin >> _cost;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the mage file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the max power of the arm: " << endl;
				 cin >> _max_power;
				 Arm stuff3(_name,_model_number,_cost,_description,_image_file,_max_power);
				 break;}
		case 4 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 cin >> _model_number;
				 cout << "Enter the cost of the part: " << endl;
				 cin >> _cost;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the mage file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the max power of the locomotor: " << endl;
				 cin >> _max_power;
				 Locomotor stuff4(_name,_model_number,_cost,_description,_image_file,_max_power);
				 break;}
		case 5 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 cin >> _model_number;
				 cout << "Enter the cost of the part: " << endl;
				 cin >> _cost;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the mage file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the power available" << endl;
				 cin >> _power_available;
				 cout << "Enter the max enery: " << endl;
				 cin >> _max_energy;
				 Battery stuff5(_name,_model_number,_cost,_description,_image_file,_power_available,_max_energy);
				 break;}
		default : {}
}