#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 6e3 + 10;

int t, n, m;

int e[N], ne[N], w[N], h[N], idx;

void add(int a, int b, int c)
{
    e[++idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx;
}

int dis[N], vis[N], cnt[N];
queue<int> q;

void spfa()
{
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    while (q.size())
        q.pop();
    dis[1] = 0, vis[1] = 1, q.push(1);
    while (q.size())
    {
        int ver = q.front();
        q.pop();
        vis[ver] = 0;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[ver] + w[i])
            {
                dis[j] = dis[ver] + w[i];
                if (!vis[j])
                {
                    if (++cnt[j] >= n)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        idx = 0;
        memset(h, -1, sizeof(h));
        for (int i = 1, a, b, c; i <= m; i++)
        {
            cin >> a >> b >> c;
            add(a, b, c);
            if (c >= 0)
                add(b, a, c);
        }
        spfa();
    }
    return 0;
}