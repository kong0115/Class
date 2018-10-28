//class implementation file that stores the member function definitions for ElectricComponent class
#include "ElectricComponent.h" //Needed to use ElectricComponent class. " "indicates the file is located in the current project directory.

//Function definition for overloaded stream insertion operator (<<)
//The ostream parameter will be a reference to the ostream object on the left side of the << operator. The second parameter is a reference to a ElectricComponent object.
ostream &operator << (ostream & strm, const ElectricComponent & obj)
{
	string componentType; //create a string that stores the component type

	if (obj.getUnit() == " Ohm(s)") //If the function return value is the same as " Ohm(s)",
	{
		componentType = "Resistor"; //store "Resistor" into the string variable.
	}

	else if (obj.getUnit() == " Farad(s)") //If the function return value is the same as " Farad(s)",
	{
		componentType = "Capacitor"; //store "Capacitor" into the string variable
	}

	else
	{
		componentType = "Battery";//Otherwise, store "Battery" into the string variable
	}

	//whenever a cout << is followed by a ElectricComponet object, this code will execute
	strm << componentType << " value (" << obj.getDescription() << ")"; //return the component type and the description of the electric component
	return strm; //return the ElectricComponent object to cout
}



