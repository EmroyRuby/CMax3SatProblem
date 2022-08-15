#pragma once
#include <vector>
#include <time.h>
#include <iostream>
#include <random>
#include <tuple>
#include <chrono>
#include <cstdlib>
#include "CMax3SatProblem.h"

class CSolution{

public:
	CSolution();
	CSolution(int n, bool bRand);
	CSolution(int n, CMax3SatProblem cProblem);

	void vRandomize(int n);
	std::vector <bool> vGet();
	void vPrint();
	void operator=(CSolution pcOther);
	void vMutate(double dProbability);
	std::tuple<CSolution, CSolution> tCross(CSolution cParent1, CSolution cParent2);
	double vFitness(CMax3SatProblem cProblem);
	double dGetFitness();
	void vSetFitness(double val);
private:
	std::vector<bool> v_solution_list;
	double fitness;
};