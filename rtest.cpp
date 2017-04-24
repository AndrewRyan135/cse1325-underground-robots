#include "store.h"
#include "customer.h"
#include "utility.h"

int main(void)
{
    string filename;
    Store store;
    Head* head;
    Torso* torso;
    Arm* arm;
    Locomotor* locomotor;
    Battery* battery;
    Robot_model* robot_model;
    Customer* customer;
    Sales_associate* sales_associate;
    Order* order;
    int choice = 0;
    while(true){
        cout << "Regression test" << endl;
        cout << "1 to save" << endl;
        cout << "2 to open" << endl;
        cout << "3 to print everything" << endl;
        cout << "0 to exit" << endl;
        choice = get_int("Enter a number", 0, 3);
        switch(choice){
        case 0:
            {
                exit(0);
                break;
            }
        case 1:
            {

                filename = get_string("Enter filename:");

                head = new Head("a head", 123, 43.1, "thats it", "head.file", 123.54);
                torso = new Torso("a torso", 1342, 324.5, "yep", "torso.file", 4, 5);
                arm = new Arm("an arm", 43, 55.5, "wow", "arm.file", 20);
                locomotor = new Locomotor("a locomotor", 76, 34.3, "ya", "foot.file", 54.83);
                battery = new Battery("a battery", 234, 77.4, "Z", "bat.file", 5354.3, 345.7);
                robot_model = new Robot_model("a model", 453, *torso, *head, *locomotor, *arm, *battery);
                customer = new Customer("Jerry", 123, "222-222-2222", "Jerry@bennjerrys.com");
                sales_associate = new Sales_associate("Ben", 434);
                order = new Order(543, "2/2/22", *robot_model, 6, *customer, 1, *sales_associate);

                store.get_catalog()->add_head(*head);
                store.get_catalog()->add_torso(*torso);
                store.get_catalog()->add_arm(*arm);
                store.get_catalog()->add_locomotor(*locomotor);
                store.get_catalog()->add_battery(*battery);
                store.get_catalog()->add_model(*robot_model);
                store.add_customer(*customer);
                store.add_sales_associate(*sales_associate);
                store.add_order(*order);
                store.save(filename);
                break;
            }
        case 2:
            {
                filename = get_string("Enter filename:");
                store.open(filename);
                break;
            }
        case 3:
            {
                cout << store.get_catalog()->catalog_to_string() << endl;
                cout << store.order_to_string(0) << endl;
                break;
            }

        }
    }

}
