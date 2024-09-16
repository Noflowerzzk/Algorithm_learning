// 01背包 dp
#include <iostream>

using namespace std;
using ll = long long;
const int N = 105;
int t[N], p[N];
int dp[105][1010];   // 第i个物品为止, 用j的时间 获得的最大价值
int T, M;

void solve()
{
    // 初始化 
    // dp[0][i] = 0
    for(int i = 1; i <= T; ++ i) dp[0][i] = 0;
    for(int i = 1; i <= M; i ++) cin >> t[i] >> p[i];

    // 状态转移
    for(int i = 1; i <= M; ++ i)
        for(int j = 0; j <= T; ++ j)
        {
            // 优化点 : i行只与i - 1行有关
            if(j >= t[i]) dp[i][j] = max(dp[i - 1][j - t[i]] + p[i], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
       }
    cout << dp[M][T] << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while(cin >> T >> M)
    {
        if(T == 0 && M == 0) break;
        solve();
    }


    return 0;
}

