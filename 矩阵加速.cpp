#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

const int p = 1e9 + 7;

ll t, n;

ll res[3][3], a[3][3], c[3][3];

void modify1()
{
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                c[i][j] = (c[i][j] + (ll)res[i][k] * a[k][j]) % p;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            res[i][j] = c[i][j];
}

void modify2()
{
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                c[i][j] = (c[i][j] + (ll)a[i][k] * a[k][j]) % p;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = c[i][j];
}

int qmi(int b)
{
    res[0][0] = 1, res[0][1] = 2, res[0][2] = 3, res[1][0] = 1, res[1][1] = 1, res[1][2] = 2, res[2][0] = 1, res[2][1] = 1, res[2][2] = 1;
    a[0][0] = 1, a[0][1] = 0, a[0][2] = 1, a[1][0] = 1, a[1][1] = 0, a[1][2] = 0, a[2][0] = 0, a[2][1] = 1, a[2][2] = 0;
    while (b)
    {
        if(b&1)
            modify1();
        modify2();
        b >>= 1;
    }
    return res[2][0];
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n<=3)
            cout << "1" << endl;
        else
            cout << qmi(n - 3) % p << endl;
    }
    return 0;
}