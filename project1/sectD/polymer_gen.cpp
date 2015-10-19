#include <iostream>
#include "constants.h"
#include "simulation.h"

int main () {

    //declare chain or chains
    simulation PEO1;
    //writes atom list for desired length and 1st tor ang
    PEO1.build();
    //runs simulation to generate tor ang list
    PEO1.run();

    
    //std::cout<< cc.statWtMatrix().elementValue(2,2) << std::endl;
    std::cout<< PEO1.atom_list().size() << std::endl;
    std::cout<< PEO1.tor_list().size() << std::endl;
    for (unsigned int l=0; l < PEO1.tor_list().size(); l++){
        std::cout << PEO1.tor_list()[l] << std::endl;
    }
    
    return 0;
}

