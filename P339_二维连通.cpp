#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e3 + 3;

bool a[N][N], vis[N][N];
int m, n, k;
int _x[4] = {0, 1, 0, -1},
    _y[4] = {-1, 0, 1, 0};

bool out(int x, int y)
{
    return x <= 0 || y <= 0 || x > n || y > n;
}

int dfs(int x, int y)
{
    int res = 1;
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++ i)
    {
        int _i = x + _x[i], _j = y + _y[i];
        if(out(_i, _j) || vis[_i][_j] || a[_i][_j]) continue;
        res += dfs(_i, _j);
    }
    return res;
}

void solve()
{
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j) vis[i][j] = 0;
    cin >> m >> n >> k;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j) cin >> a[i][j];

    vector<int> v;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i][j] == 0 && !vis[i][j])
            {
                int cnt = dfs(i, j);
                if(cnt >= k) v.push_back(cnt);
            }
    
    if(v.size())
    {
        sort(v.begin(), v.end());
        for(auto &x : v) cout << x << ' ';
        cout << '\n';
    }
    else cout << -1 << '\n';

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;

    while(_ --) solve();

    return 0;
}