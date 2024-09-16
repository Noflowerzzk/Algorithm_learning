// 01背包 dp
// 滚动数组优化 变为一维 降空间复杂度
#include <iostream>

using namespace std;
using ll = long long;
const int N = 105;
int t[N], p[N];
int dp[2][1010];   // 第i个物品为止, 用j的时间 获得的最大价值
int T, M;

void solve()
{
    // 初始化 
    // dp[0][i] = 0
    for(int i = 0; i <= T; ++ i) dp[0][i] = 0;
    for(int i = 1; i <= M; i ++) cin >> t[i] >> p[i];

    // 状态转移
    for(int i = 1; i <= M; ++ i)
    {
        int x = i & 1;  // x表示当前行(0 || 1)
        for(int j = 0; j <= T; ++ j)
        {
            if(j >= t[i]) dp[x][j] = max(dp[1 ^ x][j - t[i]] + p[i], dp[x ^ 1][j]);
            else dp[x][j] = dp[x ^ 1][j];
        }
    }
    cout << dp[M & 1][T] << '\n';
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

