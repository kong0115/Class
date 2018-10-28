//	CS	1337.003 Project 3 <sxk170832> <Siang Swee Kong>

#include <iostream> //preprocessor directive,in order to read or write to the standard input/output streams
#include <string> //need to include this header file to work with string data type
#include <vector> //to use vector in my program, I must include the <vector> header file
#include "ElectricComponent.h" //Needed to use ElectricComponent class
#include "Resistor.h" //Needed to use Resistor class
#include "Capacitor.h" //Needed to use Capacitor class
#include "Battery.h" //Needed to use Battery class

using namespace std; // declares that the program will be accessing entities whose names are part of the namespace called std

void printData (vector<ElectricComponent *>, int ); //function prototype that prints the information of electric components.
//It takes two arguments, the vector of pointer to electric components and integer count.

int main() {

	string choice; // a variable to store the user's desired action
	vector<ElectricComponent *> eComponent;  //create an vector of pointers to ElectricComponent base class that has no defined size
	int count = 0; // a variable to store the number of elements in the array
	string a;

	do {
		//prompt the user for which type of electric component they want to select or if they want to terminate the program
		cout << "Please enter 1, 2, 3 or 4:" << endl;
		cout << "  1 - Enter information about a resistor" << endl;
		cout << "  2 - Enter information about a capacitor" << endl;
		cout << "  3 - Enter information about a battery" << endl;
		cout << "  4 - Print component information and terminate the program" << endl;
		cin >> choice; //get the value for desired action from user

		double tempValue; //create a temporary variable of double to check input validation for the value of the electric component;

		if (choice == "1") //if the user enters 1, then ask for the value of the resistor
		{
			cout << "Please enter a value for the component" << endl;
			cin >> tempValue; //store the user input in temporary variable
			while (tempValue < 0  || !cin ) //it will keep looping if the user enter invalid input or negative numbers
			{
				cout << "Entry not accepted. Please enter ONLY a positive, floating point value" << endl; //ask the user to enter a valid input
				cout << "\nPlease enter a value for the component" << endl;
				cin.clear();  //use to clear the flag
				cin.ignore(1000, '\n'); //will ignore invalid input for 1000 characters or until the enter key hit
				cin >> tempValue; //store the user input in temporary variable
			}
			getline(cin,a);
			eComponent.push_back(new Resistor(tempValue)); //dynamically create an instance of Resistor that passes one argument to the constructor and add it to the vector
			count++;//increment count by 1, used to keep track of how many elements in the vector, also used as a subscript to access the vector elements
		}

		else if (choice == "2") //if the user enters 2, then ask for the value of the capacitor
		{
			cout << "Please enter a value for the component" << endl;
			cin >> tempValue; //store the user input in temporary variable
			while (tempValue < 0 || !cin) //it will keep looping if the user enter invalid input or negative numbers
			{
				cout << "Entry not accepted. Please enter ONLY a positive, floating point value" << endl; //ask the user to enter a valid input
				cout << "\nPlease enter a value for the component" << endl;
				cin.clear(); //use to clear the flag
				cin.ignore(1000, '\n'); //will ignore invalid input for 1000 characters or until the enter key hit
				cin >> tempValue;  //store the user input in temporary variable
			}
			getline(cin, a);
			eComponent.push_back(new Capacitor(tempValue));//dynamically create an instance of Capacitor that passes one argument to the constructor and add it to the vector
			count++; //increment count by 1, used to keep track of how many elements in the vector, also used as a subscript to access the vector elements
		}

		else if (choice == "3") //if the user enters 3, then ask for the value of the battery
		{
			cout << "Please enter a value for the component" << endl;
			cin >> tempValue; //store the user input in temporary variable
			while (tempValue < 0 || !cin) //it will keep looping if the user enter invalid input or negative numbers
			{
				cout << "Entry not accepted. Please enter ONLY a positive, floating point value" << endl;  //ask the user to enter a valid input
				cout << "\nPlease enter a value for the component" << endl;
				cin.clear(); //use to clear the flag
				cin.ignore(1000, '\n'); //will ignore invalid input for 1000 characters or until the enter key hit
				cin >> tempValue; //store the user input in temporary variable
			}
			getline(cin, a);
			eComponent.push_back(new Battery(tempValue));//dynamically create an instance of Battery that passes one argument to the constructor and add it to the vector
			count++; //increment count by 1, used to keep track of how many elements in the vector, also used as a subscript to access the vector elements
		}

		else if (choice == "4") //if the user enters 4, then print the information of the electric components
		{
			if(count == 0) //if the count is equal to zero, then tell the user that no information is given from the user
			{
				cout<< "No information is entered." << endl;
			}
			else //otherwise, print the information of the electric components
				printData(eComponent,count); //sent two arguments to the printData function and call the function to print the data.
		}

		else //if the user enters anything that is not 1, 2, 3 or 4 for desired actions
			cout << "Entry not accepted. Please enter ONLY 1, 2, 3, or 4" << endl; //ask the user for desired action again


	} while (choice != "4"); //the loop will stop if the user enter 4 for desired action

	for (int index = 0; index < count; index++)
	{
	delete (eComponent[index]); //delete all the dynamically allocated memory.
	eComponent[index] = nullptr; //set all the pointer variable to the ElectricComponent class in the vector to nullptr after delete them
	//to prevents code from inadvertently using the pointer to access the memory that was freed.
	}

	return 0; //close the program
}

void printData (vector<ElectricComponent *> eComponent, int count) //function definition for printData that prints the information of electrical components
{//It takes two arguments, the vector of pointer to electric components and integer count.
	for (int index = 0; index < count; index++) //loop from the first element in the vector to the last element of the vector, increment by one
	{
		cout << "Component value is " << eComponent[index]->getDescription() << endl;
		//using a pointer to call the getDescription function from the derived class that making the call at run time instead of the base class.
	}

		cout << endl;

	for (int index = 0; index < count; index++) //loop from the first element in the vector to the last element of the vector, increment by one
	{
		cout << "Component " << (index+1) << " " << *eComponent[index] << endl;
		//when a cout << is followed by a ElectricComponet object, this will call the overloaded stream insertion operator (<<) function from the ElectricComponent.
	}
}




