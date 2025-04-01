#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;
    vector<int> z(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> z[i];
    }

    if (M == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int max_val = *max_element(z.begin(), z.end());
    int cnt = count(z.begin(), z.end(), max_val);

    if (cnt != 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> S;
    for (int x : z)
    {
        if (x != max_val)
        {
            S.push_back(x);
        }
    }


    for (int x : S)
    {
        if (2 * x > max_val)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    sort(S.rbegin(), S.rend());
    bool valid = true;
    for (size_t i = 1; i < S.size(); ++i)
    {
        if (2 * S[i] > S[i - 1])
        {
            valid = false;
            break;
        }
    }
    if (valid)
    {

        long long fact = 1;
        for (int i = 1; i <= M; ++i)
        {
            fact = fact * i % MOD;
        }
        cout << fact << endl;
        return 0;
    }

    sort(S.begin(), S.end());
    valid = true;
    for (size_t i = 1; i < S.size(); ++i)
    {
        if (S[i] < 2 * S[i - 1])
        {
            valid = false;
            break;
        }
    }
    if (valid)
    {

        long long fact = 1;
        for (int i = 1; i <= M; ++i)
        {
            fact = fact * i % MOD;
        }
        cout << fact << endl;
        return 0;
    }


    cout << 0 << endl;
    return 0;
}