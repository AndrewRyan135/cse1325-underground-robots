#include "store.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>


Store :: Store(){}

Store::save(string filename)
{
    ofsteam ofs;
    file.open(filename);
    ofs.close();
}


