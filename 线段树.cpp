#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 2e5 + 10;

struct node
{
	int l, r, sum, tag;
} tr[N << 2];

int n, m;
int a[N];

inline void pushdown(int u)
{
	node &p = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
	l.tag += p.tag;
	l.sum += p.tag * (l.r - l.l + 1);
	r.tag += p.tag;
	r.sum += p.tag * (r.r - r.l + 1);
	p.tag = 0;
}

inline void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u] = {l, r, a[l]};
		return;
	}
	tr[u] = {l, r};
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
inline void modify(int u, int l, int r, int k)
{
	pushdown(u);
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum += k * (tr[u].r - tr[u].l + 1);
		tr[u].tag += k;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
		modify(u << 1, l, r, k);
	if (r > mid)
		modify(u << 1 | 1, l, r, k);
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

inline int query(int u, int l, int r)
{
	pushdown(u);
	if (tr[u].l >= l && tr[u].r <= r)
		return tr[u].sum;
	int mid = tr[u].l + tr[u].r >> 1;
	int res = 0;
	if (l <= mid)
		res = query(u << 1, l, r);
	if (r > mid)
		res += query(u << 1 | 1, l, r);
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			modify(1, x, y, k);
		}
		if (t == 2)
		{
			int x, y;
			cin >> x >> y;
			cout << query(1, x, y) << endl;
		}
	}
	return 0;
}