#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class matrix {
    private:
        std::vector< std::vector<double> > m_matrix;
        std::vector<double> m_rowI, m_rowJ, m_rowK;
    public:
        matrix ();
        matrix (std::vector<double> vec);
        double& elementValue(int i, int j);
        std::vector< std::vector<double> >& getMatrix(); 

};

#endif
