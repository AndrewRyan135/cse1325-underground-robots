#pragma once
using namespace std;
#include <iostream>
#include <vector>

class Store{
private:
    vector<Order> orders;
    Catalog catalog;
    vector<Customer> customers;
    vector<Sales_associate> sales_associates;
public:
    Store();
    void save(string filename);
    void open(string filename);
    void add_order(Order _order);
    void add_catalog(Catalog _catalog);
    void add_customer(Customer _customer);
    void add_sales_associate(Sales_associate _sales_associate);
    
};