#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N], f[N][2];//0表示不同奇数，1表示相同偶数
int tmp[N][2];
int temp, temps;
int ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    f[0][0] = 1;
    for (int i = 1; i <= n;i++)
    {
        f[i][0] = 1;
        if(f[tmp[a[i]][0]][0]&1)
            f[i][1] = f[tmp[a[i]][0]][0] + 1;
        if(temp!=a[i])
            f[i][0] = max(f[i][0], f[tmp[temp][1]][1] + 1);
        else
            f[i][0] = max(f[i][0], f[tmp[temps][1]][1] + 1);
        if(f[tmp[a[i]][1]][1]<f[i][1])
            tmp[a[i]][1] = i;
        if(f[tmp[a[i]][0]][0]<f[i][0])
            tmp[a[i]][0] = i;
        if(f[tmp[temp][1]][1]<=f[i][1])
        {
            if(temp!=a[i])
                temps = a[i];
            temp = a[i];
        }
        else if(f[tmp[temps][1]][1]<=f[i][1])
            temps = a[i];
        ans = max(ans, f[i][1]);
    }
    cout << ans << endl;
    return 0;
}