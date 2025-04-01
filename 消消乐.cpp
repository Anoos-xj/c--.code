#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

string s[N];
int tot;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tot = 1;
        cin >> s[i];
        if (s[i].length() == 0)
        {
            cout << 0 << endl;
            continue;
        }

        for (int j = 1; j < s[i].length(); j++)
        {
            if (s[i][j] != s[i][j - 1])
                tot++;
        }
        cout << s[i].length() - tot << endl;
    }
    return 0;
}