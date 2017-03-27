#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"
#include "customer.h"
#include "sales_associate.h"
#include "robot.h"
using namespace std;

Catalog catalog;


class View
{
	public :
	string get_menu()
	{
		stringstream os;
		os << "========================" << "\n"
		   << "Robbie Robot Shop System" << "\n"
		   << "========================" << "\n"
		   << "\n"
		   << "\n1. Customer"
		   << "\n2. Sales Associate"
		   << "\n3. Product Manager"
		   << "\n4. Boss"
		   << "\n5. Quit";
		return os.str();
	}
	string show_catalog()
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
			case 1 : 
					  cout << "Browse robot catalog" << endl;
					  break;
					            //call to print out catalog 
			case 2 : cout << "To be finish in later sprint" << endl;
					 break;
			case 3 : cout << "1. Create robot part" << endl
					      << "2. Create new robot model" << endl;
					 cin >> cmd;
				     if (cmd == 1)
				     {

				 	 	//new robot part
				     }
				     else if (cmd == 2)
				     {
					     	//for now, just pre build robots
				 	 	//new robot model
						
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
					     cout << customer.to_string() << endl;
					     catalog.add_customer(customer);
				 	     //new customer
				     }
				     else if (cmd == 2)
				     {
				 	     string name;
				 	     int number;
				 	     cout << "Enter the employee's name: " << endl;
				 	     cin >> name;
				 	     cout << "Enter the employee's employee number: " << endl;
				 	     cin >> number;
				 	     if (cin.fail())
				 	     {
				 	     	cout << "Not a valid employee number" << endl;
				 	     }

				 	     SalesAssociate associate(name,number);
				 	     catalog.add_associate(associate);
				     }
				 
				     break;
			case 5 : exit(0);
					 break;
			default : {}
			}
	       }

		private :
		int cmd;	
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
