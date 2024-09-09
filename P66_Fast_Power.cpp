#include <iostream>

using namespace std;
using ll = long long;


void solve()
{
    ll a, b, c; cin >> a >> b >> c;
    ll res = 1;

    // 二进制拆分 每次取模
    while(b)
    {
        if(b & 1) res = res * a % c;
        // res %= c;
        b >>= 1;
        a = a * a % c;
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while(_ --) solve();

    return 0;
}