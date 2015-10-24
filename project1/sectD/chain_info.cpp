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

void chain_info::write() {
    //checks the first three atoms
    if (m_atom_list[0] == 1 && m_atom_list[1] == 1 && m_atom_list[2] == 0) {
        //placing first atom at the origin
        m_atom_coord.setAtom_xyz (0.0, 0.0, 0.0);
        //align first bond along x-axis
        m_atom_coord.setAtom_xyz (1.5075, 0.0, 0.0);
        m_atom_coord.setAtom_xyz (2.65332, -0.824268, 0.0);
    }

    else {
        std::cout << "first 3 atoms don't match" << std::endl;
    }
    //set atom positions using tor_list
    /*for each new atom set xy plane on same plane as prev 3 atoms with prev 
    atom as the origin, calc the coords from new origin and add it to the prev
    atom coords to recover the original coords*/
    for (unsigned int i=3; i < m_atom_list.size(); i++) {
        int prev_atom = (i - 1);
        double dist,x_coord, y_coord, z_coord, xy_proj, tor_angle, bond_angle;
        //set tor_angle
        if (m_tor_list[i-3] == 0) {
            tor_angle = 0.0;
        }
        else if (m_tor_list[i-3] == 1) {
            tor_angle = (consts::pi / 3);
        }
        else if (m_tor_list[i-3] == 2) {
            tor_angle = (-consts::pi / 3);
        }
        else {
            std::cout << "something is wrong with the tor_list" << std::endl;
        }
        //set bond specific data
        if (m_atom_list[i] == 1 && m_atom_list[prev_atom] == 1) {
            dist = consts::cc_dist;
            bond_angle = consts::cco_angle;
        }
        else {
            dist = consts::co_dist;
            bond_angle = consts::coc_angle;
        }
        xy_proj = dist * cos(tor_angle);
        x_coord = xy_proj * sin(bond_angle / 2);
        y_coord = xy_proj * cos(bond_angle / 2);
        if (tor_angle > 0.0) {
            z_coord = dist * -sin(tor_angle);
        }
        else if (tor_angle < 0.0) {
            z_coord = dist * sin(tor_angle);
        }
        else {
            z_coord = 0.0;
        }

















    }



}

