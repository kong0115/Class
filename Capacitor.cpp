//class implementation file that stores the member function definitions for Capacitor class
#include "Capacitor.h" //Needed to use Capacitor class. " "indicates the file is located in the current project directory.
#include <sstream> //stringstream is needed for input and output to a string

Capacitor::Capacitor(double cV) //Define the constructor for Capacitor class that takes one argument of double variable
{
	cValue = cV; //the parameter is assigned to the cValue member variable in Capacitor class
	ostringstream strObj; //create an output string stream
	strObj << cV; //add the double value of capacitor to output string stream
	string newCV = strObj.str(); // get string from output string stream , now the double variable becomes a string variable
	cDescription = newCV + getUnit(); //the value of the capacitor (now is in the form of string) append with the capacitor unit and store it to cDesctiption
}

Capacitor::~Capacitor() //create a destructor that takes no arguments and does nothing
{}
