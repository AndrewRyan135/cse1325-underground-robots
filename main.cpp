#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include "catalog.h"
#include "customer.h"
#include "robot.h"
#include "sales_associate.h"
using namespace std;

Catalog catologe;

void create_part();
int int_validation(int input);
double double_validation(double input);
void part_picker();

class View
{
	public :
	string get_menu()
	{
		stringstream os;
		os << "========================\n"
		   << "Robbie Robot Shop System\n"
		   << "========================"
		   << "\n"
		   << "\n1. Customer"
		   << "\n2. Sales Associate"
		   << "\n3. Product Manager"
		   << "\n4. Boss"
		   << "\n5. Exit";
		return os.str();
	}
	void show_parts_list()
	{
		int i = 0;
		cout << "Head: " << endl;
		for (i = 0; i < catologe.head_vector_size(); i++)
		{
			cout << "Part Number: " << i << " " << catologe.head_to_string(i) << endl;
		}
		cout << "\nTorso: " << endl;
		for (i = 0; i < catologe.torso_vector_size(); i++)
		{
			cout << "Part Number: " << i << " " << catologe.torso_to_string(i) << endl;
		}
		cout << "\nArm: " << endl;
		for (i = 0; i < catologe.arm_vector_size(); i++)
		{
			cout << "Part Number: " << i << " " << catologe.arm_to_string(i) << endl;
		}
		cout << "\nLocomotor: " << endl;
		for (i = 0; i < catologe.locomotor_vector_size(); i++)
		{
			cout << "Part Number: " << i << " " << catologe.locomotor_to_string(i) << endl;
		}
		cout << "\nBattery: " << endl;
		for (i = 0; i < catologe.battery_vector_size(); i++)
		{
			cout << "Part Number: " << i << " " << catologe.battery_to_string(i) << endl;
		}
		part_picker();
	}
	void show_catalog()
	{
		for (int i = 0; i < catologe.model_vector_size(); i++)
		{
			cout << catologe.robot_model_to_string(i) << endl;
		}
	}
};

View view;
//==================================
//           CONTROLLER
//==================================
class Controller
{
	public :
		void menu_choice(int cmd)
		{
			cmd = int_validation(cmd);
			switch(cmd) {
			case 1 :  cout << "\t\tBrowse robot cataloge\n" << endl; 
					  view.show_catalog();
					  break;
			case 2 :  cout << "To be finish in later sprint\n" << endl; 
					  break;
			case 3 : cout << "1. Create robot part" << endl
					      << "2. Create new robot model" << endl; 
					 cin >> cmd;
				     if (cmd == 1)
				     {
				     	create_part();
				     }
				     else if (cmd == 2)
				     {
				     	view.show_parts_list();
				     }
				     break;
			case 4 : cout << "1. Create new customer" << endl
				          << "2. Create new sales associate" << endl;
					 cin >> cmd;
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
					     catologe.add_customer(customer);
				     }
				     else if (cmd == 2)
				     {
				 	     string name;
				 	     int employee_number;
				 	     cout << "Enter the employee's name: " << endl;
				 	     cin >> name;
				 	     cout << "Enter the employee's employee number: " << endl;
				 	     cin >> employee_number;

				 	     SalesAssociate associate(name,employee_number);
				 	     catologe.add_associate(associate);
				     }
				     break;
			case 5 : exit(0);
			default : {}
			}
	       }

		private :
		int cmd, flag;
};

int main()
{
	while (true)
	{
	int cmd = 0;
	Controller controller;
	cout << view.get_menu() << endl;
	controller.menu_choice(cmd);
	}
}

void part_picker()
{
	string name;
	int model_number;
	int head, torso, arm, locomotor, battery;
	cout << "Enter your head selection: " << endl;
	cin >> head;
	cout << "Enter your torso selection: " << endl;
	cin >> torso;
	cout << "Enter your arm selection: " << endl;
	cin >> arm;
	cout << "Enter your locomotor selection: " << endl;
	cin >> locomotor;
	cout << "Enter your battery selection: " << endl;
	cin >> battery;
	//switch(index) {
	//	case 1 : head = catologe.get_head(choice - 1);
	//			 break;
	//	case 2 : torso = catologe.get_torso(choice - 1);
	//			 break;
	//	case 3 : arm = catologe.get_arm(choice - 1);
	//			 break;
	//	case 4 : locomotor = catologe.get_locomotor(choice - 1);
	//			 break;
	//	case 5 : battery = catologe.get_battery(choice - 1);
	//			 break;
	//	default: {}
	//}
	cout << "Please enter the robots name" << endl;
	cin >> name;
	cout << "Please enter the model number" << endl;
	cin >> model_number;
	Robot_model model(name, model_number, catologe.get_torso(torso), catologe.get_head(head), catologe.get_locomotor(locomotor), catologe.get_arm(arm), catologe.get_battery(battery));
	catologe.add_model(model);
}

int int_validation(int input)
{
	int flag = 1;
	while (flag == 1)
	{
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid input: Please re enter: " << endl;
			continue;
		}
	    flag = 0;
	}
	return input;
}

double double_validation(double input)
{
	int flag = 1;
	while (flag == 1)
	{
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid input: Please re enter: " << endl;
			continue;
		}
	    flag = 0;
	}
	return input;
}

void create_part()
{
	int cmd, _model_number, _battery_compartments, _max_arms;
	int flag = 1;
	string _name, _description, _image_file;
	double _cost, _power, _max_power, _power_available, _max_energy;
	bool valid = false;
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
				 cin.ignore();
				 getline(cin,_name);
				 cout << "Enter the model number: " << endl;
				 _model_number = int_validation(_model_number);
				 cout << "Enter the cost of the part: " << endl;
				 _cost = int_validation(_cost);
				 cout << "Enter the part description: " << endl;
				 cin.ignore();
				 getline(cin,_description);
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the part power: " << endl;
				 _power = double_validation(_power);
				 Head head(_name,_model_number,_cost,_description,_image_file,_power);
				 catologe.add_head(head);
				 break;}
		case 2 : {cout << "Enter the part name: " << endl;
				 cin.ignore();
				 getline(cin,_name);
				 cout << "Enter the model number: " << endl;
				 _model_number = int_validation(_model_number);
				 cout << "Enter the cost of the part: " << endl;
				 _cost = int_validation(_cost);
				 cout << "Enter the part description: " << endl;
				 cin.ignore();
				 getline(cin,_description);
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file; 
				 cout << "Enter the number of battery compartments: " << endl;
				 _battery_compartments = int_validation(_battery_compartments);
				 cout << "Enter the number of arms: " << endl;
				 _max_arms = int_validation(_max_arms);
				 Torso torso(_name,_model_number,_cost,_description,_image_file,_battery_compartments,_max_arms);
				 catologe.add_torso(torso);
				 break;}
		case 3 : {cout << "Enter the part name: " << endl;
				 cin.ignore();
				 getline(cin,_name);
				 cout << "Enter the model number: " << endl;
				 _model_number = int_validation(_model_number);
				 cout << "Enter the cost of the part: " << endl;
				 _cost = int_validation(_cost);
				 cout << "Enter the part description: " << endl;
				 cin.ignore();
				 getline(cin,_description);
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the max power of the arm: " << endl;
				 _max_power = double_validation(_max_power);
				 Arm arm(_name,_model_number,_cost,_description,_image_file,_max_power);
				 catologe.add_arm(arm);
				 break;}
		case 4 : {cout << "Enter the part name: " << endl;
				 cin.ignore();
				 getline(cin,_name);
				 cout << "Enter the model number: " << endl;
				 _model_number = int_validation(_model_number);
				 cout << "Enter the cost of the part: " << endl;
				 _cost = int_validation(_cost);
				 cout << "Enter the part description: " << endl;
				 cin.ignore();
				 getline(cin,_description);
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the max power of the locomotor: " << endl;
				 _max_power = double_validation(_max_power);
				 Locomotor locomotor(_name,_model_number,_cost,_description,_image_file,_max_power);
				 catologe.add_locomotor(locomotor);
				 break;}
		case 5 : {cout << "Enter the part name: " << endl;
				 cin.ignore();
				 getline(cin,_name);
				 cout << "Enter the model number: " << endl;
				 _model_number = int_validation(_model_number);
				 cout << "Enter the cost of the part: " << endl;
				 _cost = int_validation(_cost);
				 cout << "Enter the part description: " << endl;
				 cin.ignore();
				 getline(cin,_description);
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the power available" << endl;
				  _power_available = double_validation(_power_available);
				 cout << "Enter the max energy: " << endl;
				 _max_energy = double_validation(_max_energy);
				 Battery battery(_name,_model_number,_cost,_description,_image_file,_power_available,_max_energy);
				 catologe.add_battery(battery);
				 break;}
		default : {}
	}
}