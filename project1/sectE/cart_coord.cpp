#include "cart_coord.h"
#include <iostream>

cart_coord::cart_coord() {}

std::vector<double>& cart_coord::atom(int n) {
    return m_coord[n];
}

void cart_coord::setAtom_xyz(double x, double y, double z) {
    std::vector<double> xyz = {x, y, z};
    m_coord.push_back(xyz);
}

double& cart_coord::atom_x(int n) {
    return m_coord[n][0];
}
double& cart_coord::atom_y(int n) {
    return m_coord[n][1];
}    
double& cart_coord::atom_z(int n) {
    return m_coord[n][2];
}
//must write x coordinate first
void cart_coord::setAtom_x(double x) {
    std::vector<double> x1 = {x};
    m_coord.push_back(x1);
}
void cart_coord::setAtom_y(int n, double y) {
    m_coord.at(n).push_back(y);
}
void cart_coord::setAtom_z(int n, double z) {
    m_coord.at(n).push_back(z);
}

void cart_coord::replaceAtom_xyz(int n, double x, double y, double z) {
    std::vector<double> new_xyz = {x, y, z};
    m_coord.at(n) = new_xyz;
}

void cart_coord::insertAtom_xyz(int n, double x, double y, double z) {
    std::vector<double> insert_xyz = {x, y, z};
    //n+1 so it inserts after the desired position
    m_coord.insert(m_coord.begin()+n, insert_xyz);
}

/*int main() {
    cart_coord test;
    test.setAtom_xyz(0.0, 0.0, 0.0);
    test.setAtom_xyz(0.0, 1.5, 0.0);
    test.setAtom_x(0.2);
    test.setAtom_y(2, 0.3);
    test.setAtom_z(2, 0.4);
    test.insertAtom_xyz(3, 12.1, 12.2, 12.3);
    for (int i; i < 4; i++) {
        //std::cout << test.atom_x(i) << test.atom_y(i) << test.atom_z(i) << std::endl;
        std::cout << test.atom(i)[0] << test.atom(i)[1] << test.atom(i)[2] << std::endl;
    }

    return 0;
}*/

