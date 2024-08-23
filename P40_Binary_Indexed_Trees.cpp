#include <iostream>

using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int a[N], t[N];
int n, q;

int lowbit(int x)
{
    return x & (-x);
}

void update(int u, ll v)
{
    for (int i = u; i <= n; i += lowbit(i))
        t[i] += v;
}

ll getsum(ll x)
{
    ll sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += t[i];
    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        update(i, a[i]);
    while (q--)
    {
        int _;
        cin >> _;
        if (_ == 1)
        {
            ll k, v;
            cin >> k >> v;
            update(k, v);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << getsum(r) - getsum(l - 1) << '\n';
        }
    }
    return 0;
}