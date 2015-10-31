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

void chain_info::write_linearChain() {
    //checks the first three atoms
    if (m_atom_list[0] == 1 && m_atom_list[1] == 1) {
        //placing first atom at the origin
        m_atom_coord.setAtom_xyz (0.0, 0.0, 0.0);
        //align first bond along x-axis
        m_atom_coord.setAtom_xyz (1.5075, 0.0, 0.0);
    }

    else {
        std::cout << "first 2 atoms don't match" << std::endl;
    }
    double rot_angle = 0.0;
    //set atom positions based on a translation and rotation about the z axis
    for (unsigned int i=2; i < m_atom_list.size(); i++) {
        int prev_atom = (i - 1);
        double dist, x_coord, y_coord, z_coord, bond_angle;
        //set bond specific data
        if (m_atom_list[i] == 1 && m_atom_list[prev_atom] == 1) {
            dist = consts::cc_dist;
            bond_angle = consts::cco_angle;
        }
        else {
            dist = consts::co_dist;
            bond_angle = consts::coc_angle;
        }
        if (rot_angle > (2 * consts::pi)) {
            rot_angle -= (2 * consts::pi);
        }
        else {
            rot_angle = rot_angle;
        }
        if (i % 2 == 0){
            rot_angle += (2 * consts::pi - (consts::pi - bond_angle));
        }
        else {
            rot_angle += (consts::pi - bond_angle);
        }
        //set atom along x-axis
        x_coord = dist;
        //rotation around z-axis
        y_coord = x_coord * sin(rot_angle);
        x_coord *= cos(rot_angle);
        z_coord = 0.0;
        //translate back to abs origin
        x_coord += m_atom_coord.atom_x(prev_atom);
        y_coord += m_atom_coord.atom_y(prev_atom);
        z_coord += m_atom_coord.atom_z(prev_atom);
        //distance check
        double dist_check;
        dist_check = sqrt(pow(x_coord - m_atom_coord.atom_x(prev_atom), 2.0) + 
                pow(y_coord - m_atom_coord.atom_y(prev_atom), 2.0) + 
                pow(z_coord - m_atom_coord.atom_z(prev_atom), 2.0));
        if (dist_check >= (dist - 0.1) && dist_check <= (dist + 0.1)) {
            m_atom_coord.setAtom_xyz(x_coord, y_coord, z_coord);
        }
        else {
            std::cout << "distance check failed" << std::endl;
        }

    }
    
}

void chain_info::print_xyz() {
    std::ofstream polymer_xyz;
    polymer_xyz.open("./data/polymer.xyz");
    polymer_xyz << m_atom_list.size() << std::endl;
    polymer_xyz << "polymer molecule in angstroms" << std::endl;
    for (unsigned int i=0; i < m_atom_list.size(); i++) {
        if (m_atom_list[i] == 1) {
            polymer_xyz << "C " << m_atom_coord.atom_x(i) << " " <<
                m_atom_coord.atom_y(i) << " " << 
                m_atom_coord.atom_z(i) << std::endl;
        }
        else {
            polymer_xyz << "O " << m_atom_coord.atom_x(i) << " " <<
                m_atom_coord.atom_y(i) << " " << 
                m_atom_coord.atom_z(i) << std::endl;
        }
    }
    polymer_xyz.close();

}



