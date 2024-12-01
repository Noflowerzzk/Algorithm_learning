#include <iostream>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 13;

ll x[N], y[N], a[N], b[N], mx;
bitset<N> vis;
int n, k;

ll get_dis(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

ll dfs(int dep, ll sum)
{
    if(dep == k + 1) return sum;

    ll res = -0x8000000000000000;

    for(int i = 1; i <= n; ++ i)
    {
        if(vis[i]) continue;

        vis[i] = 1;
        b[dep] = i;
        res = max(res, dfs(dep + 1, sum + a[i] - get_dis(x[b[dep]], y[b[dep]], x[b[dep - 1]], y[b[dep - 1]])));
        vis[i] = 0;
    }
    return res;
}

void solve()
{
    // mx = -9223372036854775808, vis.reset();
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i) cin >> x[i] >> y[i] >> a[i];
    cout << dfs(1, 0) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;

    while(_ --) solve();

    return 0;
}