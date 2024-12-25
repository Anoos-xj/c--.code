#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define x first
#define y second

using namespace std;

typedef pair<int, string> PIS;

int f(string m)
{
    int dist = 0;
    for (int i = 0; i < 9; i++)
        if (m[i] != 'x')
        {
            int t = m[i] - '1';
            dist = dist + abs(i / 3 - t / 3) + abs(i % 3 - t % 3); // 曼哈顿距离
        }
    return dist;
}

string bfs(string start)
{
    string end = "12345678x";
    unordered_map<string, int> d;
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap;
    unordered_map<string, pair<string, char>> prev;

    heap.push({f(start), start});
    d[start] = 0;
    char op[] = "udlr";
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (heap.size())
    {
        PIS tmp = heap.top();
        heap.pop();
        string state = tmp.y;
        if (tmp.y == end)
            break;
        int xx, yy;
        for (int i = 0; i < 9; i++)
            if (state[i] == 'x')
            {
                xx = i / 3, yy = i % 3;
                break;
            }
        string init = state;
        for (int i = 0; i < 4; i++)
        {
            int a = xx + dx[i], b = yy + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3)
                continue;
            swap(state[a * 3 + b], state[xx * 3 + yy]);
            if (!d.count(state) || d[state] > d[init] + 1)
            {
                d[state] = d[init] + 1;
                heap.push({f(state) + d[state], state});
                prev[state] = {init, op[i]};
            }
            state = init;
        }
    }
    string ans;
    while (end != start)
    {
        ans += prev[end].y;
        end = prev[end].x;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string start, xx, c;
    while (cin >> c)
    {
        start += c;
        if (c != "x")
            xx += c;
    }
    int res = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++)
            if (xx[i] > xx[j])
                res++;
    if (res % 2)
        printf("unsolvable\n");
    else
        cout << bfs(start) << endl;
    return 0;
}
// .\八数码.exe