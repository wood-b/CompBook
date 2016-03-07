#ifndef CART_COORD_H
#define CART_COORD_H

#include <vector>

class cart_coord {
    private:
        std::vector< std::vector<double> > m_coord;
    public:
        cart_coord ();

        std::vector<double>& atom(int n);
        void setAtom_xyz(double x, double y, double z);
        double& atom_x(int n);
        double& atom_y(int n);
        double& atom_z(int n);
        void setAtom_x(double x);
        void setAtom_y(int n, double y);
        void setAtom_z(int n, double z);
        void replaceAtom_xyz(int n, double x, double y, double z);
        void insertAtom_xyz(int n, double x, double y, double z);

};

#endif
