#include "CClause.h"

CClause::CClause(int x[3]) {
	for (int i = 0; i < 3; i++){
		vClause.push_back(x[i]);
	}
}

void CClause::vPrint(){
	for (int i: vClause){
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

bool CClause::bCompute(std::vector<bool> v_solution_list){

	bool bTab[3];
	int a, b, c;
	a = vClause.at(0);
	b = vClause.at(1);
	c = vClause.at(2);
	int iter = 0;
	if (a > 0) {
		bTab[0] = v_solution_list.at(a);
	}
	else{
		bTab[0] = !v_solution_list.at(-a);
	}
	if (b > 0) {
		bTab[1] = v_solution_list.at(b);
	}
	else {
		bTab[1] = !v_solution_list.at(-b);
	}
	if (c > 0) {
		bTab[2] = v_solution_list.at(c);
	}
	else {
		bTab[2] = !v_solution_list.at(-c);
	}
	for (bool i: bTab){
		if (i) return true;
	}
	return false;
}