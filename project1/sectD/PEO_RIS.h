#ifndef PEO_RIS_H
#define PEO_RIS_H

#include <vector>

class PEO_bond  
{
    private:
        std::vector<double> m_U;
        //U is stat weight matrix
        std::vector<double> m_A;
        //A is eigenvector matrix
        double m_lamda;
        //lamda is the largest eigenvalue
    public:
        PEO_bond (std::vector<double> U, std::vector<double> A, double lamda);
        std::vector<double>& Umatrix();
        std::vector<double>& Amatrix();
        double& lamdaValue();
};

#endif
