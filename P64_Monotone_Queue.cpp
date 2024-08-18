#include <iostream>
#include <deque>
using namespace std;

const int N = 2e5 + 9;
int a[N], l[N], stk[N], top; // 数组模拟栈 支持lazy_clear

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> dq; // 存下标
    for (int i = 1; i <= n; i++)
    {
        // 区间[i - k + 1, ..., i]
        // 队头合法性
        while (dq.size() && dq.front() <= i - k)
            dq.pop_front();
        // 队尾优越性
        while (dq.size() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k)
            cout << a[dq.front()] << ' ';
    }
    cout << '\n';
    dq = deque<int>();
    for (int i = 1; i <= n; i++)
    {
        // 区间[i - k + 1, ..., i]
        // 队头合法性
        while (dq.size() && dq.front() <= i - k)
            dq.pop_front();
        // 队尾优越性
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k)
            cout << a[dq.front()] << ' ';
    }

    return 0;
}