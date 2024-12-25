#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int check[1010];
int a[1010][110];
int b[1010], idx;
int main()
{
    memset(a, 0, sizeof(a));
    int n = 0;
    cin >> n;
    for (int count = 0, i = 0; count < n; count++)
    {
        int t = 0;
        int m = 0;
        cin >> i;
        while (i > 0)
        {
            i--;
            cin >> t;
            a[count][m] = t;
            // cout << a[count][m] << endl;
            m++;
        }
    }

    int s = 0, sum = 0;
    check[1] = 1;
    sum++;
    for (int p = 0; a[0][p] != 0; p++)
    {
        if (check[a[0][p]] == 0)
        {
            check[a[0][p]] = 1;
            // cout << a[0][p] << endl;
            b[++idx] = a[0][p];
            sum++;
        }
    }
    for (int i = 1; i <= idx; i++)
    {
        for (int p = 0; a[b[i] - 1][p] != 0; p++)
            if (check[a[b[i] - 1][p]] == 0)
            {
                // cout << a[b[i] - 1][p] << endl;
                check[a[b[i] - 1][p]] = 1;
                sum++;
            }
    }
    cout << sum << endl;
    return 0;
}