#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;

int a[51][51];
int f[51][51][51][51];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= m; ++k)
                for (int l = 1; l <= n; ++l)
                    if (!(i == k && j == l))
                        f[i][j][k][l] = max(f[i - 1][j][k][l - 1], max(f[i - 1][j][k - 1][l], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]))) + a[i][j] + a[k][l];
    cout << f[m][n - 1][m - 1][n];
    return 0;
}
