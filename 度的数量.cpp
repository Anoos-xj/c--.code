#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35;

int x, y, k, b;

long long c[N][N];

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

int dp(int n)
{
    if (!n)
        return 0;
    vector<int> nums;
    while (n)
        nums.push_back(n % b), n /= b;
    int res = 0, last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int t = nums[i];
        if (t)
        {
            res += c[i][k - last];
            if (t > 1 && k >= last + 1)
            {
                res += c[i][k - last - 1];
                break;
            }
            else
            {
                last++;
                if (last > k)
                    break;
            }
        }
        if (!i && last == k)
            res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> x >> y;
    cin >> k >> b;
    init();
    cout << dp(y) - dp(x - 1) << endl;
    return 0;
}