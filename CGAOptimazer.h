#pragma once
#include <vector>
#include "CSolution.h"
#include "CMax3SatProblem.h"
class CGAOptimazer{

public:
	CGAOptimazer(int iNewSize, int iNewRange, double dNewProbabilityOfCrossing, 
		double dNewProbabilityOfMutation, CMax3SatProblem cNewProblem);

	void vInitialize();
	void vRunIteration();
	CSolution cChooseParent();
	void vPrint();
	void vCalculate();

private:
	int iSize;
	int iRange;
	double dProbabilityOfCrossing;
	double dProbabilityOfMutation;
	std::vector<CSolution> vSolutionList;
	CMax3SatProblem cProblem;
};

