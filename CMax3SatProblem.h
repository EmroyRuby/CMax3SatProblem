#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "CClause.h"
class CMax3SatProblem{

public:
	CMax3SatProblem();

	void vLoad(std::string sFile);
	double iCompute(std::vector <bool> v_solution_list);
	void vPrint();

private:
	std::vector <CClause> v_list_of_clause;
};

