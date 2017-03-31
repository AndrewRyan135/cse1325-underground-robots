#include <iostream>
#include "catalog.h"
#include "robot.h"
using namespace std;

int main()
{
	Catalog catalog;

	Head head("Pizza", 21, 21, "tool", "nothing", 31);
	catalog.add_head(head);
	cout <<	catalog.head_to_string(1) << endl;
}
