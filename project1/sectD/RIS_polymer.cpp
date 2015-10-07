#include <iostream>
#include "RIS_model.h"
#include "constants.h"

int main ()
{

    RIS_params co = {consts::co_statWt, consts::co_eigenvec, 
        consts::co_eigenval};
    RIS_params oc = {consts::oc_statWt, consts::oc_eigenvec, 
        consts::oc_eigenval};
    RIS_params cc = {consts::cc_statWt, consts::cc_eigenvec, 
        consts::cc_eigenval};
    
    std::cout<< cc.statWtMatrix().elementValue(2,2) << std::endl;
    
    return 0;
}

