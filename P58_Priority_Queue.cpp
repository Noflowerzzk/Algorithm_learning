#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
int a[N], pos;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q;
    cin >> Q;
    priority_queue<ll> pq;
    ll sum = 0;
    while (Q--)
    {
        int _;
        cin >> _;
        if (_ == 1)
        {
            int t;
            cin >> t;
            pq.push(t);
            sum += t;
        }
        else if (pq.size())
        {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';

    return 0;
}