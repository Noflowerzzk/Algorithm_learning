// 基于边的Kruskal 用并查集判断连通性
// 适用于稀疏图 O(E log (E))
#include <iostream>
#include <cstring>
#include <bitset>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct node
{
    ll u, v, w;
    bool operator < (const node &r) const{
        return w == r.w ? (u == r.u ? v < r.v : u < r.w) : w < r.w;
    }
};

int n, m;
const int N = 1e5 + 3;
ll d[N];
vector<node> E;
int pre[N];

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

bool isConnected(int u,int v)
{
    return root(u) == root(v);
}

void merge(int u, int v)
{
    pre[root(u)] = root(v);
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    // memset(a, 0x3f, sizeof(a));

    // for(int i = 1; i <= n; i ++) a[i][i] = 0;
    for(int i = 1; i <= m; i ++)
    {
        ll u, v, w; cin >> u >> v >> w;
        E.push_back({u, v, w});
    }

    sort(E.begin(), E.end());

    ll ans = 0;
    // 并查集初始化
    for(int i = 1; i <= n; ++ i) pre[i] = i;

    for(auto &[u, v, w] : E)
    {
        if(isConnected(u, v)) continue;
        ans += w;
        merge(u, v);
    }

    for ( int i = 1; i < n; i ++ ) if(root(i) != root(i + 1)) ans = -1;

    cout << ans << '\n';
}