#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct Node
{
    int val;
    int id;
};

vector<int> getMin(vector<int> &a)
{
    int n = a.size();
    vector<Node> get_min(n + 1);
    get_min[n] = {0x3f3f3f3f, n};
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
        {
            get_min[i] = {a[i], i};
        }
        else
        {
            if (a[i] < get_min[i + 1].val)
            {
                get_min[i] = {a[i], i};
            }
            else
            {
                get_min[i] = get_min[i + 1];
            }
        }
    }
    int id = -1;
    for (int i = 0; i < n; ++i)
    {
        if (i + 1 < n && get_min[i + 1].val < a[i])
        {
            id = i;
            break;
        }
    }
    vector<int> res(a);
    if (id == -1)
        return res;
    int j = get_min[id + 1].id;
    swap(res[id], res[j]);
    return res;
}

vector<int> getMax(vector<int> &a)
{
    int n = a.size();
    vector<Node> get_max(n + 1);
    get_max[n] = {0, n};
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
        {
            get_max[i] = {a[i], i};
        }
        else
        {
            if (a[i] > get_max[i + 1].val)
            {
                get_max[i] = {a[i], i};
            }
            else
            {
                get_max[i] = get_max[i + 1];
            }
        }
    }
    int id = -1;
    for (int i = 0; i < n; ++i)
    {
        if (i + 1 < n && get_max[i + 1].val > a[i])
        {
            id = i;
            break;
        }
    }
    vector<int> res(a);
    if (id == -1)
        return res;
    int j = get_max[id + 1].id;
    swap(res[id], res[j]);
    return res;
}

vector<int> slove(ll t, int n, vector<int> &a)
{
    if (t == 0)
        return a;
    vector<int> fir = getMin(a);
    if (t == 1)
        return fir;
    vector<int> sec = getMax(fir);
    if (t == 2)
        return sec;
    vector<int> thi = getMin(sec);
    vector<int> fou = getMax(thi);
    ll tmp = t - 2;
    if (thi == sec)
    {
        return sec;
    }
    else if (thi == fir && fou == sec)
    {
        if (tmp % 2 == 0)
        {
            return sec;
        }
        else
        {
            return thi;
        }
    }
    tmp = t - 2;
    if (tmp % 2 == 0)
    {
        return sec;
    }
    else
    {
        return thi;
    }
}

int main()
{
    ll t;
    int n;
    cin >> t >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> result = slove(t, n, a);
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}