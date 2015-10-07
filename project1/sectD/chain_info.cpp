#include <iostream>
#include "chain_info.h"

chain_info::chain_info() {

}

std::vector<int>& chain_info::atom_list() {
    return m_atom_list;
}

void chain_info::add_atoms(std::vector<int> atoms) {
    for (unsigned int i; i <= atoms.size(); i++) {
        m_atom_list.push_back(atoms[i]);
    }
}

std::vector<int>& chain_info::tor_list() {
    return m_tor_list;
}

void chain_info::add_tor(int torsion) {
    m_tor_list.push_back(torsion);
}

