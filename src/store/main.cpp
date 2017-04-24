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
Fl_Menu_Item menuitems[] = {
	{"&File", 0,0,0,FL_SUBMENU},
		{"&Open", FL_ALT + 'o', (Fl_Callback *) openCB},
		{"&Save", FL_ALT + 's', (Fl_Callback *) saveCB},
		{"&Quit", FL_ALT + 'q', (Fl_Callback *) Quit},
		{0},
	{"&Report", 0,0,0,FL_SUBMENU},
		{"&Show Robot Parts", FL_ALT + 'v', (Fl_Callback *)show_robot_partsCB},
		{"Show &Models",FL_ALT + 'm', (Fl_Callback *)show_robot_modelsCB},
		{"Show Orders", FL_ALT + FL_SHIFT + 'o', (Fl_Callback *)show_ordersCB},
<<<<<<< HEAD
		{"Show &Customers", FL_ALT + 'c', (Fl_Callback *)show_customersCB},
=======
		{"Orders by &employees",FL_ALT + 'e', (Fl_Callback *)show_sales_reportCB},
		{"&Test order output", FL_ALT + 't', (Fl_Callback *)test_windowCB},
>>>>>>> 6323f77d8568b107c1050aa03248178974d046ff
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

int main()
{
	robot_part_dlg = new robot_part_dialog{};
	robot_head_dlg = new robot_head_dialog{};
	robot_torso_dlg = new robot_torso_dialog{};
	robot_arm_dlg = new robot_arm_dialog{};
	robot_locomotor_dlg = new robot_locomotor_dialog{};
	robot_battery_dlg = new robot_battery_dialog{};
	robot_model_dlg = new robot_model_dialog{};
	sales_associate_dlg = new sales_associate_dialog{};
	customer_dlg = new customer_dialog{};
	order_dlg = new create_order{};
	manage_order_dlg = new manage_order_dialog{};

		Fl_Window *win;
		Fl_Menu_Bar *menubar;
		fl_register_images();
		win = new Fl_Window(640,480, "Robbie Robot Shop");
		menubar = new Fl_Menu_Bar(0,0,640,30);
		menubar->menu(menuitems);
		win->end();
		win->show();
		return Fl::run();
}
