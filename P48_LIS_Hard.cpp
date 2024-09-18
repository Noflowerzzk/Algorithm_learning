#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 2e5 + 3;
ll a[N];
// stk[i] 表示长度为 i+1 的子序列的末尾元素的最小可能值。
int stk[N], top;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    
    int ans = 0;
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