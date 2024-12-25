#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 2e5 + 10;

int n;
int fa[N];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int e[N], ne[N], h[N], idx;

void add(int u,int v)
{
    e[++idx] = v, ne[idx] = h[u], h[u] = idx;
}

int ans[N];

void dfs(int s,int pre,int cnt,int t)
{
    ans[cnt] = s;
    if(s==t)
    {
        sort(ans, ans + cnt + 1);
        for (int i = 0; i <= cnt;i++)
            cout << ans[i] << " ";
        return;
    }
    for (int i = h[s]; ~i;i=ne[i])
    {
        int j = e[i];
        if(j!=pre)
            dfs(j, s, cnt + 1, t);
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    for (int i = 1, u, v; i <= n;i++)
    {
        cin >> u >> v;
        if(find(u)!=find(v))
            add(u, v), add(v, u),fa[find(u)] = find(v);
        else
            dfs(u, 0, 0, v);
    }
    return 0;
}