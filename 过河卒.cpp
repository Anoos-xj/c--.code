#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 30;

long long vis[N][N], f[N][N];

int n, m, x, y;
int dx[9] = {-2, -1, 1, 2, -2, -1, 1, 2, 0};
int dy[9] = {-1, -2, 2, 1, 1, 2, -2, -1, 0};

int main()
{
    cin >> n >> m >> x >> y;
    f[0][0] = 1;
    for (int i = 0; i <= 8;i++)
        if(dx[i]+x>=0&&dy[i]+y>=0)
            vis[dx[i] + x][dy[i] + y] = 1;
    for (int i = 0; i <= n;i++)
        for (int j = 0; j <= m;j++)
            if(vis[i][j])
                continue;
            else if(!i&&!j)
                continue;
            else if(!i)
                f[i][j] = f[i][j - 1];
            else if(!j)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i - 1][j] + f[i][j - 1];
    cout << f[n][m] << endl;
    return 0;
}