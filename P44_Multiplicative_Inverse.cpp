#include <iostream>

using namespace std;
using ll = long long;
const int p = 998244353;

// 用费马小定理 + 快速幂
ll inv(ll x)
{
    ll res = 1, b = p - 2;
    while(b)
    {
        if(b & 1) res = res * x % p;
        b >>= 1;
        x = x * x % p;
    }
    return res;
}

void solve()
{
    ll a, b, c; int q; cin >> a >> b >> c >> q;
    while(q --)
    {
        int x; cin >> x;
        cout << ((a * x % p + b)* inv(c * x % p)) % p << '\n';  // 勿忘记mod p！
    }

}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);

    int _; cin >> _;
    while(_ --) solve();

    return 0;
}