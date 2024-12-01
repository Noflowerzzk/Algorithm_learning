// 基于子集
#include <iostream>

using namespace std;
using ll = long long;

const int N = 28;

ll n, k, a[N];

ll dfs(int x, ll sum)
{
    if(x == n + 1)
        return (ll)(sum <= k);     

    return dfs(x + 1, sum) + dfs(x + 1, sum + a[x]);
}

void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i) cin >> a[i];

    cout << dfs(1, 0) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while(_ --) solve();

    return 0;
}