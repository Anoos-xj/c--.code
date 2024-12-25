#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 5e5 + 10;

typedef pair<int, int> PI;

int n, m, s;

int h[N], e[N], ne[N], w[N];
int idx;
int dis[N], vis[N];

void add(int a, int b, int c)
{
    e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}

priority_queue<PI, vector<PI>, greater<PI>> q;

void dijkstra()
{
    dis[s] = 0;
    q.push({dis[s], s});
    while (q.size())
    {
        PI tmp = q.top();
        q.pop();
        int ver = tmp.second, val = tmp.first;
        if (vis[ver])
            continue;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > val + w[i])
            {
                dis[j] = val + w[i];
                q.push({dis[j], j});
            }
        }
    }
}

long long power(int x, int y)
{
    long long ans = 1;
    for (int i = 1; i <= y; i++)
        ans *= x;
    return ans;
}

int main()
{

    cin >> n >> m >> s;
    memset(h, -1, sizeof(h));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        if (dis[i] == 0x3f3f3f3f)
            cout << power(2, 31) - 1 << " ";
        else
            cout << dis[i] << " ";
}