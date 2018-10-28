//class specification file that stores class declaration for ElectricComponet class
#ifndef ELECTRICCOMPONENT_H_ //This directive tells the preprocessor to see if a constant named ELECTRICCOMPONENT_H_ has not been previously created  with a #define directive.
#define ELECTRICCOMPONENT_H_  //If the ELECTRICCOMPONENT_H_ constant has not been defined, the rest of the file is included. If the constant has been defined, everything between the #ifndef and #endif is skipped.
#include <iostream> // needed for cout
#include <string> //need to include this header file to work with string data type

using namespace std; // declares that the program will be accessing entities whose names are part of the namespace called std

class ElectricComponent; //Forward declaration
ostream &operator << (ostream &, const ElectricComponent &); // Function prototype for overloaded stream insertion operator (<<)
// Because this function is not a member of the ElectricComponent class, it doesn’t have the access to the private members.

//Create an abstract base class that contains the common information that are sharing by the derived classes
//ElectricComponent class declaration
class ElectricComponent {
public: //public access specifier is used for member functions which means that they can be called from statements outside the class.
	virtual ~ElectricComponent() //create a virtual destructor that does nothing because virtual functions are used in this base class.
	{};
	//pure virtual functions that must be overridden in derived classes. (= 0) notation indicates that these function are pure virtual functions.
	virtual double getValue() const = 0;  //	get	the value of the electronic	component,	returning a	value of type double.
	virtual string getUnit() const = 0; //	get	the	units of the electronic	component,	returning a	value of type string
	virtual string getDescription() const = 0; // 	get	the	printable description of the electronic component, returning a value of	type string.

	//make this function a friend of ElectricComponent class so this function can access directly to the private members.
	friend ostream &operator << (ostream &, const ElectricComponent &);
};

#endif //Needed to end the #ifndef statement
