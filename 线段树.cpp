// 线段树的实现
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 2e5 + 10;
typedef long long ll;

struct node
{
	ll l, r, sum, tag;
} tr[N << 2];

ll n, m;
ll a[N];

void pushdown(ll u)
{
	node &p = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
	l.sum += p.tag * (l.r - l.l + 1);
	r.sum += p.tag * (r.r - r.l + 1);
	l.tag += p.tag;
	r.tag += p.tag;
	p.tag = 0;
}

void pushup(ll u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(ll u, ll l, ll r)
{
	if (l == r)
	{
		tr[u] = {l, r, a[l], 0};
		return;
	}
	tr[u] = {l, r};
	ll mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(ll u, ll l, ll r, ll k)
{
	pushdown(u); // 为什么是必要的？答案：因为我们要保证每个节点的sum是正确的，所以我们要先把tag下传
	// 这样我们才能保证每个节点的sum是正确的，然后再进行修改
	// 总结：能pushdown就pushdown
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum += k * (tr[u].r - tr[u].l + 1);
		tr[u].tag += k;
		return;
	}
	ll mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
		modify(u << 1, l, r, k);
	if (r > mid)
		modify(u << 1 | 1, l, r, k);
	pushup(u);
}

ll query(ll u, ll l, ll r)
{
	pushdown(u);
	if (tr[u].l >= l && tr[u].r <= r)
		return tr[u].sum;
	ll mid = tr[u].l + tr[u].r >> 1;
	ll res = 0;
	if (l <= mid)
		res += query(u << 1, l, r);
	if (r > mid)
		res += query(u << 1 | 1, l, r);
	return res;
}

int main()
{
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	for (ll i = 1; i <= m; i++)
	{
		ll op;
		cin >> op;
		if (op == 1)
		{
			ll x, y, k;
			cin >> x >> y >> k;
			modify(1, x, y, k);
		}
		if (op == 2)
		{
			ll x, y;
			cin >> x >> y;
			cout << query(1, x, y) << endl;
		}
	}
	return 0;
}