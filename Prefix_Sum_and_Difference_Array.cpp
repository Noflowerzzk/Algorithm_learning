// 前缀和
/*
给定义一个数组a,有q+1次询问，对于每次询问：
给定两个整数l,r，求出a[l] + ... + a[r] 的结果。
*/
#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

ll a[N];
ll prefix[N], diff[N];

int main()
{
    // 基操：取消同步流
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int p;
    cin >> p;
    int q;
    cin >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // prefix[0] = a[0];
    for (int i = 1; i <= n; i++)
        diff[i] = a[i] - a[i - 1];
    while (p--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        diff[l] += x, diff[r + 1] -= x;
    }

    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + diff[i];

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    return 0;
}