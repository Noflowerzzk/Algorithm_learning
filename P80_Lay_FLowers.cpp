#include <iostream>

using namespace std;
using ll = long long;
const int N = 102;
const int p = 1e6 + 7;
ll a[N];
ll dp[N][N];    // 放到第i种花为止，放了j盆花的种类数

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> a[i];

    dp[0][0] = 1;

    for(int i = 1; i <= n; ++ i)
        for(int j = 0;j <= m; ++ j)
            for(int k = 0; k <= a[i] && k <= j; ++ k)
                dp[i][j] = (dp[i - 1][j - k] + dp[i][j]) % p;

    cout << dp[n][m] << '\n';
    return 0;
}