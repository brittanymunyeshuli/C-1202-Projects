#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "StateStats.h"
#include "State.h"


using namespace std;

const int NAME_SIZE = 50;
struct Symptom {
	char name[NAME_SIZE];
	int intensity;
};

int getMenu();
void enterSymptoms();
void printSymptoms();
void stateData();

int choice;

int main()
{

	while (choice != 7)
	{
	
		switch (getMenu())
		{
		case 1:
			enterSymptoms();
			break;
		case 2:
			printSymptoms();
			break;
		case 3:
			stateData();
			break;
		case 4:
			cout << "     Exiting application now." << endl;
			exit(0);
			break;
		default:
			cout << "     INVALID OPTION. Please review the menu options (1-4)" << endl;
			// cout << "Please enter a valid option (1-7)" << endl;
			// cout << "from the following menu" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

int getMenu()
{
	cout << endl;
	cout << "   COVID-19 Symptom and State Data Tracker" << endl;
	cout << "_______________________________________________" << endl;
	cout << "   Please select from the following menu: " << endl<<endl;
	cout << "                  SYMPTOMS" << endl;
	cout << "             1. Enter symptoms" << endl;
	cout << "             2. Print symptoms" << endl<<endl;
	cout << "                  STATE DATA" << endl;
	cout << "             3. Enter State Data" << endl;
	cout << "             4. Exit application" << endl;

	cout << endl;
	cout << "      Enter your choice: ";
	cin >> choice;
	cout << endl;

	return choice;
}

fstream sympData;

void enterSymptoms()
{
	sympData.open("covidFile.dat", ios::out | ios::binary);
	char shouldContinue;
	do {
		Symptom symp;
		cout << "     Enter the symptom (common name): ";
		cin >> symp.name;

		cout << "     Intensity to monitor (out of 10): ";
		cin >> symp.intensity;
		cout << endl;

		sympData.write(reinterpret_cast<char*>(&symp), sizeof(symp));

		cout << "     Enter additional symptoms (Y/N): ";
		cin >> shouldContinue;
		cout << endl;
		cin.ignore();
	} while (shouldContinue == 'Y' || shouldContinue == 'y');

	sympData.close();
}

void printSymptoms()
{
	sympData.open("covidFile.dat", ios::in | ios::binary);
	sympData.seekg(0L, ios::beg); 

	Symptom symp;
	sympData.read(reinterpret_cast<char*>(&symp), sizeof(symp));

	cout << "___________________________________________________" << endl;
	cout << endl;
	cout << "          COMMON SYMPTOMS TO MONITOR" << endl;

	while (!sympData.eof())
	{
		cout << "         SYMPTOMS:  "<< symp.name << endl;
		cout << "         INTENSITY: " << symp.intensity << endl;
		sympData.read(reinterpret_cast<char*>(&symp), sizeof(symp));
		cout << endl;
	}

	cout << "___________________________________________________" << endl;

	sympData.close();
}

void stateData()
{
	cout << "     ENTER COVID-19 DATA" << endl;
	cout << "     State: ";
	string stateName;
	cin >> stateName;

	cout << "     Confirmed cases: ";
	int numConfirmed;
	cin >> numConfirmed;

	cout << "     Recovered: ";
	int numRecovered;
	cin >> numRecovered;

	cout << "     Deaths: ";
	int numDeaths;
	cin >> numDeaths;

	cout << "     Presumed: ";
	int numPresumed;
	cin >> numPresumed;
	cout << endl;
	cin.ignore();

	State state1(stateName, numConfirmed, numRecovered, numDeaths, numPresumed);
	state1.displayStats();
}