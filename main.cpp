#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "catologe.h"
#include "customer.h"
//#include "robot.h"
using namespace std;

Catologe catologe;


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
				 	 	//new robot part
				     }
				     else if (cmd == 2)
				     {
				 	 	//new robot model
				     }
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
