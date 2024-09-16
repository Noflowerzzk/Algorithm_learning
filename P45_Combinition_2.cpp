// 要求默写
#include <iostream>

using namespace std;
using ll = long long;
const ll p = 1e9 + 7, N = 1e7 + 5;;
ll fac[N];

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
}

ll Com(int n, int m)
{
    if(n < 0 || m < 0 || n < m) return 0;
    return fac[n] * inv(fac[n - m] * fac[m] % p) % p;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init(1e7);    

    int _; cin >> _;
    while (_ --)
    {
        int n, m;
        cin >> n >> m;
        cout << Com(n, m) << '\n';
    }

    return 0;
}