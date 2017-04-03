#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include "catalog.h"
#include "customer.h"
#include "robot.h"
#include "sales_associate.h"
using namespace std;

Catalog catologe;

void create_part();
int int_validation(int input);
double double_validation(double input);
void create_robot_headCB(Fl_Widget* w, void* p);
void robot_part_dialogCB(Fl_Widget* w, void* p);
//void part_picker(int index);
void create_partCB(Fl_Widget* w, void* p);
//void save_data();

//===============================
//            VIEW
//===============================
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
		   << "\n5. Exit\n";
		return os.str();
	}
	void show_parts_list()
	{
		int i = 0;
		cout << "Head: \n" << endl;
		for (i = 0; i < catologe.head_vector_size(); i++)
		{
			cout << "Part Number: " << i << "\n" << catologe.head_to_string(i) << "\n" << endl;
			cout << "=====================================" << endl;
		}
		//part_picker(1);
		cout << "\nTorso: \n" << endl;
		for (i = 0; i < catologe.torso_vector_size(); i++)
		{
			cout << "Part Number: " << i << "\n" << catologe.torso_to_string(i) << "\n" << endl;
			cout << "=====================================" << endl;
		}
		//part_picker(2);
		cout << "\nArm: \n" << endl;
		for (i = 0; i < catologe.arm_vector_size(); i++)
		{
			cout << "Part Number: " << i << "\n" << catologe.arm_to_string(i) << "\n" << endl;
			cout << "=====================================" << endl;
		}
		//part_picker(3);
		cout << "\nLocomotor: \n" << endl;
		for (i = 0; i < catologe.locomotor_vector_size(); i++)
		{
			cout << "Part Number: " << i << "\n" << catologe.locomotor_to_string(i) << "\n" << endl;
			cout << "=====================================" << endl;
		}
		//part_picker(4);
		cout << "\nBattery: \n" << endl;
		for (i = 0; i < catologe.battery_vector_size(); i++)
		{
			cout << "Part Number: " << i << "\n" << catologe.battery_to_string(i) << "\n" << endl;
			cout << "=====================================" << endl;
		}
		//part_picker(5);
	}
	void show_catalog()
	{
		for (int i = 0; i < catologe.model_vector_size(); i++)
		{
			cout << catologe.robot_model_to_string(i) << "\n" << endl;
			cout << "=========================================\n" << endl;
		}
	}
};

View view;
//==================================
//           CONTROLLER
//==================================
/*void menu_choice()
{
	int cmd = int_validation(cmd);
	switch(cmd) {
	case 1 :  cout << "\t\tBrowse robot cataloge\n" << endl;
			  view.show_catalog();

			  break;
	case 2 :  cout << "To be finish in later sprint\n" << endl;
			  break;
	case 3 : cout << "1. Create robot part" << endl
			      << "2. Create new robot model" << endl
			      << "3. Exit\n" << endl;
			 cin >> cmd;
		     if (cmd == 1)
		     {
		     	create_part();
		     }
		     else if (cmd == 2)
		     {
		     	if (catologe.head_vector_size() != 0 && catologe.torso_vector_size() != 0 && catologe.arm_vector_size() != 0 &&
		     		catologe.locomotor_vector_size() != 0 && catologe.battery_vector_size() != 0)
		     	{
		     		view.show_parts_list();
		     	}
		     	else
		     	{
		     		cout << "Cannot create a new model with out parts to complete it(No created parts of a certain type)\n" << endl;
		     	}
		     }
		     else if (cmd == 3)
		     {
		     	break;
		     }
		     break;
	case 4 : cout << "1. Create new customer" << endl
		          << "2. Create new sales associate" << endl
		          << "3. Exit" << endl;
			 cin >> cmd;
		     if (cmd == 1)
		     {
			     string name, phone_number, email;
			     int number;
			     cout << "Enter the customer's name: " << endl;
			     cin.ignore();
			     getline(cin,name);
			     cout << "Enter the customer's number: " << endl;
			     number = int_validation(number);
			     cout << "Enter the customer's phone number: " << endl;
			     cin.ignore();
			     getline(cin,phone_number);
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
		 	     cin.ignore();
		 	     getline(cin, name);
		 	     cout << "Enter the employee's employee number: " << endl;
		 	     employee_number = int_validation(employee_number);

		 	     SalesAssociate associate(name,employee_number);
		 	     catologe.add_associate(associate);
		     }
		     else if (cmd == 3)
		     {
		     	break;
		     }
		     else
		     {
		     	cout << "Invalid input\n" << endl;
		     	break;
		     }
		     break;
	case 5 : exit(0);
	default : {}
	}
}*/

void Quit(Fl_Widget* w, void* p)
{
	exit(0);
}

Fl_Menu_Item menuitems[] = {
	{"&File", 0,0,0,FL_SUBMENU},
		//{"&Open", FL_ALT + 'o', (Fl_Callback *)/*open*/},
		//{"&Save", FL_ALT + 's', (Fl_Callback *)/*save*/},
		{"&Quit", FL_ALT + 'q', (Fl_Callback *) Quit},
		{0},
	{"&Boss", 0,0,0,FL_SUBMENU},
		{"Add &Part", FL_ALT + 'p', (Fl_Callback *) robot_part_dialogCB},
		{0},
	{0}
};


int main()
{
	Fl_Window *win;
		Fl_Menu_Bar *menubar;
		fl_register_images();
		win = new Fl_Window(640,480, "Robbie Robot Shop");
		menubar = new Fl_Menu_Bar(0,0,640,30);
		menubar->menu(menuitems);
		win->end();
		win->show();
		return Fl::run();
		//int cmd = 0;
		//Controller controller;
		//cout << view.get_menu() << endl;
		//controller.menu_choice(cmd);
}

/*void part_picker(int index)
{
	string name;
	static int model_number;
	static int head, torso, arm, locomotor, battery;
	switch(index) {

	    case 1 : cout << "Enter the head part number: " << endl;
		          cin >> head;
		          break;
		case 2 : cout << "Enter the torso part number: " << endl;
		         cin >> torso;
		         break;
		case 3 : cout << "Enter the arm part number: " << endl;
		         cin >> arm;
		         break;
		case 4 : cout << "Enter the locomotor part number: " << endl;
		         cin >> locomotor;
		         break;
		case 5 : {cout << "Enter the battery part number: " << endl;
		         cin >> battery;
		         cout << "Please enter the robots name" << endl;
				 cin >> name;
				 cout << "Please enter the model number" << endl;
				 cin >> model_number;
				 Robot_model model(name, model_number, catologe.get_torso(torso), catologe.get_head(head), catologe.get_locomotor(locomotor), catologe.get_arm(arm), catologe.get_battery(battery));
				 catologe.add_model(model);
		         break;}
		default : {}
	}*/

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

//saves store orders that have been places
/*
void save_data()
{
	cout << "Enter the file name to save in: " << endl;
	string output_filename;
	cin >> output_filename;
	ofstream ofs {output_filename};
	if(!ofs)
	{
		throw runtime_error("Can't open file...");
		return;
	}

	ofs << "Works";
	return;
}
*/


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

/*
double calculate_total_price(int model_index, int quantity)
{
	double total;
	Robot_model model = catologe.get_model(model_index);

	total = quantity * model.cost();
}
*/

void create_partCB(Fl_Widget* w, void* p)
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

void robot_part_dialogCB(Fl_Widget* w, void* p)
{
	Fl_Window *dialog;
	Fl_Return_Button *rp_head;//, *rp_torso, *rp_arm, *rp_locomotor, *rp_battery;
		dialog = new Fl_Window(340,270,"Robot Parts");
		rp_head = new Fl_Return_Button(100, 50, 120, 25, "Head");
		rp_head->callback((Fl_Callback *)create_robot_headCB, 0);

		//rp_torso = new Fl_Return_Button(100, 80, 120, 25, "Torso");
		//rp_torso->callback((Fl_Callback *)create_robot_torsoCB, 0);

		//rp_arm = new Fl_Return_Button(100, 110, 120, 25, "Arm");
		//rp_arm->callback((Fl_Callback *)create_robot_armCB, 0);

		//rp_locomotor = new Fl_Return_Button(100, 140, 120, 25, "Locomotor");
		//rp_locomotor->callback((Fl_Callback *)create_robot_locomotorCB, 0);

		//rp_battery = new Fl_Return_Button(100, 170, 120, 25, "Battery");
		//rp_battery->callbcak((Fl_Callback *)create_robot_batteryCB, 0);
		dialog->end();
		dialog->set_non_modal();
}


void create_robot_headCB(Fl_Widget* w, void* p)
{
	Fl_Window *dialog;
	Fl_Input *rp_name, *rp_part_number, *rp_cost, *rp_description, *rp_file_name, *rp_power;
	dialog = new Fl_Window(340, 270, "Robot Head");
	rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
	rp_name->align(FL_ALIGN_LEFT);

	rp_part_number = new Fl_Input(120, 40, 210, 25, "Model Number:");
	rp_part_number->align(FL_ALIGN_LEFT);

	rp_cost = new Fl_Input(120, 70, 210, 25, "Cost:");
	rp_cost->align(FL_ALIGN_LEFT);

	rp_description = new Fl_Multiline_Input(120, 100, 210, 75, "Description:");
	rp_description->align(FL_ALIGN_LEFT);

	rp_file_name = new Fl_Input(120, 190, 210, 25, "File name:");
	rp_file_name->align(FL_ALIGN_LEFT);

	rp_power = new Fl_Input(120, 220, 210, 25, "Power:");
	rp_power->align(FL_ALIGN_LEFT);
	dialog->end();
		dialog->set_non_modal();
}
