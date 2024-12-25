#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 2e5 + 10;

int n, tot, rt, idx;
int cnt, rub[N];

struct node
{
    int per[2], val;
    node() {};
    node(int x, int y, int vall)
    {
        per[0] = x, per[1] = y, val = vall;
    }
} nod[N];

struct KD_tree
{
    int ch[2], maxn[2], minn[2], sum, size;
    node p;
} tr[N];

int cmp0(node a, node b)
{
    return a.per[0] < b.per[0];
}

int cmp1(node a, node b)
{
    return a.per[1] < b.per[1];
}

int newu()
{
    if (cnt)
        return rub[cnt--];
    return ++tot;
}

void pushup(int u)
{
    int lc = tr[u].ch[0], rc = tr[u].ch[1];
    for (int i = 0; i < 2; i++)
    {
        tr[u].minn[i] = tr[u].maxn[i] = tr[u].p.per[i];
        if (lc)
            tr[u].minn[i] = min(tr[u].minn[i], tr[lc].minn[i]),
            tr[u].maxn[i] = max(tr[u].maxn[i], tr[lc].maxn[i]);
        if (rc)
            tr[u].minn[i] = min(tr[u].minn[i], tr[rc].minn[i]),
            tr[u].maxn[i] = max(tr[u].maxn[i], tr[rc].maxn[i]);
    }
    tr[u].sum = tr[lc].sum + tr[rc].sum + tr[u].p.val;
    tr[u].size = tr[lc].size + tr[rc].size + 1;
}

void slap(int u)
{
    if (!u)
        return;
    nod[++idx] = tr[u].p;
    rub[++cnt] = u;
    slap(tr[u].ch[0]), slap(tr[u].ch[1]);
}

int rebuild(int l, int r, int d)
{
    if (l > r)
        return 0;
    int mid = l + r >> 1;
    int u = newu();
    nth_element(nod + l, nod + mid, nod + r + 1, d ? cmp1 : cmp0);
    tr[u].p = nod[mid];
    tr[u].ch[0] = rebuild(l, mid - 1, d ^ 1);
    tr[u].ch[1] = rebuild(mid + 1, r, d ^ 1);
    pushup(u);
    return u;
}

void check(int &u, int d)
{
    int lc = tr[u].ch[0], rc = tr[u].ch[1];
    if (tr[lc].size > 3 * tr[u].size / 4 || tr[rc].size > 3 * tr[u].size / 4)
    {
        idx = 0;
        slap(u);
        u = rebuild(1, tr[u].size, d);
    }
}

void insert(int &u, node now, int d)
{
    if (!u)
    {
        u = newu();
        tr[u].ch[0] = tr[u].ch[1] = 0;
        tr[u].p = now;
        pushup(u);
        return;
    }
    if (now.per[d] <= tr[u].p.per[d])
        insert(tr[u].ch[0], now, d ^ 1);
    else
        insert(tr[u].ch[1], now, d ^ 1);
    pushup(u);
    check(u, d);
}

bool in(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2)
{
    return x1 <= X1 && x2 >= X2 && y1 <= Y1 && y2 >= Y2;
}

bool out(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2)
{
    return x1 > X2 || x2 < X1 || y1 > Y2 || y2 < Y1;
}

int query(int u, int x1, int y1, int x2, int y2)
{
    if (!u)
        return 0;
    if (in(x1, y1, x2, y2, tr[u].minn[0], tr[u].minn[1], tr[u].maxn[0], tr[u].maxn[1]))
        return tr[u].sum;
    if (out(x1, y1, x2, y2, tr[u].minn[0], tr[u].minn[1], tr[u].maxn[0], tr[u].maxn[1]))
        return 0;
    int ans = 0;
    if (in(x1, y1, x2, y2, tr[u].p.per[0], tr[u].p.per[1], tr[u].p.per[0], tr[u].p.per[1]))
        ans += tr[u].p.val;
    ans += query(tr[u].ch[0], x1, y1, x2, y2) + query(tr[u].ch[1], x1, y1, x2, y2);
    return ans;
}

int main()
{
    int op, x1, x2, y1, y2, ad;
    int lastans = 0;
    ios::sync_with_stdio(0);
    cin >> n;
    while (1)
    {
        cin >> op;
        if (op == 3)
            break;
        else if (op == 1)
        {
            cin >> x1 >> y1 >> ad;
            x1 ^= lastans, y1 ^= lastans, ad ^= lastans;
            insert(rt, node(x1, y1, ad), 0);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            x1 ^= lastans, y1 ^= lastans, x2 ^= lastans, y2 ^= lastans;
            lastans = query(rt, x1, y1, x2, y2);
            cout << lastans << endl;
        }
    }
    return 0;
}