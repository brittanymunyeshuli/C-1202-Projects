/*
 * Brittany Munyeshuli
 * CIS 1111
 * Final Project - Fundraising Competition Tracker
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void displayMenu();

int getSelection();

void inputDollarsEarned(string participants[], double earnings[], int size);

void showHighestEarned(string participants[], double earnings[], int size);

void saveValues(string participants[], double earnings[], int size);

void loadValues(string participants[], double earnings[], int size);

//Variables used in main and functions
const int NUM_PARTICIPANTS = 5;
const int GOAL = 5000;

int main() {

	string participants[NUM_PARTICIPANTS] = { "Brittany Munyeshuli",
											  "Michael Bowman     ",
											  "Stan Dupp          ",
											  "Allie Gater        ",
											  "Levy Tate          " };
	double earnings[NUM_PARTICIPANTS];

	displayMenu();
	int choice = getSelection();
	while (choice < 5) {

		switch (choice) {

		case 1:
			inputDollarsEarned(participants, earnings, NUM_PARTICIPANTS);
			break;

		case 2:
			showHighestEarned(participants, earnings, NUM_PARTICIPANTS);
			break;

		case 3:
			saveValues(participants, earnings, NUM_PARTICIPANTS);
			break;

		case 4:
			loadValues(participants, earnings, NUM_PARTICIPANTS);
			break;

		}

		choice = getSelection();
	}

	system("pause");
	return 0;
}

//Display Menu Function
void displayMenu() {
	cout << endl;
	cout << "         Middle School Fundraising Competition" << endl;
	cout << "                      Goal of $5000" << endl;
	cout << "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "          1  Amount earned per participant and Stats" << endl;
	cout << "          2  Fundraiser Winner" << endl;
	cout << "          3  Save Data to File" << endl;
	cout << "          4  Load Data from File" << endl;
	cout << "          5  Exit App" << endl;
	cout << "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

//Case 1 Function
void inputDollarsEarned(string participants[], double earnings[], int size) {
	double sumEarned = 0;
	double aveEarned;
	double percentEarned;
	double amtRemain;
	for (int i = 0; i < size; i++) {
		cout << "         Enter earnings for " << participants[i] << ": $";
		double earning;
		cin >> earning;

		sumEarned += earning;
		percentEarned = (sumEarned / GOAL) * 100;
		aveEarned = sumEarned / NUM_PARTICIPANTS;
		amtRemain = GOAL - sumEarned;


		while (earning < 0) {
			cout << "        Error, enter a value greater than 0: ";
			cin >> earning;
		}
		earnings[i] = earning;
	}
	cout << endl;
	cout << "        The sum of all the earnings is: $" << sumEarned << endl;
	cout << "        The average earnings is       : $" << aveEarned << endl << endl;
	cout << "        Congrats!!! " << percentEarned << "% of the $" << GOAL << " goal was earned!" << endl << endl;
	cout << "        Only $" << amtRemain << " remaining to reach goal of $" << GOAL << endl;
}



//Case 2 Function
void showHighestEarned(string participants[], double earnings[], int size) {
	int index = 0;
	double highest = earnings[index];

	for (int i = 0; i < size; i++) {
		if (earnings[i] > highest) {
			index = i;
		}
	}

	cout << "        The the fundraiser winner is " << participants[index] << endl << 
		    "        with a total earnings of " << "$" << earnings[index] << ".00" << endl;
}

//Case 3 Function
void saveValues(string participants[], double earnings[], int size) {
	ofstream outFile;
	outFile.open("fundraisers.txt");
	for (int i = 0; i < size; i++) {
		// name
		outFile << participants[i] << endl;
		// earning
		outFile << earnings[i] << endl;
	}
	outFile.close();

	cout << "          Data was saved to file named 'fundraisers.txt'" << endl;
}

//Case 4 Function
void loadValues(string participants[], double earnings[], int size) {
	ifstream inFile;
	inFile.open("fundraisers.txt");
	string name;
	double earning;
	int i = 0;
	while (getline(inFile, name)) {
		inFile >> earning;
		participants[i] = name;
		earnings[i] = earning;
		inFile.ignore();
		i++;
	}

	inFile.close();

	for (int participantNum = 0; participantNum < size; participantNum++)
	{
		cout << "         " << participants[participantNum] << "   $" << earnings[participantNum] << endl;
	}
}


// Menu Selection
int getSelection() {
	int choice;
	cout << endl;
	cout << "         Enter menu option: ";
	cin >> choice;
	cout << endl;
	while (choice < 1 || choice > 5) {
		cout << "         Error, enter an option between 1 and 5: ";
		cin >> choice;
		cout << endl;
	}
	cout << endl;
	return choice;
}


