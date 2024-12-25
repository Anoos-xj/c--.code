#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int num[11];

int work(int x)
{
    while (x)
    {
        if (num[x % 10] == 1)
            return 0;
        if (x % 10 == 0)
            return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int main()
{
    for (int i = 102; i <= 333; i++)
    {
        int x = i, y = i * 2, z = i * 3;
        if (work(x) && work(y) && work(z))
            cout << x << " " << y << " " << z << endl;
        memset(num, 0, sizeof(num));
    }
    return 0;
}