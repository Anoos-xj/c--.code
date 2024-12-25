#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define down 0.996

using namespace std;

const int N = 40;
const long long inf = 9223372036854775807;

int t, n, v[N];
long long ans;

long long get(int x, int y)
{
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= (n + 1) / 2; i++)
        ans1 += v[i];
    for (int i = (n + 1) / 2 + 1; i <= n; i++)
        ans2 += v[i];
    if (x <= (n + 1) / 2)
        ans1 = ans1 + v[y] - v[x];
    if (x > (n + 1) / 2)
        ans2 = ans2 + v[y] - v[x];
    if (y <= (n + 1) / 2)
        ans1 = ans1 + v[x] - v[y];
    if (y > (n + 1) / 2)
        ans2 = ans2 + v[x] - v[y];
    return abs(ans1 - ans2);
}

void SA()
{
    int T = 3000;
    while (T > 1e-14)
    {
        int x = rand() % n + 1, y = rand() % n + 1;
        long long tmp = get(x, y);
        if (tmp < ans)
            ans = tmp, swap(v[x], v[y]);
        else if (exp((ans - tmp) / T) * RAND_MAX > rand())
            swap(v[x], v[y]);
        T *= down;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = inf;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        for (int i = 1; i <= 500; i++)
            SA();
        printf("%lld\n", ans);
    }
    return 0;
}