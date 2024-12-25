#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 12;

int n, k;
vector<int> vec;
vector<int> res[1 << N];
int check(int x)
{
    for (int i = 0; i < n; i++)
        if ((x >> i & 1) && (x >> i + 1 & 1))
            return 0;
    return 1;
}

int count(int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (x >> i & 1)
            ans++;
    return ans;
}

long long f[N][N * N][1 << N];
int cnt[1 << N];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < 1 << n; i++)
        if (check(i))
            vec.push_back(i), cnt[i] = count(i); // 寻找符合单行条件的状态
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec.size(); j++)
            if (((vec[i] & vec[j]) == 0) && check(vec[i] | vec[j]))
                res[i].push_back(j); // 寻找上下两行间符合条件的状态
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int a = 0; a < vec.size(); a++)
                for (int b : res[a])
                    if (j >= cnt[vec[a]])
                        f[i][j][a] += f[i - 1][j - cnt[vec[a]]][b];
    long long ans = 0;
    for (int a = 0; a < vec.size(); a++)
        ans += f[n][k][a];
    cout << ans << endl;
    return 0;
}