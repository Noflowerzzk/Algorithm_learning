#include <iostream>
#include <stack>
using namespace std;

const int N = 2e5 + 9;
int a[N], l[N], stk[N], top; // 数组模拟栈 支持lazy_clear   

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (top && a[stk[top]] >= a[i])
            top--;
        if (top)
            l[i] = a[stk[top]];
        else
            l[i] = -1;
        stk[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << l[i] << ' ';
    return 0;
}