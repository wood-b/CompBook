#ifndef PEO_RIS_H
#define PEO_RIS_H

#include <vector>

class PEO_bonds 
{
    private:
        std::vector<double> U;
        std::vector<double> A;
        double lamda;
        //PEO_bonds ();//default constructor
        PEO_bonds (std::vector<double>& u, std::vector<double>& a, double lam){
            this->U = u;
            this->A = a;
            this->lamda = lam;
        } 

    public:
        std::vector<double> Umatrix(){
            return this->U;
        }
       //void resetU (std::vector<double> u){
          // U = u;
       //}
        std::vector<double> Amatrix(){
            return this->A;
        }
       // void setA (std::vector<double> a){
           //A = a;
       //}
        double lamdaValue(){
            return this->lamda;
        }
        //void setLamda (double lam){
            //lamda = lam;
        //}


};

//#include "PEO_RIS.cpp"

#endif
