#ifndef RIS_MODEL_H
#define RIS_MODEL_H

#include <vector>
#include "matrix.h"

class RIS_params {
    private:
        matrix m_statWt;
        //U is stat weight matrix
        matrix m_eigenvec;
        //A is eigenvector matrix
        double m_eigenval;
        //lamda is the largest eigenvalue
    public:
        RIS_params (/*const*/ std::vector<double>& U, /*const*/ std::vector<double>& A, 
                /*const*/ double& lamda);
        matrix& statWtMatrix();
        matrix& eigenvectors();
        double& eigenvalue();
};

#endif
