#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

ll t, x, k;
ll ans;

ll bits[64], cnt;

ll check(ll a)
{
    cnt = 0;
    ll tmp = 0;
    while (a)
    {
        if (a & 1)
            bits[++cnt] = a & 1, tmp++;
        else
            bits[++cnt] = a & 1;
        a >>= 1;
    }
    return tmp;
}

int main()
{
    cin >> t;
    while (t--)
    {
        ans = 0;
        memset(bits, 0, sizeof(bits));
        cin >> x >> k;
        ll m = check(x);
        if (m == 1)
        {
            ll tmp = k - m;
            ll temp = 1;
            for (ll i = 1; i <= 60; i++)
            {
                if (tmp == 0)
                    break;
                if (bits[i] == 0)
                {
                    ans += temp;
                    tmp--;
                }
                temp <<= 1;
            }
            ll ans0 = 0;
            tmp = k;
            for (ll i = cnt - 2; i >= 0; i--)
            {
                if (tmp == 0)
                    break;
                tmp--;
                ans0 += (1 << i);
            }
            if(tmp==0) 
                ans = min(ans, x - ans0);
        }
        if (x - (2 << k) + 1 == 0)
        {
            ll tmp = k - m;
            ll temp = 1;
            for (ll i = 1; i <= 60; i++)
            {
                if (tmp == 0)
                    break;
                if (bits[i] == 0)
                {
                    ans += temp;
                    tmp--;
                }
                temp <<= 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}