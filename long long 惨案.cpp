#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

ll m, k;
ll t[N], a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> m >> k;
    ll temp = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    t[m] = (1 + m) * m / 2; // 这里m如果是int型，会溢出，不开ll见祖宗，要开全都开。
    cnt = m - 1;
    for (int i = m - 1; i >= 1; i--)
        if (a[i] >= a[i + 1])
            t[cnt] = t[cnt + 1] - i, cnt--;
    for (int i = 1; i <= m; i++)
        if (t[i])
            cout << t[i] << " ";
        else
            cout << -1 << " ";
    return 0;
}