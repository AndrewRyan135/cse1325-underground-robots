#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "catologe.h"
using namespace std;

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
		   << "1. Customer"
		   << "2. Sales Associate"
		   << "3. Product Manager"
		   << "4. Boss";
		return os.str();
	}
	void menu_choice(int cmd)
	{
		switch(cmd) {
			case 1 : cout << "Browse robot cataloge" << endl;
			case 2 : cout << "To be finish in later sprint" << endl;
			case 3 : cout << "1. Create robot part" << endl
					      << "2. Create new robot model" << endl;
			case 4 : cout << "1. Create new customer" << endl
				          << "2. Create new sales associate" << endl;
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
				 	 	//new robot part
				     }
				     else if (cmd == 2)
				     {
				 	 	//new robot model
				     }
			case 4 : cin >> cmd;
				     if (cmd == 1)
				     {
				 	     //new customer
				     }
				     else if (cmd == 2)
				     {
				 	     //new sales associate
				     }
			default : {}
			}
		}
		void add_customer()
		{
			string name, phone_number, email;
			int number;
			cout << "Enter the customers name" << endl;
			cin >> name;
			cout << "Enter the customers number" << endl;
			cin >> number;
			cout << "Enter the customers phone number" << endl;
			cin >> phone_number;
			cout << "Enter the customers email" << endl;
			cin >> email;

			Customer customer(name, number, phone_number, email);
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
