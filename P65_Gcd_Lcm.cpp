#include <iostream>

using namespace std;
using ll = long long;

ll a, b;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    cin >> a >> b;
    ll t = gcd(a, b);
    cout << t << ' ';
    cout << a * b / t << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _; cin >> _;

    while(_ -- ) solve();

    cin >> a >> b;


    return 0;
}