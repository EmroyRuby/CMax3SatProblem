#include "CGAOptimazer.h"

CGAOptimazer::CGAOptimazer(int iNewSize, int iNewRange, double dNewProbabilityOfCrossing, 
	double dNewProbabilityOfMutation, CMax3SatProblem cNewProblem){
	iSize = iNewSize;
	iRange = iNewRange;
	dProbabilityOfCrossing = dNewProbabilityOfCrossing;
	dProbabilityOfMutation = dNewProbabilityOfMutation;
	cProblem = cNewProblem;
}

void CGAOptimazer::vInitialize(){
	for (int i = 0; i < iSize; i++){
		vSolutionList.push_back(CSolution(iRange, cProblem));
	}
}

CSolution CGAOptimazer::cChooseParent(){
	std::uniform_real_distribution<double> distribution(0, iSize);
	std::random_device rd;
	std::mt19937 eng(rd());

	std::vector<CSolution> turniej;

	for (int i = 0; i < 4; i++){
		int picked = floor(distribution(eng));
		turniej.push_back(vSolutionList.at(picked));
	}

	CSolution zw = turniej.at(0);
	for (int i = 1; i < 4; i++){
		if (zw.dGetFitness() < turniej.at(i).dGetFitness()){
			zw = turniej.at(i);
		}
	}
	return zw;
}

void CGAOptimazer::vRunIteration(){
	std::uniform_real_distribution<double> distribution(0, 1);
	std::random_device rd;
	std::mt19937 eng(rd());

	std::vector<CSolution> nowaPopulacja;

	while (nowaPopulacja.size() < vSolutionList.size()){
		CSolution cParent1 = cChooseParent();
		CSolution cParent2 = cChooseParent();
		CSolution cChild1 = CSolution(iRange, false);
		CSolution cChild2 = CSolution(iRange, false);
		if (distribution(eng) < dProbabilityOfCrossing){
			std::tuple<CSolution, CSolution> dzieci = cChild1.tCross(cParent1, cParent2);
			cChild1 = std::get<0>(dzieci);
			cChild2 = std::get<1>(dzieci);
		}
		else{
			cChild1 = cParent1;
			cChild2 = cParent2;
		}
		cChild1.vMutate(dProbabilityOfMutation);
		cChild2.vMutate(dProbabilityOfMutation);
		cChild1.vSetFitness(cChild1.vFitness(cProblem));
		cChild2.vSetFitness(cChild2.vFitness(cProblem));
		nowaPopulacja.push_back(cChild1);
		nowaPopulacja.push_back(cChild2);

	}
	vSolutionList.clear();
	for (int i = 0; i < nowaPopulacja.size(); i++){
		vSolutionList.push_back(nowaPopulacja.at(i));
	}
}

void CGAOptimazer::vPrint(){
	int j = 0;
	for (CSolution i: vSolutionList){
		std::cout << j << " ";
		i.vPrint();
		j++;
	}
}

void CGAOptimazer::vCalculate(){
	double iMax = 0;
	for (int i = 0; i < iSize; i++){
		double iRes = vSolutionList.at(i).dGetFitness();
		if (iRes > iMax){
			iMax = iRes;
		}
	}
	std::cout << "maximum: " << iMax << '\n';
}