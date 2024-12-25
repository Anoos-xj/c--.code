#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long t, n, k;
long long total;
long long q, r;

int main()
{
    cin >> t;
    while (t--)
    {
        total = 1;
        cin >> n >> k;
        if (k == 0)
            cout << total << endl;
        else
        {
            q = n / k;
            r = n - q * k;
            //cout << q << " " << r << endl;
            if ((q - r) % (k + 1) == 0)
                total--;
            total += (q - r) / (k + 1);
            if(q<r)
                cout << "0" << endl;
            else
                cout << total << endl;
            //cout << abs(n / k - n / (k + 1)) << endl;
        }
    }
    //cout << n % k << endl;
    return 0;
}
// 321532634 2141534