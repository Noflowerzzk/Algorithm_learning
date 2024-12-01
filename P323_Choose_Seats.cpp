// 枚举对应选择较少的 基于排列
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 15;

int a[N], b[N];
bitset<N> vis;
ll m, n, Max, cnt;

// 深度x:人数编号, 值:座位编号
int dfs(int x, ll sum)
{
    if(x == m + 1)
        return (ll)(sum >= Max / 2);

    ll res = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(vis[i]) continue;

        vis[i] = true;

        res += dfs(x + 1, sum + b[x] * a[i]);

        vis[i] = false;
    }
    return res;
}

void solve()
{
    cnt = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; ++ i) cin >> a[i];

    for(int i = 1; i <= m; ++ i) cin >> b[i];

    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);

    Max = 0;
    for(int i = n, j = m; j >= 1; -- i, -- j)
        Max += a[i] * b[j];
    // cout << Max << '\n';
    vis.reset();
    cout << dfs(1, 0) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int _; cin >> _;
    while(_ --) solve();

    return 0;
}