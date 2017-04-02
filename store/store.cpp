#include "store.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>


Store :: Store(){}

Store :: save(string filename)
{
    ofsteam ofs(filename);
    ofs = save_orders(ofs);
    ofs.close();
}

ostream& Store :: save_orders(ostream& ofs)
{
    //if orders is empty, save -1
    if(orders.size() == 0){
            ofs << -1;
            return ofs;
    }
    else{ //if orders exist, insert line
        ofs << endl;
    }
    for(int i = 0; i < orders.size(); i++){

        //save object
        ofs << orders.at(i);
        //if last object saved, insert -1
        if(i == orders.size()-1){
            ofs << "-1";
        }
        //otherwise skip a line
        else{
            ofs << endl;
        }
    }
    return ofs;
}

Store :: open(string filename)
{
    ifstream ifs(filename);
    open_orders(ifs);

}

istream& Store :: open_orders(istream& ifs)
{
    string line;
    while(!ifs.eof()){
        getline(ifs, line);
        //check if line is -1
        if (line.length() > 0 && line[0] == -1){
            break;
        }
        //load data
        if(line.length() == 0)
        {
            Order order;
            ifs >> order;
            orders.push_back(order);
        }
    }
}


