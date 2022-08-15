#include <iostream>
#include "CMax3SatProblem.h"
#include "CSolution.h"
#include "CGAOptimazer.h"

int main() {
    CMax3SatProblem problem = CMax3SatProblem();
    problem.vLoad("350/m3s_350_0.txt");
    CGAOptimazer lista_rozwiazan = CGAOptimazer(20, 350, 0.7, 0.01, problem);
    lista_rozwiazan.vInitialize();
    for (int i = 0; i < 100; i++) {
        lista_rozwiazan.vRunIteration();
        lista_rozwiazan.vCalculate();
    }
}
