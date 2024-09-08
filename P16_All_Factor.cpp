#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n; cin >> n;
    vector<ll> f;
    f.push_back(1);

    if(n == 1)
    {
        cout << 1;
        return 0;
    }

    for (ll i = 2; i <= n / i; ++ i)
    {
        if (n % i) continue;

        f.push_back(i);
        if(i != n / i) f.push_back(n / i);
    }


    sort(f.begin(), f.end());
    f.push_back(n);

    for (auto &i : f) cout << i << ' ';

    return 0;
}