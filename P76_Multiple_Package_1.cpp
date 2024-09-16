// 时间超限
#include <iostream>

using namespace std;
using ll = long long;
const int N = 2004;
const int W = N * N;

int m, n, s;
int dp[W];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> m >> n;

    for(int i = 1; i <= n; ++ i)
    {
        int s, w, v; cin >> s >> w >> v;
        while(s --)
        {
            for(int j = m; j >= v; -- j)
                dp[j] = max(dp[j], dp[j - v] + w);
        }
    }

    cout << dp[m] << '\n';

    return 0;
}