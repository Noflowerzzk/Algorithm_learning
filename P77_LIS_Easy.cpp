#include <iostream>

using namespace std;
using ll = long long;
const int N = 1e3 + 4;

ll a[N], dp[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i];

    for(int i = 1; i <= n; ++ i)
    {
        dp[i] = 1;
        for(int j = i - 1; j >= 1; -- j) if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++ i) ans  = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}