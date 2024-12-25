#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

#define x first
#define y second

using namespace std;

const int N = 1010;

typedef pair<int, int> PI;

int n, m;
int dis[N][N];
string str[N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<PI> q;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (str[i][j] == '1')
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
            else
                dis[i][j] = 0x3f3f3f3f;
    while (q.size())
    {
        PI t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = t.x + dx[i], ty = t.y + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m)
                continue;
            if (dis[tx][ty] == 0x3f3f3f3f)
            {
                dis[tx][ty] = dis[t.x][t.y] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dis[i][j] << " ";
        cout << endl;
    }
    return 0;
}