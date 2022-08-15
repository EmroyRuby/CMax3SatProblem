#include "CSolution.h"


CSolution::CSolution(){
	
}

CSolution::CSolution(int n, bool bRand){
	v_solution_list = std::vector<bool>(n);
	if (bRand) {
		vRandomize(n);
	}
}

CSolution::CSolution(int n, CMax3SatProblem cProblem){
	vRandomize(n);
	fitness = vFitness(cProblem);
}

void CSolution::vRandomize(int n){
	std::uniform_real_distribution<double> distribution(0, 2);
	std::random_device rd;
	std::mt19937 eng(rd());

	v_solution_list.clear();
	for (int i = 0; i < n; i++){
		if ( distribution(eng) > 1){
			v_solution_list.push_back(true);
		}
		else{
			v_solution_list.push_back(false);
		}
	}
}

std::vector<bool> CSolution::vGet(){
	return v_solution_list;
}

void CSolution::vPrint(){
	for (bool i : v_solution_list){
		std::cout << i;
	}
	std::cout << '\n';
}

void CSolution::operator=(CSolution pcOther){
	for (int i = 0; i < pcOther.v_solution_list.size(); i++) {
		v_solution_list.at(i) = pcOther.v_solution_list.at(i);
	}
}

void CSolution::vMutate(double dProbability){
	std::uniform_real_distribution<double> distribution(0, 1);
	std::random_device rd;
	std::mt19937 eng(rd());

	for (int i = 0; i < v_solution_list.size(); i++){
		if ( distribution(eng) < dProbability){
			v_solution_list.at(i) = !v_solution_list.at(i);
		}
	}
}

std::tuple<CSolution, CSolution> CSolution::tCross(CSolution cParent1, CSolution cParent2){
	int iSize = cParent1.vGet().size();
	std::uniform_real_distribution<double> distribution(0, 2);
	std::random_device rd;
	std::mt19937 eng(rd());
	
	CSolution cChild1 = CSolution(iSize, false);
	CSolution cChild2 = CSolution(iSize, false);
	for (int i = 0; i <iSize; i++){
		if (distribution(eng) < 1){
			cChild1.v_solution_list[i] = cParent1.vGet()[i];
			cChild2.v_solution_list[i] = cParent2.vGet()[i];
		}
		else {
			cChild1.v_solution_list.at(i) = cParent2.vGet().at(i);
			cChild2.v_solution_list.at(i) = cParent1.vGet().at(i);
		}
		
	}
	return std::make_tuple(cChild1, cChild2);
}

double CSolution::vFitness(CMax3SatProblem cProblem){
	return cProblem.iCompute(v_solution_list);
}

double CSolution::dGetFitness() {
	return fitness;
}

void CSolution::vSetFitness(double val){
	fitness = val;
}