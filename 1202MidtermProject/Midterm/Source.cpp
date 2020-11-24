/*
* Brittany Munyeshuli
* CIS 1202
* 03/16/2020
* Midterm Project - Equipment Inventory
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int index = 0; // variable to hold how many pieces of equipment are entered


//Equipment Information struct
struct Information
{
	string detModel;
	string detSerialNum;
	string metModel;
	string metSerialNum;
	string efficiency;

};


struct dateInfo
{
	string techName;
	double fullYear;
};

void getDateInfo(dateInfo*);
void displayDateInfo();


//Function Declaration
int displayMenu();
Information getEquipment();
void displayEquipment(Information[]);
void selectEquipment(Information[]);
void findEquipment(Information[], int);

//Main Function
int main()
{
	// Declare array of information struct
	Information equip[100];

	// Show menu to user until asks to exit
	while (true)
	{
		// Call displayMenu function and get choice
		// Call appropriate function according to entered choice
		int choice = displayMenu();
		switch (choice)
		{
		case 1:
			equip[index] = getEquipment();
			index++; // After adding equipment, increment index variable

	  // credentials
			displayDateInfo();
			break;
		case 2:
			displayEquipment(equip);
			break;
		case 3:
			findEquipment(equip, index);
			break;
		case 4:
			cout << "     Exiting Program" << endl;
			return 0;
			break;
		default:
			cout << "     Invalid selection!!" << endl;
			break;
		}
		cout << endl;
	}


	return 0;
}


//Function Definitions
//displayMenu Function
int displayMenu()
{
	// Display menu
	cout << endl;
	cout << "          ~ Lab Equipment Inventory ~ " << endl;
	cout << "____________________________________________________" << endl;
	cout << "     Please select from the menu below" << endl << endl;
	cout << "     1. Enter New Equipment" << endl;
	cout << "     2. Display all Equipment" << endl;
	cout << "     3. Display a piece of Equipment" << endl;
	cout << "     4. Exit program" << endl << endl;

	int choice;

	// Ask user to enter a choice
	cout << "     Please enter your selection: ";
	cin >> choice;
	cin.ignore();
	cout << endl;

	// Return choice
	return choice;
}


Information getEquipment()
{
	
	Information c;

	cout << "     Enter Rad Detector Model: ";
	getline(cin, c.detModel);
	cout << "     Enter Rad Detector Serial Number: ";
	getline(cin, c.detSerialNum);
	cout << "     Enter Equipment Pair Model: ";
	getline(cin, c.metModel);
	cout << "     Enter Equipment Pair Serial Number: ";
	getline(cin, c.metSerialNum);
	cout << "     Enter Equipment Pair % Efficiency: ";
	getline(cin, c.efficiency);
	cout << endl;

	return c;

}

//Credentials
void getDateInfo(dateInfo* info) {
	cout << "     Technician's initials: ";
	getline(cin, info->techName);
	cout << "     Year of calibration: ";
	cin >> info->fullYear;
}

void displayDateInfo() {
	dateInfo val;
	getDateInfo(&val);
	cout << endl;
	cout << "     CREDENTIAL CONFIRMATION" << endl;
	cout << "     Technician initials: " << val.techName << endl;
	cout << "     Year calibration completed: " << val.fullYear << endl;
}


void selectEquipment(Information c) {

	// Display equipment information
	cout << "                       Model  Serial Number" << endl;
	cout << "         Rad Detector: " << c.detModel << "    " << c.detSerialNum << endl;
	cout << "Paired with Rad Meter: " << c.metModel << "     " << c.metSerialNum << endl << endl;

	cout << "           Efficiency: " << c.efficiency << "%" << endl;
}


void displayEquipment(Information equip[]) {

	
	for (int i = 0; i < index; i++) {
		selectEquipment(equip[i]);
		cout << endl;
	}
}

void findEquipment(Information equip[], int size) {
	cout << "     numEquip = " << index << endl;
	
	string Model, serialNumber;

	cout << "      Enter Detector Model: ";
	getline(cin, Model);
	cout << "      Enter Serial Number: ";
	getline(cin, serialNumber);
	cout << endl;

	// Iterate the loop for all equipment
	// display equipment details when model and serial number match
	// return
	// else, print equipment not found
	for (int i = 0; i < size; i++) {
		if (equip[i].detModel == Model && equip[i].detSerialNum == serialNumber) {
			selectEquipment(equip[i]);
			return;
		}
	}

	cout << "      Equipment not found" << endl;
}