#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include "catalog.h"
#include "customer.h"
#include "robot.h"
using namespace std;

Catalog catologe;

void create_part();

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
			flag = 1;
			while (flag == 1)
			{
				cin >> cmd;
				if (cin.fail())
				{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Invalid input: Please re enter: " << endl;
				continue;
				}
			flag = 0;
			}
			
			switch(cmd) {
			case 1 :  cout << "Browse robot cataloge\n" << endl; 
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
				     	//create_model
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
	View view;
	Controller controller;
	cout << view.get_menu() << endl;
	controller.menu_choice(cmd);
	}
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
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 while (flag == 1)
				 {
				   cin >> _model_number;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the cost of the part: " << endl;
				 while (flag == 1)
				 {
				   cin >> _cost;
				   if (cin.fail())
				   {
				    	cin.clear();
				    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				    	cout << "Invalid input: Pease re enter: " << endl;
				    	continue;
				   }
				 flag = 0;
				 }
				 flag = 1;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the part power: " << endl;
				 while (flag == 1)
				 {
				   cin >> _power;
				   if (cin.fail())
				   {
				   		cin.clear();
				    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				    	cout << "Invalid input: Pease re enter: " << endl;
				    	continue;
				   }
				 flag = 0;
				 }
				 flag = 1;
				 Head head(_name,_model_number,_cost,_description,_image_file,_power);
				 catologe.add_part(head);
				 break;}
		case 2 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 while (flag == 1)
				 {
				   cin >> _model_number;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the cost of the part: " << endl;
				 while (flag == 1)
				 {
				   cin >> _cost;
				   if (cin.fail())
				   {
				    	cin.clear();
				    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				    	cout << "Invalid input: Pease re enter: " << endl;
				    	continue;
				   }
				 flag = 0;
				 }
				 flag = 1;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file; 
				 cout << "Enter the number of battery compartments: " << endl;
				 while (flag == 1)
				 {
				   cin >> _battery_compartments;
				   if (cin.fail())
				   {
				   		cin.clear();
				   		cin.ignore(numeric_limits<streamsize>::max(),'\n');
				   		cout << "Invalid input: Please re enter: " <<endl;
				   		continue;
				   }
				 flag = 0;
				 }
				 flag = 1;
				 cout << "Enter the number of arms: " << endl;
				 while (flag == 1)
				 {
				   cin >> _max_arms;
				   if (cin.fail())
				   {
				   		cin.clear();
				   		cin.ignore(numeric_limits<streamsize>::max(),'\n');
				   		cout << "Invalid input: Please re enter: " <<endl;
				   		continue;
				   }
				 flag = 0;
				 }
				 flag = 1;
				 Torso torso(_name,_model_number,_cost,_description,_image_file,_battery_compartments,_max_arms);
				 catologe.add_part(torso);
				 break;}
		case 3 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 while (flag == 1)
				 {
				   cin >> _model_number;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the cost of the part: " << endl;
				 while (flag == 1)
				 {
				   cin >> _cost;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the max power of the arm: " << endl;
				 while (flag == 1)
				 {
				   cin >> _max_power;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 Arm arm(_name,_model_number,_cost,_description,_image_file,_max_power);
				 catologe.add_part(arm);
				 break;}
		case 4 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 while (flag == 1)
				 {
				   cin >> _model_number;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the cost of the part: " << endl;
				 while (flag == 1)
				 {
				   cin >> _cost;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the max power of the locomotor: " << endl;
				 while (flag == 1)
				 {
				   cin >> _max_power;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 Locomotor locomotor(_name,_model_number,_cost,_description,_image_file,_max_power);
				 catologe.add_part(locomotor);
				 break;}
		case 5 : {cout << "Enter the part name: " << endl;
				 cin >> _name;
				 cout << "Enter the model number: " << endl;
				 while (flag == 1)
				 {
				   cin >> _model_number;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the cost of the part: " << endl;
				 while (flag == 1)
				 {
				   cin >> _cost;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the part description: " << endl;
				 cin >> _description;
				 cout << "Enter the image file name: " << endl;
				 cin >> _image_file;
				 cout << "Enter the power available" << endl;
				 while (flag == 1)
				 {
				   cin >> _power_available;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 cout << "Enter the max energy: " << endl;
				 while (flag == 1)
				 {
				   cin >> _max_energy;
				   if (cin.fail())
				   {
				 	  cin.clear();
				 	  cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 	  cout << "Invalid input: Please re enter: " << endl;
				 	  continue;
				   }
				 flag = 0;
				 }
				 flag =1;
				 Battery battery(_name,_model_number,_cost,_description,_image_file,_power_available,_max_energy);
				 catologe.add_part(battery);
				 break;}
		default : {}
	}
}