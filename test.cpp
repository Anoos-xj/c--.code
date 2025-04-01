// 数组模拟堆排序
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[101];

void down(int x)
{
    while (x * 2 <= n)
    {
        int t = x * 2;
        if (t + 1 <= n && a[t + 1] > a[t])
            t++;
        if (a[t] <= a[x])
            break;
        std::swap(a[x], a[t]);
        x = t;
    }
}

void build()
{
    for (int i = n; i >= 1; i--)
        down(i);
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    cout << a[1] << endl;
    return 0;
}