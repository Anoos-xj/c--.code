#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int check[N];
int ans1, ans2;

int main()
{
    memset(check, -1, sizeof(check));
    int n, l;
    cin >> l >> n;
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            for (int j = x; j <= y; j++)
            {
                if (check[j] == -1)
                    check[j] = 1;
                if (check[j] == 0)
                    check[j] = 1, ans1++;
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            for (int j = x; j <= y; j++)
            {
                if (check[j] == 1)
                    check[j] = 0;
            }
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (check[i] == 0)
            ans2++;
    }
    cout << ans2 << endl
         << ans1 << endl;

    return 0;
}