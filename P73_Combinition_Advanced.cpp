#include <iostream>

using namespace std;
using ll = long long;
const ll p = 1e9 + 7, N = 1e7 + 5;;
ll fac[N], invfac[N];

ll quickPower(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

ll inv(ll x)
{
    return quickPower(x, p - 2);
}

// fac初始化
void init(ll a)
{
    fac[0] = 1;
    for ( int i = 1; i <= a; ++ i)
        fac[i] = fac[i - 1] * i % p;
    invfac[a] = inv(fac[a]);
    for(ll i = a - 1; i >= 1; -- i) invfac[i] = invfac[i + 1] * (i + 1) % p;
}

ll Com(ll n, ll m)
{
    if(n < 0 || m < 0 || n < m) return 0;
    return fac[n] * invfac[n - m] % p * invfac[m] % p;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init(1e7);    

    ll q, a, b, c, n, m;
    cin >> q >> a >> b >> c >> n >> m;
    ll ans = 0;

    while (q --)
    {
        ans = (Com(n, m) + ans) % p;
        n = ((n * a) % c + b) % c;
        m = ((m * b) % c + a) % c;
    }
    cout << ans << '\n';

    return 0;
}