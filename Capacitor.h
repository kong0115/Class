//class specification file that stores class declaration for Capacitor class

#ifndef CAPACITOR_H_ //This directive tells the preprocessor to see if a constant named CAPACITOR_H_ has not been previously created  with a #define directive.
#define CAPACITOR_H_ //If the CAPACITOR_H_ constant has not been defined, the rest of the file is included. If the constant has been defined, everything between the #ifndef and #endif is skipped.

#include "ElectricComponent.h" //Needed to use ElectricComponent class. " "indicates the file is located in the current project directory.

//Create a Capacitor derived class that inherits information from the ElectricComponent base class
class Capacitor : public ElectricComponent {//Public class access specification
private://making the member variables private to protects critical data from being accidentally modified, they cannot be accessed by statements outside the class
	double cValue;//create a double variable to store the capacitor value
	const string cUnit = " Farad(s)";//create a string variable to store the capacitor unit. I don't want the unit to be changed, so I use a const string
	string cDescription; //create a string variable to store the printable description of the capacitor

public://public access specifier is used for member functions which means that they can be called from statements outside the class.
	Capacitor(double cV); //create a constructor that takes one parameter for the capacitor value as double
	virtual ~Capacitor(); //create a virtual destructor that perform shutdown procedures when the object is destroyed.

	////Inline member function
	virtual double getValue() const //redefine the getValue function in the base class
	{
		return cValue; //return the capacitor value as double
	}
	virtual string getUnit() const //redefine the getUnit function in the base class
	{
		return cUnit; //return the capacitor unit as string
	}

	virtual string getDescription() const //redefine the getDescription function in the base class
	{
		return cDescription; //return the capacitor description as string
	}

};

#endif //Needed to end the #ifndef statement
