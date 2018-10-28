//class implementation file that stores the member function definitions for Battery class
#include "Battery.h" //Needed to use Battery class. " "indicates the file is located in the current project directory.
#include <sstream> //stringstream is needed for input and output to a string

Battery::Battery(double bV) //Define the constructor for Battery class that takes one argument of double variable
{
	bValue = bV; //the parameter is assigned to the bValue member variable in Battery class
	ostringstream strObj; //create an output string stream
	strObj << bV; //add the double value of battery to output string stream
	string newBV = strObj.str(); // get string from output string stream , now the double variable becomes a string variable
	bDescription = newBV + getUnit(); //the value of the battery (now is in the form of string) append with the battery unit and store it to bDesctiption
}

Battery::~Battery() //create a destructor that takes no arguments and does nothing
{}
