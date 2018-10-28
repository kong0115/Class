//class specification file that stores class declaration for Battery class

#ifndef BATTERY_H_ //This directive tells the preprocessor to see if a constant named BATTERY_H_ has not been previously created  with a #define directive.
#define BATTERY_H_ //If the BATTERY_H_ constant has not been defined, the rest of the file is included. If the constant has been defined, everything between the #ifndef and #endif is skipped.

#include "ElectricComponent.h" //Needed to use ElectricComponent class. " "indicates the file is located in the current project directory.

//Create a Battery derived class that inherits information from the ElectricComponent base class
class Battery : public ElectricComponent { //Public class access specification
private://making the member variables private to protects critical data from being accidentally modified, they cannot be accessed by statements outside the class
	double bValue;//create a double variable to store the battery value
	const string bUnit = " Volt(s)";//create a string variable to store the battery unit. I don't want the unit to be changed, so I use a const string
	string bDescription;//create a string variable to store the printable description of the battery

public: //public access specifier is used for member functions which means that they can be called from statements outside the class.
	Battery(double bV); //create a constructor that takes one parameter for the battery value as double
	virtual ~Battery(); //create a virtual destructor that perform shutdown procedures when the object is destroyed.

	////Inline member function
	virtual double getValue() const //redefine the getValue function in the base class
	{
		return bValue; //return the battery value as double
	}
	virtual string getUnit() const//redefine the getUnit function in the base class
	{
		return bUnit;//return the battery unit as string
	}

	virtual string getDescription() const //redefine the getDescription function in the base class
	{
		return bDescription; //return the battery description as string
	}

};


#endif //Needed to end the #ifndef statement
