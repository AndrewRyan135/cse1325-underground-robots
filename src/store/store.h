#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "order.h"
#include "customer.h"
#include "catalog.h"
#include "sales_associate.h"

class Store{
private:
    vector<Order> orders;
    Catalog catalog;
    vector<Customer> customers;
    vector<SalesAssociate> sales_associates;
public:
    Store();
    void save(string filename);
    void open(string filename);
    void open_arm(istream& ifs);
    void open_orders(istream& ifs);
    void add_order(Order _order);
    void add_catalog(Catalog _catalog);
    void add_customer(Customer _customer);
    void add_sales_associate(SalesAssociate _sales_associate);

};
