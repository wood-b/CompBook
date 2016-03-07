#include <iostream>
#include "chain_info.h"

using namespace std;

int main()
{
    vector<int> gauche = {1,2,3};
    int a = 4;
    chain_info test;
    test.add_atoms(gauche);
    test.add_tor(a);

    cout << test.tor_list()[0] << endl;

    for (int i; i < 3; i++)
    {
        cout << test.atom_list()[i] << endl;
    }

    return 0;
}
