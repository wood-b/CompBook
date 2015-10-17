#ifndef CHAIN_INFO_H
#define CHAIN_INFO_H

#include <vector>

class chain_info {
    protected:
        std::vector<int> m_atom_list; //list of atoms in the polymer
        std::vector<int> m_tor_list; //list of torsion angles define poly
    public:
        chain_info(); //default constructor
        std::vector<int>& atom_list(); //return atom list
        void add_atoms(std::vector<int> atoms); //add atoms to list
        std::vector<int>& tor_list(); //return tor list
        void add_tor(int torsion);
};

#endif
