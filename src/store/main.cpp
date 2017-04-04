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
//void robot_part_dialogCB(Fl_Widget* w, void* p);
//void robot_head_dialogCB(Fl_Widget* w, void* p);
void robot_part_dialog_showCB(Fl_Widget* w, void* p);
void robot_part_dialog_hideCB(Fl_Widget* w, void* p);
void robot_head_dialog_showCB(Fl_Widget* w, void* p);
void robot_head_dialog_hideCB(Fl_Widget* w, void* p);
void create_robot_headCB(Fl_Widget* w, void* p);
void robot_arm_dialog_showCB(Fl_Widget* w, void* p);
void robot_arm_dialog_hideCB(Fl_Widget* w, void* p);
void create_robot_armCB(Fl_Widget* w, void* p);
void robot_torso_dialog_showCB(Fl_Widget* w, void* p);
void robot_torso_dialog_hideCB(Fl_Widget* w, void* p);
void create_robot_torsoCB(Fl_Widget* w, void* p);
void robot_locomotor_dialog_showCB(Fl_Widget* w, void* p);
void robot_locomotor_dialog_hideCB(Fl_Widget* w, void* p);
void create_robot_locomotorCB(Fl_Widget* w, void* p);
void robot_battery_dialog_showCB(Fl_Widget* w, void* p);
void robot_battery_dialog_hideCB(Fl_Widget* w, void* p);
void create_robot_batteryCB(Fl_Widget* w, void* p);
//void part_picker(int index);
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

//robot_part_dialog *robot_part_dlg;
//Fl_Menu_Item menuitems[] = {
//	{"&File", 0,0,0,FL_SUBMENU},
		//{"&Open", FL_ALT + 'o', (Fl_Callback *)/*open*/},
		//{"&Save", FL_ALT + 's', (Fl_Callback *)/*save*/},
//		{"&Quit", FL_ALT + 'q', (Fl_Callback *) Quit},
//		{0},
//	{"&Boss", 0,0,0,FL_SUBMENU},
//		{"Add &Part", FL_ALT + 'p', (Fl_Callback *) robot_part_dialog_showCB},
//		{0},
//	{0}
//};



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

/*void create_partCB(Fl_Widget* w, void* p)
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
}*/

class robot_part_dialog
{
	public :
	robot_part_dialog() {
		dialog = new Fl_Window(340,270,"Robot Parts");
		rp_head = new Fl_Return_Button(100, 50, 120, 25, "Head");
		rp_head->callback((Fl_Callback *)robot_head_dialog_showCB, 0);

		rp_torso = new Fl_Return_Button(100, 80, 120, 25, "Torso");
		rp_torso->callback((Fl_Callback *)robot_torso_dialog_showCB, 0);

		rp_arm = new Fl_Return_Button(100, 110, 120, 25, "Arm");
		rp_arm->callback((Fl_Callback *)robot_arm_dialog_showCB, 0);

		rp_locomotor = new Fl_Return_Button(100, 140, 120, 25, "Locomotor");
		rp_locomotor->callback((Fl_Callback *)robot_locomotor_dialog_showCB, 0);

		rp_battery = new Fl_Return_Button(100, 170, 120, 25, "Battery");
		rp_battery->callback((Fl_Callback *)robot_battery_dialog_showCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}
		void show() {dialog->show();}
		void hide() {dialog->hide();}
	private :
		Fl_Window *dialog;
		Fl_Return_Button *rp_head, *rp_torso, *rp_arm, *rp_locomotor, *rp_battery;
};
robot_part_dialog *robot_part_dlg;
void robot_part_dialog_showCB(Fl_Widget* w, void* p)
{
	//robot_part_dialog *robot_part_dlg;
	robot_part_dlg->show();
}
void robot_part_dialog_hideCB(Fl_Widget* w, void* p)
{
	robot_part_dlg->hide();
}
//=======================================
//             Head Dialog
//=======================================
class robot_head_dialog
{
	public :
		robot_head_dialog() {
		dialog = new Fl_Window(480, 360, "Robot Head");
		rp_name = new Fl_Input(270, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(270, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(270, 70, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(270, 100, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_file_name = new Fl_Input(270, 180, 210, 25, "File name:");
		rp_file_name->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(270, 220, 210, 25, "Power:");
		rp_power->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(270, 250, 100, 25, "Create:");
		rp_create->callback((Fl_Callback *)create_robot_headCB, 0);

		rp_cancel = new Fl_Return_Button(380, 250, 95, 25, "Cancel:");
		rp_cancel->callback((Fl_Callback *)robot_head_dialog_hideCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}

		void show() {dialog->show();}
		void hide() {dialog->hide();}
		string name() {return rp_name->value();}
		int model_number() {a = atoi(rp_cost->value());return a;}
		int cost() {b = atoi(rp_cost->value());return b;}
		string description() {return rp_description->value();}
		string file() {return rp_file_name->value();}
		double power() {c = atof(rp_power->value());return c;}
	private :
		Fl_Window *dialog;
		Fl_Input *rp_name, *rp_model_number, *rp_cost, *rp_description, *rp_file_name, *rp_power;
		Fl_Return_Button *rp_create, *rp_cancel;
		int a, b;
		double c;
};

robot_head_dialog *robot_head_dlg;
void robot_head_dialog_showCB(Fl_Widget* w, void* p)
{
	robot_head_dlg->show();
}
void robot_head_dialog_hideCB(Fl_Widget* w, void* p)
{
	robot_head_dlg->hide();
}
void create_robot_headCB(Fl_Widget* w, void* p)
{
	Head head(robot_head_dlg->name(),robot_head_dlg->model_number(),robot_head_dlg->cost(),robot_head_dlg->description(),robot_head_dlg->file(),robot_head_dlg->power());
	catologe.add_head(head);
	robot_head_dlg->hide();
}
//=======================================
//             Torso Dialog
//=======================================
class robot_torso_dialog
{
	public :
		robot_torso_dialog() {
		dialog = new Fl_Window(480, 360, "Robot torso");
		rp_name = new Fl_Input(270, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(270, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(270, 70, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(270, 100, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_file_name = new Fl_Input(270, 180, 210, 25, "File name:");
		rp_file_name->align(FL_ALIGN_LEFT);

		rp_battery = new Fl_Input(270, 220, 210, 25, "Battery compartments:");
		rp_battery->align(FL_ALIGN_LEFT);

		rp_max_arms = new Fl_Input(270, 250, 210, 25, "Max arms:");
		rp_max_arms->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(270, 280, 100, 25, "Create:");
		rp_create->callback((Fl_Callback *)create_robot_torsoCB, 0);

		rp_cancel = new Fl_Return_Button(380, 280, 95, 25, "Cancel:");
		rp_cancel->callback((Fl_Callback *)robot_torso_dialog_hideCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}

		void show() {dialog->show();}
		void hide() {dialog->hide();}
		string name() {return rp_name->value();}
		int model_number() {a = atoi(rp_cost->value());return a;}
		int cost() {b = atoi(rp_cost->value());return b;}
		string description() {return rp_description->value();}
		string file() {return rp_file_name->value();}
		int battery() {c = atoi(rp_battery->value());return c;}
		int max_arms() {d = atoi(rp_max_arms->value());return d;}
	private :
		Fl_Window *dialog;
		Fl_Input *rp_name, *rp_model_number, *rp_cost, *rp_description, *rp_file_name, *rp_battery, *rp_max_arms;
		Fl_Return_Button *rp_create, *rp_cancel;
		int a, b, c, d;
};

robot_torso_dialog *robot_torso_dlg;
void robot_torso_dialog_showCB(Fl_Widget* w, void* p)
{
	robot_torso_dlg->show();
}
void robot_torso_dialog_hideCB(Fl_Widget* w, void* p)
{
	robot_torso_dlg->hide();
}
void create_robot_torsoCB(Fl_Widget* w, void* p)
{
	Torso torso(robot_head_dlg->name(),robot_torso_dlg->model_number(),robot_torso_dlg->cost(),robot_torso_dlg->description(),robot_torso_dlg->file(),
				robot_torso_dlg->battery(),robot_torso_dlg->max_arms());
	catologe.add_torso(torso);
	robot_torso_dlg->hide();
}
//=======================================
//             Arm Dialog
//=======================================
class robot_arm_dialog
{
	public :
		robot_arm_dialog() {
		dialog = new Fl_Window(480, 360, "Robot Arm");
		rp_name = new Fl_Input(270, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(270, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(270, 70, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(270, 100, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_file_name = new Fl_Input(270, 180, 210, 25, "File name:");
		rp_file_name->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(270, 220, 210, 25, "Max arm power:");
		rp_power->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(270, 250, 100, 25, "Create:");
		rp_create->callback((Fl_Callback *)create_robot_armCB, 0);

		rp_cancel = new Fl_Return_Button(380, 250, 95, 25, "Cancel:");
		rp_cancel->callback((Fl_Callback *)robot_arm_dialog_hideCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}

		void show() {dialog->show();}
		void hide() {dialog->hide();}
		string name() {return rp_name->value();}
		int model_number() {a = atoi(rp_cost->value());return a;}
		int cost() {b = atoi(rp_cost->value());return b;}
		string description() {return rp_description->value();}
		string file() {return rp_file_name->value();}
		double power() {c = atof(rp_power->value());return c;}
	private :
		Fl_Window *dialog;
		Fl_Input *rp_name, *rp_model_number, *rp_cost, *rp_description, *rp_file_name, *rp_power;
		Fl_Return_Button *rp_create, *rp_cancel;
		int a, b;
		double c;
};

robot_arm_dialog *robot_arm_dlg;
void robot_arm_dialog_showCB(Fl_Widget* w, void* p)
{
	robot_arm_dlg->show();
}
void robot_arm_dialog_hideCB(Fl_Widget* w, void* p)
{
	robot_arm_dlg->hide();
}
void create_robot_armCB(Fl_Widget* w, void* p)
{
	Arm arm(robot_arm_dlg->name(),robot_arm_dlg->model_number(),robot_arm_dlg->cost(),robot_arm_dlg->description(),robot_arm_dlg->file(),robot_arm_dlg->power());
	catologe.add_arm(arm);
	robot_arm_dlg->hide();
}
//=======================================
//           Locomotor Dialog
//=======================================
class robot_locomotor_dialog
{
	public :
		robot_locomotor_dialog() {
		dialog = new Fl_Window(480, 360, "Robot locomotor");
		rp_name = new Fl_Input(270, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(270, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(270, 70, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(270, 100, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_file_name = new Fl_Input(270, 180, 210, 25, "File name:");
		rp_file_name->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(270, 220, 210, 25, "Max locomotor power:");
		rp_power->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(270, 250, 100, 25, "Create:");
		rp_create->callback((Fl_Callback *)create_robot_locomotorCB, 0);

		rp_cancel = new Fl_Return_Button(380, 250, 95, 25, "Cancel:");
		rp_cancel->callback((Fl_Callback *)robot_locomotor_dialog_hideCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}

		void show() {dialog->show();}
		void hide() {dialog->hide();}
		string name() {return rp_name->value();}
		int model_number() {a = atoi(rp_cost->value());return a;}
		int cost() {b = atoi(rp_cost->value());return b;}
		string description() {return rp_description->value();}
		string file() {return rp_file_name->value();}
		double power() {c = atof(rp_power->value());return c;}
	private :
		Fl_Window *dialog;
		Fl_Input *rp_name, *rp_model_number, *rp_cost, *rp_description, *rp_file_name, *rp_power;
		Fl_Return_Button *rp_create, *rp_cancel;
		int a, b;
		double c;
};

robot_locomotor_dialog *robot_locomotor_dlg;
void robot_locomotor_dialog_showCB(Fl_Widget* w, void* p)
{
	robot_locomotor_dlg->show();
}
void robot_locomotor_dialog_hideCB(Fl_Widget* w, void* p)
{
	robot_locomotor_dlg->hide();
}
void create_robot_locomotorCB(Fl_Widget* w, void* p)
{
	Locomotor loco(robot_locomotor_dlg->name(),robot_locomotor_dlg->model_number(),robot_locomotor_dlg->cost(),robot_locomotor_dlg->description(),robot_locomotor_dlg->file(),robot_locomotor_dlg->power());
	catologe.add_locomotor(loco);
	robot_locomotor_dlg->hide();
}
//=======================================
//            Battery Dialog
//=======================================
class robot_battery_dialog
{
	public :
		robot_battery_dialog() {
		dialog = new Fl_Window(480, 360, "Robot battery");
		rp_name = new Fl_Input(270, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(270, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(270, 70, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(270, 100, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_file_name = new Fl_Input(270, 180, 210, 25, "File name:");
		rp_file_name->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(270, 220, 210, 25, "Power available:");
		rp_power->align(FL_ALIGN_LEFT);

		rp_energy = new Fl_Input(270, 250, 210, 25, "Energy available:");
		rp_energy->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(270, 280, 100, 25, "Create:");
		rp_create->callback((Fl_Callback *)create_robot_batteryCB, 0);

		rp_cancel = new Fl_Return_Button(380, 280, 95, 25, "Cancel:");
		rp_cancel->callback((Fl_Callback *)robot_battery_dialog_hideCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}

		void show() {dialog->show();}
		void hide() {dialog->hide();}
		string name() {return rp_name->value();}
		int model_number() {a = atoi(rp_cost->value());return a;}
		int cost() {b = atoi(rp_cost->value());return b;}
		string description() {return rp_description->value();}
		string file() {return rp_file_name->value();}
		double power() {c = atof(rp_power->value());return c;}
		double energy() {d = atof(rp_energy->value());return d;}
	private :
		Fl_Window *dialog;
		Fl_Input *rp_name, *rp_model_number, *rp_cost, *rp_description, *rp_file_name, *rp_power, *rp_energy;
		Fl_Return_Button *rp_create, *rp_cancel;
		int a, b;
		double c, d;
};

robot_battery_dialog *robot_battery_dlg;
void robot_battery_dialog_showCB(Fl_Widget* w, void* p)
{
	robot_battery_dlg->show();
}
void robot_battery_dialog_hideCB(Fl_Widget* w, void* p)
{
	robot_battery_dlg->hide();
}
void create_robot_batteryCB(Fl_Widget* w, void* p)
{
	Battery battery(robot_battery_dlg->name(),robot_battery_dlg->model_number(),robot_battery_dlg->cost(),robot_battery_dlg->description(),
					robot_battery_dlg->file(),robot_battery_dlg->power(), robot_battery_dlg->energy());
	catologe.add_battery(battery);
	robot_battery_dlg->hide();
}

//robot_part_dialog *robot_part_dlg;
Fl_Menu_Item menuitems[] = {
	{"&File", 0,0,0,FL_SUBMENU},
		//{"&Open", FL_ALT + 'o', (Fl_Callback *)/*open*/},
		//{"&Save", FL_ALT + 's', (Fl_Callback *)/*save*/},
		{"&Quit", FL_ALT + 'q', (Fl_Callback *) Quit},
		{0},
	{"&Boss", 0,0,0,FL_SUBMENU},
		{"Add &Part", FL_ALT + 'p', (Fl_Callback *) robot_part_dialog_showCB},
		{0},
	{0}
};

int main()
{
	robot_part_dlg = new robot_part_dialog{};
	robot_head_dlg = new robot_head_dialog{};
	robot_torso_dlg = new robot_torso_dialog{};
	robot_arm_dlg = new robot_arm_dialog{};
	robot_locomotor_dlg = new robot_locomotor_dialog{};
	robot_battery_dlg = new robot_battery_dialog{};
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