// 树形dp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
void dfs(int x, int pre);

const int N = 1e5 + 2;

vector<int> g[N];
ll w[N], dp[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> w[i];
    for(int i = 1; i <= n; ++ i)
    {
        dp[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i < n; ++ i)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    dfs(3, -1);
    cout << *max_element(dp + 1, dp + 1 + n) << '\n';
}

void dfs(int x, int pre)
{
    dp[x] = w[x];
    for(auto &y : g[x])
    {
        if(y == pre) continue;
        dfs(y, x);
        if(dp[y] > 0) dp[x] += dp[y];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while(_ --) solve();

    return 0;
}