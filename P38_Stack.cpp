#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5 + 9;
int a[N], pos;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    stack<int> stk;
    pos = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (pos <= n && (stk.empty() || stk.top() != i))
            stk.push(a[pos++]);
        if (stk.top() == i)
            stk.pop();
        else
        {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}