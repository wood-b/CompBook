#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <random>
#include "matrix.h"
#include "chain_info.h"
#include "RIS_model.h"
#include "constants.h"

class simulation: public chain_info {
    private:

        const RIS_params m_co;
        const RIS_params m_oc;
        const RIS_params m_cc;
        std::vector<double> cond_prob(matrix statWt, matrix eigenvec, 
                double eigenval);
        //int monte_carlo(

    public:
        //simulation(); NO default constructor with const member var
        simulation(const RIS_params& co, const RIS_params& oc, const RIS_params& cc);
        void build(); 

};

#endif
