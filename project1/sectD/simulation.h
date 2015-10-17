#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <random>
#include "matrix.h"
#include "chain_info.h"
#include "RIS_model.h"
#include "constants.h"
#include <chrono>

class simulation: public chain_info {
    private:

        const RIS_params m_co;
        const RIS_params m_oc;
        const RIS_params m_cc;
        std::vector<double> m_cond_prob;
        //int monte_carlo(

    public:
        //simulation(); NO default constructor with const member var
        simulation(RIS_params co, RIS_params oc, RIS_params cc);
        void build();
        void cond_prob(int prev_atom, int atom, int prev_tor);
        void monte_carlo(int seed);
        void run();

};

#endif
