#pragma once
#include <string>
#include <iostream>
#include <climits>
using namespace std;

// /////////////////////////////////////////
// U S E R   I / O
// /////////////////////////////////////////

//
// These utility functions are intended to make it simple to construct new robot parts
// on the fly. The utility functions may be included as part of the constructor itself
// for exceptionally compact record entry.

//
// Return any string from the user, including a simple \n
//
string get_string(string prompt);

//
// Skip all characters in the STDIN buffer up to and including the next newline
// For use after a cin stream operation, to clear invalid text and the newline
//
void skip();

//
// Return any valid integer from the user
//
int get_int(string prompt);

//
// Return any valid integer between min_int and max_int, inclusive
//
int get_int(string prompt, int min_int, int max_int);

//
// Return any valid double from the user
//
double get_double(string prompt);

// /////////////////////////////////////////
// F I L E   I / O
// /////////////////////////////////////////

//
// Return any string from the file, including a simple \n
//
string get_string(istream& ist);

//
// Skip all characters in the input buffer up to and including the next newline
// For use after a input stream operation, to clear invalid text and the newline
//
void skip(istream& ist);

//
// Return any valid integer from the file
//
int get_int(istream& ist);

//
// Return any valid double from the file
//
double get_double(istream& ist);
