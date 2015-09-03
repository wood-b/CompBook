#ifndef PEO_RIS_H
#define PEO_RIS_H

#include <vector>

class PEO_bonds 
{
    private:
        const std::vector<double> U;

    public:
        //constructor
        PEO_bonds(const std::vector<double> u); 

        const std::vector<double>& Umatrix() const { return U; }
};

#endif
