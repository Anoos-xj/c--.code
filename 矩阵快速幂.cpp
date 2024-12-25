#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long

using namespace std;

const int N = 110;
const int p = 1e9 + 7;

ll n, b;
ll a[N][N];
ll res[N][N];
ll c[N][N];

void modify1()
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                c[i][j] = (c[i][j] + (ll)res[i][k] * a[k][j]) % p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res[i][j] = c[i][j];
}

void modify2()
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                c[i][j] = (c[i][j] + (ll)a[i][k] * a[k][j]) % p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = c[i][j];
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            modify1();
        modify2();
        b >>= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << res[i][j] % p << " ";
        cout << endl;
    }
    return 0;
}