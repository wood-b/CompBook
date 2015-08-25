#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <array>

//Date: 08/03/15
//Author: Brandon Wood
//License: Modified BSD

using namespace std;

//==================================
//Functions
//==================================

void cond_prob(vector<double>& q,
               vector<int>& tor_set,
               vector<int>& back_atom, 
               array<double,9>& U1, 
               array<double,9>& U2, 
               array<double,9>& U3, 
               array<double,9>& A1, 
               array<double,9>& A2, 
               array<double,9>& A3,
               double lamdaA1, 
               double lamdaA2, 
               double lamdaA3)
{
    //C-O bond
    if ((back_atom[back_atom.size()-1]==1) && (back_atom[back_atom.size()-2]==1)) {
        cout << "you don't suck completely" << endl;
        cout << back_atom.size() << endl;
        q.clear();
        for (int index=0; index<9; index++) {
            q[index]= U1[index]*A1
            
        }

        
        


    }
    else
        cout << "you do suck completely" << endl; 
}

//==================================
//Main Function
//==================================

int main(int argc, char *argv[])
{
    //==================================
    //Degree of Polymerization
    //==================================
    
    int poly_length;
    cout << "Please enter the desired chain length as an integer: ";
    cin >> poly_length;
    //cout << poly_length << endl;
    //calc length of chain in terms of torsion angles
    //there are 3 bonds per monomer ignoring end groups
    //subtract 2 for methyl end groups and there are n-2 torsion angles
    int tor_length = (poly_length*3)-4;
    //cout << tor_length << endl;
    //Calc the number of backbone atoms
    int back_length = (poly_length*3)+2;
   
    //==================================
    //Definitions
    //==================================
    
    //matrices are stored as simple arrays -> element 2,3 would be (2x3)-1=5
    const int mat_ele = 9; //number of matrix elements
    //statistical weight matrices U1 -> C-O-C U2 -> O-C-C U3 -> C-C-O
    array <double, mat_ele> U1={1.0, 0.22, 0.22, 1.0, 0.22, 0.12452, 1.0, 0.12452, 0.22};
    //cout << Ua[8] << endl;
    array <double, mat_ele> U2={1.0, 0.22, 0.22, 1.0, 0.22, 0.0, 1.0, 0.0, 0.22};
    array <double, mat_ele> U3={1.0, 2.07, 2.07, 1.0, 2.07, 1.17162, 1.0, 1.17162, 2.07};

    //eigenvector matrices A1 -> U1 ... so on
    array <double, mat_ele> A1={0.602509, 0.279784, 0.0, 0.564351, -0.678867, -0.707107, 0.564351, -0.678867, 0.707107};
    array <double, mat_ele> A2={0.634022, 0.259165, 0.0, 0.546816, -0.682947, -0.707107, 0.546816, -0.682947, 0.707107};
    array <double, mat_ele> A3={0.647675, -0.925039, 0.0, 0.538757, 0.268611, -0.707107, 0.538757, 0.268611, 0.707107};

    //eigenvalues
    double lamdaA1=1.41213; double lamdaA2=1.37948; double lamdaA3=4.44379;
    //set of torsion angles defining the entire polymer structure -1->g- 0->t 1->g+ 
    vector <int> tor_set; 
    //polymer backbone polymer atom list 0 -> Oxygen 1 -> Carbon
    vector <int> back_atom;
    //conditional probability
    vector <double> q;

    //==================================
    //Initial Config
    //==================================

    tor_set.push_back(0); //first torsion angle is trans
    back_atom.push_back(1), back_atom.push_back(1), back_atom.push_back(0); //first three atoms are C-C-O
    //cout << back_atom[0] << ", " << tor_set[0] << endl;


    //==================================
    //Calculate Conditional Probabilities
    //==================================

    cond_prob(q, tor_set, back_atom, U1, U2, U3, A1, A2, A3, lamdaA1, lamdaA2, lamdaA3);

    return 0;
}
