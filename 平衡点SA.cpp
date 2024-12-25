#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define down 0.993
using namespace std;

const int N = 1010;

int n;
double ansx, ansy, ansz;
struct node
{
    int x, y, z;
} obj[N];

double energy(double xx, double yy)
{
    double res = 0, dx, dy;
    for (int i = 1; i <= n; i++)
    {
        dx = xx - obj[i].x;
        dy = yy - obj[i].y;
        res += sqrt(dx * dx + dy * dy) * obj[i].z;
    }
    return res;
}

void SA() // 拜拜电脑，令机魂大悦即可。
{
    double t = 1926;
    while (t > 1e-14)
    {
        double ex = ansx + (rand() * 2 - RAND_MAX) * t;
        double ey = ansy + (rand() * 2 - RAND_MAX) * t;
        double ez = energy(ex, ey);
        double det = ez - ansz;
        if (det < 0)
            ansx = ex, ansy = ey, ansz = ez;
        else if (exp(-det / t) * RAND_MAX > rand())
            ansx = ex, ansy = ey;
        t *= down;
    }
}

void solve()
{
    for (int i = 1; i <= 3; i++)
        SA();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> obj[i].x >> obj[i].y >> obj[i].z;
        ansx += obj[i].x, ansy += obj[i].y;
    }
    ansx /= n;
    ansy /= n;
    ansz = energy(ansx, ansy);
    solve();
    printf("%.3lf %.3lf\n", ansx, ansy);
    return 0;
}