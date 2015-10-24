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

/*int main() {
    cart_coord test;
    test.setAtom_xyz(0.0, 0.0, 0.0);
    test.setAtom_xyz(0.0, 1.5, 0.0);
    test.setAtom_x(0.2);
    test.setAtom_y(2, 0.3);
    test.setAtom_z(2, 0.4);
    for (int i; i < 3; i++) {
        std::cout << test.atom(2)[i] << std::endl;
    }

    return 0;
}*/


