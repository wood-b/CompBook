#include <iostream>
#include "RIS_model.h"
#include "constants.h"
#include "simulation.h"

int main () {

    //initialize RIS parameters with PEO data
    //RIS_params* co = new RIS_params
    RIS_params co(consts::co_statWt, consts::co_eigenvec, 
        consts::co_eigenval);
    RIS_params oc(consts::oc_statWt, consts::oc_eigenvec, 
        consts::oc_eigenval);
    RIS_params cc(consts::cc_statWt, consts::cc_eigenvec, 
        consts::cc_eigenval);
    //initialize PEO chain with 1st 3 atoms and torsion angle
    simulation PEO1(co, oc, cc);
    PEO1.build();
    PEO1.run();

    
    //std::cout<< cc.statWtMatrix().elementValue(2,2) << std::endl;
    std::cout<< PEO1.atom_list().size() << std::endl;
    std::cout<< PEO1.tor_list().size() << std::endl;
    for (unsigned int l=0; l < PEO1.tor_list().size(); l++){
        std::cout << PEO1.tor_list()[l] << std::endl;
    }
    
    return 0;
}

