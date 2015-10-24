#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>

class consts {
    public:
        consts();
        virtual ~consts() {}

        //This data is specific to PEO
        //co, oc, cc represent atoms
        static std::vector<double> co_statWt;
        static std::vector<double> co_eigenvec;
        static double co_eigenval;
        static std::vector<double> oc_statWt;
        static std::vector<double> oc_eigenvec;
        static double oc_eigenval;
        static std::vector<double> cc_statWt;
        static std::vector<double> cc_eigenvec;
        static double cc_eigenval;
        static int deg_poly;
        static std::vector<int> monomer_atoms;
        static int mono_length;
        static double co_dist, cc_dist;
        static double cco_angle, coc_angle;
        static double pi;

};
#endif

