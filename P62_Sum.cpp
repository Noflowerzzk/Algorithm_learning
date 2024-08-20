#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
int a[N], l[N], r[N]; // l : i左边小于a[i]最近的位置, r同理(大于等于) -> 单调栈
int stk[N], top = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // 先求l
    for (int i = 1; i <= n; ++i)
    {
        while (top && a[stk[top]] >= a[i])
            top--;
        if (top)
            l[i] = stk[top];
        else
            l[i] = 0;

        stk[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; --i)
    {
        while (top && a[stk[top]] > a[i])
            top--;
        if (top)
            r[i] = stk[top];
        else
            r[i] = n + 1;

        stk[++top] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i] * (r[i] - i) * (i - l[i]);
    cout << ans << '\n';
    return 0;
}