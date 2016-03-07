#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

int main()
{
    matrix test = { {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0} };

    cout << test.indexValue()[2][2] << endl;

    return 0;
}
