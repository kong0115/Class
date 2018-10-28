//class specification file that stores class declaration for Resistor class
#ifndef RESISTOR_H_ //This directive tells the preprocessor to see if a constant named RESISTOR_H_ has not been previously created  with a #define directive.
#define RESISTOR_H_ //If the RESISTOR_H_ constant has not been defined, the rest of the file is included. If the constant has been defined, everything between the #ifndef and #endif is skipped.

#include "ElectricComponent.h" //Needed to use ElectricComponent class. " "indicates the file is located in the current project directory.

//Create a Resistor derived class that inherits information from the ElectricComponent base class
class Resistor : public ElectricComponent{  //Public class access specification means object of derived class can be treated as object of base class
private: //making the member variables private to protects critical data from being accidentally modified, they cannot be accessed by statements outside the class
	double rValue;  //create a double variable to store the resistor value
	const string rUnit = " Ohm(s)"; //create a string variable to store the resistor unit. I don't want the unit to be changed, so I use a const string
	string rDescription; //create a string variable to store the printable description of the resistor

public://public access specifier is used for member functions which means that they can be called from statements outside the class.
	Resistor(double rV); //create a constructor that takes one parameter for the resistor value as double
	virtual ~Resistor(); //create a virtual destructor that perform shutdown procedures when the object is destroyed.

	//Inline member function
	virtual double getValue() const //redefine the getValue function in the base class, virtual will determines the type of object making the call at run time.
	{
		return rValue;  //return the resistor value as double
	}
	virtual string getUnit() const //redefine the getUnit function in the base class
	{
		return rUnit; //return the resistor unit as string
	}

	virtual string getDescription() const //redefine the getDescription function in the base class
	{
		return rDescription; //return the resistor description as string
	}


};

#endif //Needed to end the #ifndef statement
