#include <iostream>
#include "PEO_RIS.h"

//Flory data specific to PEO

int main()
{
    PEO_bonds CO = new PEO_bonds({{1.0, 0.22, 0.22, 1.0, 0.22, 0.12452, 1.0, 0.12452, 0.22}},
            {{0.602509, 0.279784, 0.0, 0.564351, -0.678867, -0.707107, 0.564351, 
            -0.678867, 0.707107}}, 1.413);
    std::cout << CO.Umatrix[3] << std::endl;

    return 0;
}
