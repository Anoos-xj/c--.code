#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int w[N][N], f[N][N];
int ans;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y)
{
    if (f[x][y] != 0)
        return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx > 0 && ty > 0 && tx <= n && ty <= n && w[tx][ty] < w[x][y])
            f[x][y] = max(f[x][y], dfs(tx, ty) + 1);
    }
    return f[x][y];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}
// .\滑雪.exe