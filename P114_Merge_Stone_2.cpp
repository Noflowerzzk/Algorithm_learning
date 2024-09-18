// 区间dp
// 四边形不等式优化
#include <iostream>
#include <cstring>

using namespace std;

const int N = 302;

int dp[N][N], a[N];   // 表示将区间i, j合并的最小代价
int pre[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;

    memset(dp, 0x3f, sizeof dp);

    for(int i = 1; i <= n; ++ i) cin >> a[i];

    for(int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + a[i];

    for(int i = 1; i <= n; ++ i) dp[i][i] = 0;

    for(int len = 2; len <= n; ++ len)    // 枚举区间长度 dp顺序 : 由小区间到大区间
        for(int i = 1, j = i + len - 1; j <= n; ++ i, ++ j)
            for(int k = i; k < j; ++ k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1]);

    cout << dp[1][n] << '\n';
    return 0;
}