#include "simulation.h"
#include <iostream>

simulation::simulation() { }

void simulation::build() {
    //this is a hack std lib doesn't like loops, **not general**
    //carbon atoms -> 1 oxygen atoms -> 0
    for (int i=0; i < consts::deg_poly; i++) {
        m_atom_list.push_back(1);
        m_atom_list.push_back(1);
        m_atom_list.push_back(0);
    }
    /*m_atom_list.insert(m_atom_list.end(), consts::monomer_atoms.begin(),
            consts::monomer_atoms.end());*/
    /*std::copy(consts::monomer_atoms.begin(), consts::monomer_atoms.end(), 
            std::back_inserter(m_atom_list));*/
    //add terminal atoms
    m_atom_list.push_back(1);
    m_atom_list.push_back(1);
    //insert first torsion angle
    //trans -> 0; +gauche -> 1; -gauche -> 2
    m_tor_list.push_back(0);
}

void simulation::cond_prob(int prev_atom, int atom, int prev_tor) {
    m_cond_prob.clear();
    matrix statWt, evec;
    double eval;
    if (prev_atom == 1 && atom == 0) {
        statWt = consts::co_statWt;
        evec = consts::co_eigenvec;
        eval = consts::co_eigenval;
    }
    else if (prev_atom == 0 && atom == 1) {
        statWt = consts::oc_statWt;
        evec = consts::oc_eigenvec;
        eval = consts::oc_eigenval;
    }
    else if (prev_atom == 1 && atom == 1) {
        statWt = consts::cc_statWt;
        evec = consts::cc_eigenvec;
        eval = consts::cc_eigenval;
    }
    else {
        std::cout << "atom list is incorrect" << std::endl;
        eval = 0.0;
    }
    //calculate conditional probabilities
    for (int j=0; j < 3; j++) {
            m_cond_prob.push_back((statWt.elementValue(prev_tor,j) * 
                    evec.elementValue(j,0)) / 
                    (evec.elementValue(prev_tor,0) * eval));
    }
    //debugging print statement
    /*for (int k=0; k < 3; k++) {
        std::cout << m_cond_prob[k] << std::endl;
    }*/

}

void simulation::monte_carlo(double rand_num) {
    //std::cout << rand_num << std::endl;
    //assigns cond prob of trans with real # b/w [0,1)
    if (rand_num >= 0.0 && rand_num < m_cond_prob[0]){
        m_tor_list.push_back(0);
    }
    //assigns cond prob of +gauche  with real # b/w [q(Trans),1)
    else if (rand_num >= m_cond_prob[0] && rand_num < (m_cond_prob[0] + 
                m_cond_prob[1])) {
        m_tor_list.push_back(1);
    }
    //assigns remaining real #s to -gauche 
    else if (rand_num >= (m_cond_prob[0] + m_cond_prob[1]) && 
            rand_num < 1.0){
        m_tor_list.push_back(2);
    }
    else {
        std::cout << "something went wrong with cond prob" << std::endl;
    }

}

void simulation::run() {
    //generate a time based seed
    unsigned long int t_seed = std::chrono::high_resolution_clock::
        now().time_since_epoch().count();
    std::mt19937 generator (t_seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    //std::cout << t_seed << std::endl;
    //loop for generating tor angles
    //starts at 3rd atom -> n-1
    for (unsigned int n=3; n < (m_atom_list.size()-1); n++) {
        cond_prob(m_atom_list[n-1], m_atom_list[n], m_tor_list[n-3]);
        double rand_num = dist(generator);
        //std::cout << rand_num << std::endl;
        monte_carlo(rand_num);
    }
}

    
