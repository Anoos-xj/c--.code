#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e6 + 10;

int dp[N], q[N];

int y, n, m;

int mul[N];

int main()
{
    cin >> y >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> mul[i];
    int head = 1, tail = 0;
    for (int i = 1; i <= y; i++)
    {
        if (i <= n)
        {
            dp[i] = 1;
            while (head <= tail && dp[q[tail]] >= dp[i])
                tail--;
            q[++tail] = i;
            while (q[head] <= i - n)
                head++;
        }
        else
        {
            dp[i] = dp[q[head]] + 1;
            for (int j = 1; j <= m; j++)
            {
                if (i % mul[j] == 0)
                {
                    dp[i] = min(dp[i], dp[i / mul[j]] + 1);
                }
            }
            while (head <= tail && dp[q[tail]] >= dp[i])
                tail--;
            q[++tail] = i;
            while (q[head] <= i - n)
                head++;
        }
    }
    cout << dp[y] << endl;

    return 0;
}