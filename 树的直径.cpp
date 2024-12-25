#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 10010;

typedef pair<int, int> PI;

int n;

vector<PI> vec[N];

int ans;

int dfs(int u,int fa)
{
    int dist = 0, d1 = 0, d2 = 0;
    for(PI v:vec[u])
    {
        if(v.first==fa)
            continue;
        int d = dfs(v.first, u) + v.second;
        if(d>dist)
            dist = d;
        if(d>d1)
            d2 = d1, d1 = d;
        else if(d>d2)
            d2 = d;
    }
    ans = max(ans, d1 + d2);
    return dist;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}