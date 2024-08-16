#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 9;
int a[N];
bool b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int i = 1, j = 0;
    int ans = 1;
    while (i <= n)
    {
        // b[a[i]] = false, b[a[j]] = false;
        while (!b[a[j + 1]] && j < n)
            b[a[++j]] = true; // true表示在其中
        ans = max(ans, j - i + 1);
        b[a[i]] = false;
        i++;
    }
    cout << ans << '\n';
    memset(b, 0, sizeof(bool) * (N));
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int _;
    cin >> _;
    while (_--)

        solve();

    return 0;
}