#include "CMax3SatProblem.h"

CMax3SatProblem::CMax3SatProblem(){

}

void CMax3SatProblem::vLoad(std::string sFile){
	std::string sText;
	std::ifstream fFile(sFile);
	while (std::getline (fFile, sText)){
		int iStart = 0;
		int iEnd = sText.find(" ");
		int iList[3];
		int iter = 0;
		while (iEnd != -1){
			std::string sSub = sText.substr(iStart, iEnd - iStart);
			if (sSub != "("){
				iList[iter] = stoi(sSub);
				iter++;
			}
			iStart = iEnd + 1;
			iEnd = sText.find("  ", iStart);
		}
		v_list_of_clause.push_back(CClause(iList));
	}
}
double CMax3SatProblem::iCompute(std::vector<bool> v_solution_list){
	
	double iCounter = 0;
	double iCountClauses = 0;
	for (CClause i : v_list_of_clause){
		if (i.bCompute(v_solution_list)) iCounter++;
		iCountClauses += 1;
	}
	return iCounter / iCountClauses;
	
}

void CMax3SatProblem::vPrint(){
	for (CClause i: v_list_of_clause){
		i.vPrint();
	}
}