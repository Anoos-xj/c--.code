#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;
const int M = 10010;

int a[N], b[N];

int dp[M];
int minn = 0x3f3f3f3f;

int main()
{
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    ios::sync_with_stdio(false);
    int h, n;
    cin >> h >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < h; i++)
    {
        if (dp[i] == 0x3f3f3f3f)
            continue;
        for (int j = 1; j <= n; j++)
        {
            int tmp = i + a[j];
            int total = dp[i] + b[j];
            if (tmp >= h)
                minn = min(minn, total);
            else
                dp[tmp] = min(dp[tmp], total);
        }
    }
    cout << minn << endl;
    return 0;
}