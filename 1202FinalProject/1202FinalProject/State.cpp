#include <iostream>
#include "State.h"

State::State() : StateStats() {
	totPresumed = -1;
}

State::State(string stateNameIn, int confirmedIn, int recoveredIn, int deadIn, int tot)
	: StateStats(stateNameIn, confirmedIn, recoveredIn, deadIn)
{
	totPresumed = tot;
}

int State::getPresumed() {
	return totPresumed;
}

void State::setPresumed(int tot) {
	totPresumed = tot;
}

void State::displayStats()
{
	StateStats::displayStats();
	cout << "    Presumed cases: " << totPresumed << endl;
	cout << "***********************************" << endl;
	cout << endl;
}

State::~State()
{
}
