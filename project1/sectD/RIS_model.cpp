#include <iostream>
#include "RIS_model.h"
#include "matrix.h"

//Flory data
//constructor
RIS_params::RIS_params(std::vector<double> U, std::vector<double> A, double lamda) 
: m_statWt(U), m_eigenvec(A), m_eigenval(lamda) {
   /* m_U = U;
    m_A = A;
    m_lamda = lamda;*/
}

matrix& RIS_params::statWtMatrix() {
    return m_statWt;
}
matrix& RIS_params::eigenvectors() {
    return m_eigenvec;
}
double& RIS_params::eigenvalue() {
    return m_eigenval;
}

