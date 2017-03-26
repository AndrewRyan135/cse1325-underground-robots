#include <stdio.h>
using namespace std;

int main()
{
	view view()
	controller controller();
	cout << view.get_menu(); << endl;
	controller.menu_choice();
}

class view()
{
	public :
	string get_menu()
	{
		string menu = R"(
		========================
		Robbie Robot Shop System
		========================

		1. Customer
		2. Sales Associate
		3. Product Manager
		4. Boss
		)";
		return menu;
	}
	string show_cataloge()
	{
		//print out the vector
	}
};

class controller()
{
	public :
		void menu_choice()
		{
			cin << cmd;
			switch(cmd) {
			case 1 : cout << "Browse robot cataloge" << endl;
			case 2 : cout << "To be finish in later sprint" << end;
			case 3 : cout << "1. Create robot part" << endl
					      << "2. Create new robot model" << endl;
				      cin << cmd;
				  if (cmd == 1)
				 {
				 	//new robot part
				 }
				 else if (cmd == 2)
				 {
				 	//new robot model
				 }
			case 4 : cout << "1. Create new customer" << endl
				          << "2. Create new sales associate" << endl;
				     cin << cmd;
				 if (cmd == 1)
				 {
				 	//new customer
				 }
				 else if (cmd == 2)
				 {
				 	//new sales associate
				 }
			default : cout << "Invalid Input" << endl;
			}
		}

	private:
		int cmd;
};
