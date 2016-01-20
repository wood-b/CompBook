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
    //checks the first two atoms
    if (m_back_list[0] == 1 && m_back_list[1] == 1) {
        //placing first atom at the origin
        m_back_coord.setAtom_xyz (0.0, 0.0, 0.0);
        //align first bond along x-axis
        m_back_coord.setAtom_xyz (1.5075, 0.0, 0.0);
    }

    else {
        std::cout << "first 2 atoms don't match" << std::endl;
    }
    double rot_angle = 0.0;
    //set atom positions based on a translation and rotation about the z axis
    for (unsigned int i=2; i < m_back_list.size(); i++) {
        int prev_atom = (i - 1);
        double dist, x_coord, y_coord, z_coord, bond_angle;
        //set bond specific data
        if (m_back_list[i] == 1 && m_back_list[prev_atom] == 1) {
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
        x_coord += m_back_coord.atom_x(prev_atom);
        y_coord += m_back_coord.atom_y(prev_atom);
        z_coord += m_back_coord.atom_z(prev_atom);
        //distance check
        double dist_check;
        dist_check = sqrt(pow(x_coord - m_back_coord.atom_x(prev_atom), 2.0) + 
                pow(y_coord - m_back_coord.atom_y(prev_atom), 2.0) + 
                pow(z_coord - m_back_coord.atom_z(prev_atom), 2.0));
        if (dist_check >= (dist - 0.1) && dist_check <= (dist + 0.1)) {
            //keeping track of backbone atom coords for relax
            m_back_coord.setAtom_xyz(x_coord, y_coord, z_coord);
        }
        else {
            std::cout << "distance check failed" << std::endl;
        }

    }
    
}

void chain_info::add_hydrogens() {
    for (unsigned int i=0; i < m_back_list.size(); i++) {
        m_atom_list.push_back(m_back_list[i]);
        m_atom_coord.setAtom_xyz(m_back_coord.atom_x(i), 
                m_back_coord.atom_y(i), 
                m_back_coord.atom_z(i)); 
        double h1_x, h1_y, h1_z, h2_x, h2_y, h2_z;
        //odd case
        if (m_back_list[i] == 1 && i % 2 != 0) {
            h1_x = consts::oh1_x + m_back_coord.atom_x(i);
            h1_y = consts::oh1_y + m_back_coord.atom_y(i);
            h1_z = consts::oh1_z + m_back_coord.atom_z(i);
            m_atom_coord.setAtom_xyz(h1_x, h1_y, h1_z);
            h2_x = consts::oh2_x + m_back_coord.atom_x(i);
            h2_y = consts::oh2_y + m_back_coord.atom_y(i);
            h2_z = consts::oh2_z + m_back_coord.atom_z(i);
            m_atom_coord.setAtom_xyz(h2_x, h2_y, h2_z);
            m_atom_list.push_back(2);
            m_atom_list.push_back(2);
        }
        //even case
        else if (m_back_list[i] == 1 && i % 2 == 0) {
            h1_x = consts::eh1_x + m_back_coord.atom_x(i);
            h1_y = consts::eh1_y + m_back_coord.atom_y(i);
            h1_z = consts::eh1_z + m_back_coord.atom_z(i);
            m_atom_coord.setAtom_xyz(h1_x, h1_y, h1_z);
            h2_x = consts::eh2_x + m_back_coord.atom_x(i);
            h2_y = consts::eh2_y + m_back_coord.atom_y(i);
            h2_z = consts::eh2_z + m_back_coord.atom_z(i);
            m_atom_coord.setAtom_xyz(h2_x, h2_y, h2_z);
            m_atom_list.push_back(2);
            m_atom_list.push_back(2);
        }
        else {
        }

    }

    //Terminal hydrogens start of chain
    m_atom_coord.insertAtom_xyz(1, -0.35666, 1.00881, 0.00000);
    m_atom_list.insert(m_atom_list.begin() + 1, 2);
    //Terminal hydrogens end of chain
    m_atom_coord.setAtom_xyz(164.39183, -117.51879, 0.00756);
    m_atom_list.push_back(2);
    //std::cout << m_atom_list.size() << std::endl;
    
}

/*void chain_info::write_relaxChain() {
    for (unsigned int i=0; i < m_tor_list.size(); i++) {
        double tor_angle;
        if (m_tor_list[i] == 0) {
            tor_angle = 0.0;
        }
        else if (m_tor_list[i] == 1) {
            tor_angle = ((2.0 * consts::pi) / 3.0);
        }
        else {
            tor_angle = (-(2.0 * consts::pi) / 3.0);
        }
        if (tor_angle != 0.0) {
            //axis of rotation - unit vector
            double uv_x, uv_y, uv_z, uv_mag;
            uv_x = m_back_coord.atom_x(i + 1) - m_back_coord.atom_x(i + 2);
            uv_y = m_back_coord.atom_y(i + 1) - m_back_coord.atom_y(i + 2);
            uv_z = m_back_coord.atom_z(i + 1) - m_back_coord.atom_z(i + 2);
            uv_mag = sqrt((uv_x * uv_x) + (uv_y * uv_y) + (uv_z * uv_z));
            uv_x /= uv_mag;
            uv_y /= uv_mag;
            uv_z /= uv_mag;
            //rotation matrix
            double sn, cs, l_cs;
            sn = sin(tor_angle);
            cs = cos(tor_angle);
            l_cs = 1 - cs;
            std::vector <double> rot_mat;
            rot_mat.push_back(l_cs * uv_x * uv_x + cs);
            rot_mat.push_back(l_cs * uv_x * uv_y + sn * uv_z);
            rot_mat.push_back(l_cs * uv_x * uv_z - sn * uv_y);
            rot_mat.push_back(l_cs * uv_x * uv_y - sn * uv_z);
            rot_mat.push_back(l_cs * uv_y * uv_y + cs);
            rot_mat.push_back(l_cs * uv_y * uv_z + sn * uv_x);
            rot_mat.push_back(l_cs * uv_z * uv_x + sn * uv_y);
            rot_mat.push_back(l_cs * uv_z * uv_y - sn * uv_x);
            rot_mat.push_back(l_cs * uv_z * uv_z + cs);
            //translate coordinates 2rd atom origin
            double trans_x, trans_y, trans_z;
            trans_x = m_atom_coord.atom_x(i + 1);
            trans_y = m_atom_coord.atom_y(i + 1);
            trans_z = m_atom_coord.atom_z(i + 1);
            //loop over atoms affected by tor_angle change
            for (unsigned int j=(i + 3); j < m_atom_list.size(); j++){
                //NEED to include H-atoms in the loop
                //This only works if atoms are in sequential order 
                double t_x, t_y, t_z, new_x, new_y, new_z;
                //translate
                t_x = m_atom_coord.atom_x(j) - trans_x;
                t_y = m_atom_coord.atom_y(j) - trans_y;
                t_z = m_atom_coord.atom_z(j) - trans_z;
                //rotate
                new_x = t_x * rot_mat[0] + t_y * rot_mat[1] + t_z * rot_mat[2];
                new_y = t_x * rot_mat[3] + t_y * rot_mat[4] + t_z * rot_mat[5];
                new_z = t_x * rot_mat[6] + t_y * rot_mat[7] + t_z * rot_mat[8];
                //translate back to original origin
                new_x += trans_x;
                new_y += trans_y;
                new_z += trans_z;
                //replace old coordinate
                int k = j;
                m_atom_coord.replaceAtom_xyz(k, new_x, new_y, new_z);
            }
        }
        else {
            continue;
        }
    }
}*/

void chain_info::print_xyz() {
    unsigned int print_size;
    std::vector<int> *atoms;
    cart_coord *print_coord;
    if (m_atom_list.size() == 0) {
        print_size = m_back_list.size();
        atoms = &m_back_list;
        print_coord = &m_back_coord;
    }
    else {
        print_size = m_atom_list.size();
        atoms = &m_atom_list;
        print_coord = &m_atom_coord;
    }
    std::ofstream polymer_xyz;
    polymer_xyz.open("./data/polymer.xyz");
    polymer_xyz << print_size << std::endl;
    polymer_xyz << "polymer molecule in angstroms" << std::endl;
    for (unsigned int i=0; i < print_size; i++) {
        if (atoms->at(i) == 1) {
            polymer_xyz << "C " << print_coord->atom_x(i) << " " <<
                print_coord->atom_y(i) << " " << 
                print_coord->atom_z(i) << std::endl;
        }
        else if (atoms->at(i) == 2) {
            polymer_xyz << "H " << print_coord->atom_x(i) << " " <<
                print_coord->atom_y(i) << " " << 
                print_coord->atom_z(i) << std::endl;
        }
            
        else {
            polymer_xyz << "O " << print_coord->atom_x(i) << " " <<
                print_coord->atom_y(i) << " " << 
                print_coord->atom_z(i) << std::endl;
        }
    }
    polymer_xyz.close();

}

void chain_info::ete_dist() {
    unsigned int last_atom = m_back_list.size() - 1;
    double dist;
    dist = sqrt(pow(m_back_coord.atom_x(last_atom) - 
                m_back_coord.atom_x(0), 2.0) + 
            pow(m_back_coord.atom_y(last_atom) - m_back_coord.atom_y(0), 2.0) + 
            pow(m_back_coord.atom_z(last_atom) - m_back_coord.atom_z(0), 2.0));
    std::cout << dist << std::endl;
}
    


