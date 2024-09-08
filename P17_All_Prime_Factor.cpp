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


    for (ll i = 2; i <= n / i; ++ i)
    {
        if (n % i != 0) continue;

        f.push_back(i);

        while(n % i == 0) n /= i;
    }
    if(n > 1) f.push_back(n);


    sort(f.begin(), f.end());

    for (auto &i : f) cout << i << ' ';

    return 0;
}