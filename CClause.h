#pragma once
#include <vector>
#include <iostream>
class CClause{

public:
	CClause(int x[3]);

	void vPrint();
	bool bCompute(std::vector <bool> v_solution_list);

private:
	std::vector <int> vClause;
};