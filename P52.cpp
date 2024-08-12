#include <iostream>
using namespace std;

const int N = 1e3 + 5;
long long a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int x = a[0];
    for (int i = 1; i < n; ++i)
        x ^= a[i];
    cout << x << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }

    return 0;
}