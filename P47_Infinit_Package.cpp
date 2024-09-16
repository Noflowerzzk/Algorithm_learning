#include <iostream>

using namespace std;
using ll = long long;
int m, n;
const int N = 505;
ll w[N];
ll v[N];
ll dp[N][10005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> m >> n;

    for(int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
    
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 0; j <= m; ++j)
        {
            if(j >= v[i]) dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}