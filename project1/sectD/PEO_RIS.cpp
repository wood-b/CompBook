#include <iostream>
#include "PEO_RIS.h"

//Flory data, specific to PEO
//constructor
PEO_bond::PEO_bond(std::vector<double> U, std::vector<double> A, double lamda)
{
    m_U = U;
    m_A = A;
    m_lamda = lamda;
}

std::vector<double>& PEO_bond::Umatrix()
{
    return m_U;
}
std::vector<double>& PEO_bond::Amatrix()
{
    return m_A;
}
double& PEO_bond::lamdaValue()
{
    return m_lamda;
}

