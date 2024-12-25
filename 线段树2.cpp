#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 2e5 + 10;

ll a[N];
ll n, m, p;

struct node
{
    ll l, r, res, sum, mull;
} tr[N << 2];

void pushdown(ll u)
{
    node &f = tr[u],
         &l = tr[u << 1],
         &r = tr[u << 1 | 1];
    l.res = (l.res * f.mull + f.sum * (l.r - l.l + 1)) % p;
    r.res = (r.res * f.mull + f.sum * (r.r - r.l + 1)) % p;
    l.sum = (l.sum * f.mull + f.sum) % p;
    r.sum = (r.sum * f.mull + f.sum) % p;
    l.mull = (l.mull * f.mull) % p;
    r.mull = (r.mull * f.mull) % p;
    f.mull = 1, f.sum = 0;
}
void pushup(ll u)
{
    tr[u].res = (tr[u << 1].res + tr[u << 1 | 1].res) % p;
}

void build(ll u, ll l, ll r)
{
    if (l == r)
    {
        tr[u] = {l, r, a[r] % p, 0, 1};
        return;
    }
    tr[u] = {l, r, 0, 0, 1};
    ll mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void mul(ll u, ll l, ll r, ll k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].mull = (tr[u].mull * k) % p;
        tr[u].sum = (tr[u].sum * k) % p;
        tr[u].res = (tr[u].res * k) % p;
        return;
    }
    pushdown(u);
    ll mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        mul(u << 1, l, r, k);
    if (r > mid)
        mul(u << 1 | 1, l, r, k);
    pushup(u);
}

void add(ll u, ll l, ll r, ll k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum = (tr[u].sum + k) % p;
        tr[u].res = (tr[u].res + (tr[u].r - tr[u].l + 1) * k) % p;
        return;
    }
    pushdown(u);
    ll mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        add(u << 1, l, r, k);
    if (r > mid)
        add(u << 1 | 1, l, r, k);
    pushup(u);
}

ll query(ll u, ll l, ll r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].res;
    pushdown(u);
    ll ans = 0;
    ll mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        ans = (ans + query(u << 1, l, r)) % p;
    if (r > mid)
        ans = (ans + query(u << 1 | 1, l, r)) % p;
    return ans;
}

int main()
{
    cin >> n >> m >> p;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            mul(1, x, y, k);
        }
        else if (t == 2)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            add(1, x, y, k);
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}