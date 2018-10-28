//class implementation file that stores the member function definitions for Resistor class
#include "Resistor.h" //Needed to use Resistor class. " "indicates the file is located in the current project directory.
#include <sstream> //stringstream is needed for input and output to a string
Resistor::Resistor(double rV) //Define the constructor for Resistor class that takes one argument of double variable
{
	rValue = rV; //the parameter is assigned to the rValue member variable in Resistor class
	ostringstream strObj; //create an output string stream
	strObj << rV; //add the double value of resistor to output string stream
	string newRV = strObj.str(); // get string from output string stream , now the double variable becomes a string variable
	rDescription = newRV + getUnit(); //the value of the resistor (now is in the form of string) append with the resistor unit and store it to rDesctiption
}

Resistor::~Resistor() //create a destructor that takes no arguments and does nothing
{}

