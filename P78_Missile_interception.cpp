#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e3 + 3;
ll a[N];
ll stk[N], top;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // 1.最长下降子序列
    ll n = 0, ans = 0;
    while(cin >> a[++ n]);
    n --;

    for(int i = 1; i <= n; ++ i)
    {
        int pos = upper_bound(stk + 1, stk + top + 1, a[i], [](const int &u, const int &v)
        {
            return u > v;
        }) - stk;

        if(pos == top + 1) top ++;

        stk[pos] = a[i];
    }

    cout << top << '\n';

    // 2.Dilworth's Theorem
    // 最大反链的大小等于最少链划分的数量

    top = 0, ans = 0;
    for(int i = 1; i <= n; ++ i)
    {
        // 找单调栈中最后一个<=a[i]的位置
        // 相当于第一个>a[i]的位置
        int pos = upper_bound(stk + 1, stk + top + 1, a[i]) - stk;

        if(pos == top + 1) top ++;
        stk[pos] = a[i];

        ans = max(ans, top);
    }

    cout << ans << '\n';

    return 0;
}