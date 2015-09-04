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

PEO_bond CO = 
{
    {1.0, 0.22, 0.22, 1.0, 0.22, 0.12452, 1.0, 0.12452, 0.22},
    {0.602509, 0.279784, 0.0, 0.564351, -0.678867, -0.707107, 0.564351, 
        -0.678867, 0.707107},
    1.41213
};

PEO_bond OC = 
{
    {1.0, 0.22, 0.22, 1.0, 0.22, 0.0, 1.0, 0.0, 0.22},
    {0.634022, 0.259165, 0.0, 0.546816, -0.682947, -0.707107, 0.546816, 
        -0.682947, 0.707107},
    1.37948
};
    
PEO_bond CC = 
{
    {1.0, 2.07, 2.07, 1.0, 2.07, 1.17162, 1.0, 1.17162, 2.07},
    {0.647675, -0.925039, 0.0, 0.538757, 0.268611, -0.707107, 0.538757, 
        0.268611, 0.707107},
    4.44379
};

int main ()
{
    std::cout << CC.lamdaValue() << std::endl;

    return 0;
}

