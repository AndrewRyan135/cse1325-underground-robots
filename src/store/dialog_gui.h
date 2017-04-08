#include <iostream>
#include <string>
#include <sstream>
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
#include "store.h"

Catalog catologe;
Store store;

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
void show_robot_partsCB(Fl_Widget* w, void* p);



void Quit(Fl_Widget* w, void* p)
{
	exit(0);
}

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

		rp_return = new Fl_Return_Button(230, 240, 100, 25, "Return:");
		rp_return->callback((Fl_Callback *)robot_part_dialog_hideCB, 0);
		dialog->end();
		dialog->set_non_modal();
		}
		void show() {dialog->show();}
		void hide() {dialog->hide();}
	private :
		Fl_Window *dialog;
		Fl_Return_Button *rp_head, *rp_torso, *rp_arm, *rp_locomotor, *rp_battery, *rp_return;
};
robot_part_dialog *robot_part_dlg;
void robot_part_dialog_showCB(Fl_Widget* w, void* p)
{
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
	fl_message("Created part");
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
	fl_message("Created part");
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
	fl_message("Created part");
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
	fl_message("Created part");
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
	fl_message("Created part");
	robot_battery_dlg->hide();
}

void saveCB(Fl_Widget* w, void* p)
{
	store.save("save_file.txt");
}

void openCB(Fl_Widget* w, void* p)
{
	store.open("save_file.txt");
}

void show_robot_partsCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(640,480);
	stringstream os;
	int i = 0;
	os << "Heads: \n";
	for (i=0;i<catologe.head_vector_size();i++)
	{
		os << "Part index: " << i+1 << '\n' << catologe.head_to_string(i) << '\n'
		   << "=================================================\n";
	}
	os << "Torsos: \n";
	for (i=0;i<catologe.torso_vector_size();i++)
	{
		os << "Part index: " << i+1 << '\n' << catologe.torso_to_string(i) << '\n'
		   << "=================================================\n";
	}
	os << "Arms: \n";
	for (i=0;i<catologe.arm_vector_size();i++)
	{
		os << "Part index: " << i+1 << '\n' << catologe.arm_to_string(i) << '\n'
		   << "=================================================\n";
	}
	os << "Locomotors: \n";
	for (i=0;i<catologe.locomotor_vector_size();i++)
	{
		os << "Part index: " << i+1 << '\n' << catologe.locomotor_to_string(i) << '\n'
		   << "=================================================\n";
	}
	os << "Batteries: \n";
	for (i=0;i<catologe.battery_vector_size();i++)
	{
		os << "Part index: " << i+1 << '\n' << catologe.battery_to_string(i) << '\n'
		   << "=================================================\n";
	}

	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20,20,640-40,480-40, "Robot Parts");
	disp->buffer(buff);
	win->resizable(*disp);
	win->show();
	buff->text((os.str()).c_str());
}