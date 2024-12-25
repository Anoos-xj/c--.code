#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int ans = -2147483648;

int a[N], s[N];

deque<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && q.front() < i - m)
            q.pop_front();
        ans = max(ans, s[i] - s[q.front()]);
        while (q.size() && s[q.back()] >= s[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << ans << endl;
    return 0;
}