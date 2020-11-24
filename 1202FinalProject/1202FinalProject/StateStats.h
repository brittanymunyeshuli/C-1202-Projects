#pragma once

#include <string>

using namespace std;

class StateStats

{
private:
	string stateName;
	int confirmed;
	int recovered;
	int dead;
	double deathRate;
	double recoveryRate;
public:
	StateStats();
	StateStats(string stateName, int confirmed, int recovered, int dead);

	// State Name
	void setStateName(string stateNameIn);
	string getStateName();

	// Confirmed Cases
	void setConfirmed(int confirmedIn);
	int getConfirmed();

	// Recovered
	void setRecovered(int recoveredIn);
	int getRecovered();

	// Death
	void setDeaths(int deadIn);
	int getDead();

	// Death Rate
	double calcDeathRate();
	double calcRecoveryRate();

	// Display Stats
	void displayStats();

	~StateStats();
};