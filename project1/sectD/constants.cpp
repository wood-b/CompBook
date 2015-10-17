#include "constants.h"

consts::consts() {}

//PEO CO bond data
std::vector<double> consts::co_statWt = {1.0, 0.22, 0.22, 1.0, 0.22, 0.12452, 
    1.0, 0.12452, 0.22};
std::vector<double> consts::co_eigenvec = {0.602509, 0.279784, 0.0, 0.564351, 
    -0.678867, -0.707107, 0.564351, -0.678867, 0.707107};
double consts::co_eigenval = 1.41213;
//PEO OC bond data
std::vector<double> consts::oc_statWt = {1.0, 0.22, 0.22, 1.0, 0.22, 0.0, 
    1.0, 0.0, 0.22};
std::vector<double> consts::oc_eigenvec ={0.634022, 0.259165, 0.0, 0.546816,
    -0.682947, -0.707107, 0.546816, -0.682947, 0.707107};
double consts::oc_eigenval = 1.37948;
//PEO CC bond data
std::vector<double> consts::cc_statWt = {1.0, 2.07, 2.07, 1.0, 2.07, 1.17162,
    1.0, 1.17162, 2.07};
std::vector<double> consts::cc_eigenvec ={0.647675, -0.925039, 0.0, 0.538757,
    0.268611, -0.707107, 0.538757, 0.268611, 0.707107};
double consts::cc_eigenval = 4.44379;

int consts::deg_poly = 20;
std::vector<int> consts::monomer_atoms = {1, 1, 0};
int consts::mono_length = 3;
