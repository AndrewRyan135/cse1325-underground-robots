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
#include <FL/Fl_Text_Display.H>
#include "catalog.h"
#include "customer.h"
#include "robot.h"
#include "sales_associate.h"
#include "store.h"
#include "dialog_gui.h"
using namespace std;

//Catalog catologe;
//Store store;

void create_part();
int int_validation();
double double_validation();
void part_picker(int index);
bool int_validation(string input);
bool double_validation(string input);
//void part_picker(int index);
//void save_data();

//robot_part_dialog *robot_part_dlg;
Fl_Menu_Item manager_menuitems[] = {
	{"&File", 0,0,0,FL_SUBMENU},
		{"&Open", FL_ALT + 'o', (Fl_Callback *) open_fileCB},
		{"&Save", FL_ALT + 's', (Fl_Callback *) save_fileCB},
		{"&Quit", FL_ALT + 'q', (Fl_Callback *) Quit},
		{0},
	{"&Report", 0,0,0,FL_SUBMENU},
		{"&Show Robot Parts", FL_ALT + 'v', (Fl_Callback *)show_robot_partsCB},
		{"Show &Models",FL_ALT + 'm', (Fl_Callback *)show_robot_models_dialogCB},
		{"Show Orders", FL_ALT + FL_SHIFT + 'o', (Fl_Callback *)show_ordersCB},

		{"Show &Customers", FL_ALT + 'c', (Fl_Callback *)show_customersCB},

		{"Orders by &employees",FL_ALT + 'e', (Fl_Callback *)show_sales_reportCB},
		//{"&Test order output", FL_ALT + 't', (Fl_Callback *)test_windowCB},

		{0},
	{"&Create", 0,0,0,FL_SUBMENU},
		{"Robot &Part", FL_ALT + 'p', (Fl_Callback *) robot_part_dialog_showCB},
		{"Robot &Model", FL_ALT + 'r', (Fl_Callback *)robot_model_dialog_showCB},
		{"Sales &Associate", FL_ALT + 'a', (Fl_Callback *)sales_associate_dialog_showCB},
		{"Customer", FL_ALT + 'c', (Fl_Callback *)customer_dialog_showCB},
		{"Order", FL_ALT + + 'o', (Fl_Callback *)show_order_dialogCB},
		{0},
    {"&Manage", 0,0,0,FL_SUBMENU},
        {"&Orders", FL_ALT + 'o', (Fl_Callback *)manage_order_dialogCB},
        {0},
	{0}
};

Fl_Menu_Item sales_associate_menuitems[] = {
	{"&File", 0,0,0,FL_SUBMENU},
		{"&Open", FL_ALT + 'o', (Fl_Callback *) open_fileCB},
		{"&Save", FL_ALT + 's', (Fl_Callback *) save_fileCB},
		{"&Quit", FL_ALT + 'q', (Fl_Callback *) Quit},
		{0},
	{"&Report", 0,0,0,FL_SUBMENU},
		{"&Show Robot Parts", FL_ALT + 'v', (Fl_Callback *)show_robot_partsCB},
		{"Show &Models",FL_ALT + 'm', (Fl_Callback *)show_robot_models_dialogCB},
		{"Show &Customers", FL_ALT + 'c', (Fl_Callback *)show_customersCB},
		{0},
	{"&Create", 0,0,0,FL_SUBMENU},
		{"Robot &Part", FL_ALT + 'p', (Fl_Callback *) robot_part_dialog_showCB},
		{"Robot &Model", FL_ALT + 'r', (Fl_Callback *)robot_model_dialog_showCB},
		{"Sales &Associate", FL_ALT + 'a', (Fl_Callback *)sales_associate_dialog_showCB},
		{"Customer", FL_ALT + 'c', (Fl_Callback *)customer_dialog_showCB},
		{"Order", FL_ALT + + 'o', (Fl_Callback *)show_order_dialogCB},
		{0},
		{0}
};

int main()
{
	string sales_associate_password = "123abc";
	string manager_password = "pizza";
	string input_password;
	
	Fl_Window *login;
	login = new Fl_Window(0,0,"test");
	login->end();
	login->show();

	robot_part_dlg = new robot_part_dialog{};
	robot_head_dlg = new robot_head_dialog{};
	robot_torso_dlg = new robot_torso_dialog{};
	robot_arm_dlg = new robot_arm_dialog{};
	robot_locomotor_dlg = new robot_locomotor_dialog{};
	robot_battery_dlg = new robot_battery_dialog{};
	robot_model_dlg = new robot_model_dialog{};

	show_robot_models_dlg = new show_robot_models_dialog{};

	sales_associate_dlg = new sales_associate_dialog{};
	customer_dlg = new customer_dialog{};
	order_dlg = new create_order{};
	manage_order_dlg = new manage_order_dialog{};
	while(true)
	{
		input_password = fl_password("Enter password: ", "");
		login->hide();
		login->clear();

		if(input_password == manager_password)
		{
			Fl_Window *win;
			Fl_Menu_Bar *menubar;
			fl_register_images();
			win = new Fl_Window(640,480, "Robbie Robot Shop (Manager)");
			menubar = new Fl_Menu_Bar(0,0,640,30);
			menubar->menu(manager_menuitems);
			win->end();
			win->show();
			return Fl::run();
		}
		else if(input_password == sales_associate_password)
		{
			Fl_Window *win;
			Fl_Menu_Bar *menubar;
			fl_register_images();
			win = new Fl_Window(640,480, "Robbie Robot Shop (Sales associate)");
			menubar = new Fl_Menu_Bar(0,0,640,30);
			menubar->menu(sales_associate_menuitems);
			win->end();
			win->show();
			return Fl::run();
		}
		else
		{
			fl_message("Wrong password, try again.");
		}
	
	}
				
		Fl_Window *win;
		Fl_Menu_Bar *menubar;
		fl_register_images();
		win = new Fl_Window(680,480, "Robbie Robot Shop");
		menubar = new Fl_Menu_Bar(0,0,680,30);
		string help_text = R"(
                        		===========================
		                           		   HELP
                        		===========================


Customers:
    	Customers are able to view robot models in order to view prospective purchases. 
    	When an order is created the customer will be provided an invoice of the order 
    	so that can pay for the product and review the order.		

Sales Assocaites:
    	Sales associates will handeling the order proccess for the customer once the 
    	customer selects a model. The Sales Associate will then provide the invlice to 
    	the customer.
    	Additionally, the Sales Associates will also be able to view there sales reports.

Product Manager:
    	The Product Manager is able to create new robot parts, as well as assembeling 
    	these parts into robot models.

Pointed-haired Boss:
    	The boss is able to view all orders that have been created and adjust the statuses 
    	of the orders as well as viewing the sales reports for each Sales Associate.)";
		Fl_Text_Buffer *buff = new Fl_Text_Buffer();
		Fl_Text_Display *disp = new Fl_Text_Display(5,40,680-10,480-40);
		disp->buffer(buff);
		win->resizable(*disp);
		win->show();
		buff->text(help_text.c_str());
		menubar->menu(menuitems);
		win->end();
		win->show();
		return Fl::run();
}
