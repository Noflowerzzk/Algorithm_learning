#include <iostream>

using namespace std;
using ll = long long;

const ll p = 1e9 + 7;
const int N = 1e6 + 2;

ll v[N], x;



void solve()
{
    int n; cin >> n >> x;


    ll sum = 0;
    for (int i = 1; i <= n; ++ i) sum += v[i] % p;

    cout << sum * x % p << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;

    v[1] = 1;

    for (int i = 2; i <= N; ++ i)
    {
        for (int j = 1; j <= i / j; ++ j)
            if(i % j == 0)
                if(j * j == i) v[i] += v[j];
                else v[i] += (v[j] + v[i / j]);
    }


    while(_ --) solve();
    return 0;
}