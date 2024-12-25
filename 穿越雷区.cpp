#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 110;

int n;

struct node
{
    int x, y, ans;
};

node s, t;
queue<node> q;

int map[N][N], check[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs()
{
    q.push(s);
    check[s.x][s.y] = 1;
    while(q.size())
    {
        node tmp = q.front();
        q.pop();
        for (int i = 0; i < 4;i++)
        {
            int tx = tmp.x + dx[i], ty = tmp.y + dy[i];
            if(!check[tx][ty]&&map[tx][ty]!=map[tmp.x][tmp.y])
            {
                node ver = {tx, ty, tmp.ans + 1};
                if(tx==t.x&&ty==t.y)
                    return ver.ans;
                q.push(ver);
                check[tx][ty] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
        {
            char c;
            cin >> c;
            if(c=='A')
                s.x = i, s.y = j;
            if(c=='B')
                t.x = i, t.y = j;
            if(c=='+')
                map[i][j] = 1;
            if(c=='-')
                map[i][j] = 2;
        }
    cout << bfs() << endl;
    return 0;
}