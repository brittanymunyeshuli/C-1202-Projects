#include "StateStats.h"
#include <iostream>
#include <iomanip>

StateStats::StateStats() {
	string stateName = "";
	int confirmed = 0;
	int recovered = 0;
	int dead = 0;
	double deathRate = 0.0;
	double recoveryRate = 0.0;
}

StateStats::StateStats(string stateNameIn, int confirmedIn, int recoveredIn, int deadIn) {
	stateName = stateNameIn;
	confirmed = confirmedIn;
	recovered = recoveredIn;
	dead = deadIn;
}

// State Name
void StateStats::setStateName(string stateNameIn) {
	stateName = stateNameIn;
}
string StateStats::getStateName() {
	return stateName;
}

// Confirmed Cases
void StateStats::setConfirmed(int confirmedIn) {
	confirmed = confirmedIn;
}
int StateStats::getConfirmed() {
	return confirmed;
}

// Recovered
void StateStats::setRecovered(int recoveredIn) {
	recovered = recoveredIn;
}
int StateStats::getRecovered() {
	return recovered;
}

// Deaths
void StateStats::setDeaths(int deadIn) {
	dead = deadIn;
}
int StateStats::getDead() {
	return dead;
}

// Death Rate
double StateStats::calcDeathRate()
{
	deathRate = 100 * (double(dead) / confirmed);
	return deathRate;
}

// Recovery Rate
double StateStats::calcRecoveryRate()
{
	recoveryRate = 100 * (double(recovered) / confirmed);
	return recoveryRate;
}

// Display State Stats
void StateStats::displayStats()
{
	cout << "***********************************" << endl;
	cout << "       DATA FOR: " << getStateName() << endl;
	cout << "       Confirmed: " << getConfirmed() << endl;
	cout << "       Recovered: " << getRecovered() << endl;
	cout << "       Deaths:    " << getDead() << endl;
	cout << endl;
	cout << "       Death Rate:    " << setprecision(2) << fixed
		<< calcDeathRate() << "%" << endl;
	cout << "       Recovery Rate: " << setprecision(2) << fixed
		<< calcRecoveryRate() << "%" << endl;
}

StateStats::~StateStats()
{
}
