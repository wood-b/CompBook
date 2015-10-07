#include <iostream>
#include "matrix.h"
#include <cmath>

matrix::matrix() {
}

matrix::matrix(std::vector<double> vec) {
    //not generalized only works for square 3x3 matrix
    for (int i=0; i < 3; i++) {
        m_rowI.push_back(vec[i]);
        m_rowJ.push_back(vec[i+3]);
        m_rowK.push_back(vec[i+6]);

    }
    
    m_matrix= {m_rowI, m_rowJ, m_rowK};
    //std::cout << m_matrix.at(2).at(1) << std::endl;
}

double& matrix::elementValue(int i, int j) {
    return m_matrix[i][j];
}
std::vector< std::vector <double> >& matrix::getMatrix() {
    return m_matrix;
}


