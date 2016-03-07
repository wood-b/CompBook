#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <random>
#include "matrix.h"
#include "chain_info.h"
#include "constants.h"
#include <chrono>

class simulation: public chain_info {
    private:

        std::vector<double> m_cond_prob;

    public:
        simulation();
        void build();
        void cond_prob(int prev_atom, int atom, int prev_tor);
        void monte_carlo(double rand_num);
        void run();

};

#endif
