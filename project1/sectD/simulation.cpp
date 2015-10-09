#include "simulation.h"
#include <iostream>

//simulation::simulation() { } see header
simulation::simulation(const RIS_params& co, const RIS_params& oc, 
        const RIS_params& cc): m_co(co), m_oc(oc), m_cc(cc) { }
 
void simulation::build() {
    //this is a hack std lib doesn't like loops, **not general**
    //carbon atoms -> 1 oxygen atoms -> 0
    for (int i; i < consts::deg_poly; i++) {
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
    

}



