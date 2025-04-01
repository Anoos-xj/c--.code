#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename type>
inline void read(type &x)
{
    x = 0;
    bool flag(0);
    char ch = getchar();
    while (!isdigit(ch))
        flag = ch == '-', ch = getchar();
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
} // 快读

template <typename type>
inline void write(type x, bool mode = 1) // 0为空格，1为换行
{
    x < 0 ? x = -x, putchar('-') : 0;
    static short Stack[50], top(0);
    do
        Stack[++top] = x % 10, x /= 10;
    while (x);
    while (top)
        putchar(Stack[top--] | 48);
    mode ? putchar('\n') : putchar(' ');
} // 快写

vector<int> simulateBubbleSort(vector<int> a, int n, int k)
{
    vector<int> res;
    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
            ++cnt;
            if (cnt == k)
            {
                res = a;
                return res;
            }
        }
    }

    return a;
}

int main()
{
    int n, T, k;
    read(n);
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    read(T);
    while (T--)
    {
        read(k);
        vector<int> res = simulateBubbleSort(a, n, k);
        for (int i = 1; i <= n; ++i)
        {
            write(res[i], i == n ? 1 : 0);
        }
    }
    return 0;
}    
