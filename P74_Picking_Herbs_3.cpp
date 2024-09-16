// 01背包 dp
// 滚动数组优化 降空间复杂度
// 压缩成一维
// 单方向转移的优化
#include <iostream>

using namespace std;
using ll = long long;
const int N = 105;
int t[N], p[N];
int dp[1010];   // 到目前为止，花费j时间的最大价值
int T, M;

void solve()
{
    // 初始化 
    // dp[0][i] = 0
    for(int i = 0; i <= T; ++ i) dp[i] = 0;
    for(int i = 1; i <= M; i ++) cin >> t[i] >> p[i];

    // 状态转移
    for(int i = 1; i <= M; ++ i)
    {
        // 复制
        for(int j = T; j >= t[i]; -- j)
        {
            // 从右往左转移
            dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
        }
    }
    cout << dp[T] << '\n';
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

