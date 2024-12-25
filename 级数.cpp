#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double gama = 0.5772156649;
int n, k;

int main()
{
    cin >> k;
    n = exp(k - gama) + 0.5;
    cout << n << endl;
    return 0;
}