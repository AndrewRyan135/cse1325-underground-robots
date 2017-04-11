#include "utility.h"
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
string get_string(string prompt) {
  string result = "";
  cout << prompt;
  getline(cin, result);
  return result;
}

//
// Skip all characters in the STDIN buffer up to and including the next newline
// For use after a cin stream operation, to clear invalid text and the newline
//
void skip() {
  if (cin.fail())
    cin.clear();
  cin.ignore(INT_MAX, '\n');
}

//
// Return any valid integer from the user
//
int get_int(string prompt) {
  int result = 0;
  while (true) {
    cout << prompt;
    cin >> result;
    bool success = cin.good();
    skip();
    if (success) return result;
    cerr << "### Not an integer!" << endl;
  }
}

//
// Return any valid integer between min_int and max_int, inclusive
//
int get_int(string prompt, int min_int, int max_int) {
  int result = min_int - 1;
  while (true) {
    result = get_int(prompt);
    if (min_int <= result && result <= max_int) return result;
    cerr << "### Integer must be between " << min_int << " and " << max_int << "!\n";
  }
}

//
// Return any valid double from the user
//
double get_double(string prompt) {
  double result = 0.0;
  while (true) {
    cout << prompt;
    cin >> result;
    bool success = cin.good();
    skip();
    if (success) return result;
    cerr << "### Not a number!" << endl;
  }
}

// /////////////////////////////////////////
// F I L E   I / O
// /////////////////////////////////////////

//
// Return any string from the file, including a simple \n
//
string get_string(istream& ist) {
  string result = "";
  getline(ist, result);
  return result;
}

//
// Skip all characters in the input buffer up to and including the next newline
// For use after a input stream operation, to clear invalid text and the newline
//
void skip(istream& ist) {
  if (ist.fail())
    ist.clear();
  ist.ignore(INT_MAX, '\n');
}

//
// Return any valid integer from the file
//
int get_int(istream& ist) {
  int result = 0;
  ist >> result;
  skip(ist);
  return result;
}

//
// Return any valid double from the file
//
double get_double(istream& ist) {
  double result = 0.0;
  ist >> result;
  skip(ist);
  return result;
}
