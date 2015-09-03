#include <iostream>
#include "PEO_RIS.h"

//Flory data specific to PEO

PEO_bonds::PEO_bonds(std::vector<double>& u) {
    U = u;
}


int main()
{
    PEO_bonds CO({1.0, 0.22, 0.22, 1.0, 0.22, 0.12452, 1.0, 0.12452, 0.22});
    std::cout << CO.Umatrix()[2] << std::endl;

    return 0;
}
