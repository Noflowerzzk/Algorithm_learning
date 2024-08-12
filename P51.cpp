#include <iostream>
using namespace std;

const int N = 2e5 + 9;
using ll = long long;

ll a[N];

int f(int n)
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int r = 0;
    while (n != 0)
    {
        r += (n & 1) ? 1 : 0;
        n >>= 1;
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cout << f(a[i]) << '\n';
    return 0;
}