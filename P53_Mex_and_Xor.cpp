#include <iostream>
using namespace std;

const int N = 2e5 + 9;

int pre[N];

void solve()
{
    int a, b;
    cin >> a >> b;
    int y = pre[a - 1] ^ b;
    if (y == a)
        cout << a + 2 << '\n';
    else if (y == 0)
        cout << a << '\n';
    else
        cout << a + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 0; i < N; i++)
        pre[i] = pre[i - 1] ^ i;
    int _;
    cin >> _;
    while (_--)
        solve();

    return 0;
}