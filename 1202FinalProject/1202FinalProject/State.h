#pragma once
#include "StateStats.h"

class State : public StateStats
{
private:
	int totPresumed;

public:
	State();
	State(string stateName, int confirmed, int recovered, int dead, int totPresumed);

	int getPresumed();
	void setPresumed(int tot);

	void displayStats();

	~State();
};
