// 离散化处理+二分查找+加线段树处理区间求奇数项中位数问题
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int tr[N << 2];

int n;
int a[N];
int tmpa[N], ranks[N];

void update(int u, int l, int r, int idx)
{
    if (l == r)
    {
        tr[u]++;
        return;
    }
    int mid = l + r >> 1;
    if (idx <= mid)
        update(u << 1, l, mid, idx);
    else
        update(u << 1 | 1, mid + 1, r, idx);
    tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

int query(int u, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = l + r >> 1;
    if (tr[u << 1] >= k)
        return query(u << 1, l, mid, k);
    else
        return query(u << 1 | 1, mid + 1, r, k - tr[u << 1]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tmpa[i] = a[i];
    }

    sort(tmpa + 1, tmpa + 1 + n);
    int m = unique(tmpa + 1, tmpa + 1 + n) - (tmpa + 1);

    for (int i = 1; i <= n; i++)
        ranks[i] = lower_bound(tmpa + 1, tmpa + 1 + m, a[i]) - tmpa;

    memset(tr, 0, sizeof(tr));

    for (int i = 1; i <= n; i++)
    {
        int ran = ranks[i];
        update(1, 1, m, ran);
        if (i & 1)
            cout << tmpa[query(1, 1, m, i + 1 >> 1)] << endl;
    }
    return 0;
}