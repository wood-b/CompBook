#ifndef CHAIN_INFO_H
#define CHAIN_INFO_H

#include <vector>
#include "cart_coord.h"
#include "constants.h"
#include <cmath>
#include <iostream>
#include <fstream>

class chain_info {
    protected:
        std::vector<int> m_back_list; //list of backbone atoms
        std::vector<int> m_atom_list; //list of atoms in the polymer
        std::vector<int> m_tor_list; //list of torsion angles define poly
        cart_coord m_atom_coord;
        cart_coord m_back_coord;
    public:
        chain_info(); //default constructor
        std::vector<int>& atom_list(); //return atom list
        void add_atoms(std::vector<int> atoms); //add atoms to list
        std::vector<int>& tor_list(); //return tor list
        void add_tor(int torsion);
        void write_linearChain();
        void add_hydrogens();
        void write_relaxChain();
        void print_xyz();
        void ete_dist();
};

#endif
