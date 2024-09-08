// 基于点的Prim 堆优化
// 使用邻接表
// 适用于稠密图 O(V log (V))
#include <iostream>
#include <cstring>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

struct node
{
    ll x, w;
    bool operator < (const node &r) const{
        return w == r.w ? x < r.x : w > r.w;
    }
};

int n, m;
const int N = 1e5 + 3;
ll d[N];
bitset<N> intree;
vector<node> g[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    // memset(a, 0x3f, sizeof(a));
    memset(d, 0x3f, sizeof(d));

    // for(int i = 1; i <= n; i ++) a[i][i] = 0;
    for(int i = 1; i <= n; i ++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ll ans = 0;

    priority_queue<node> pq;
    pq.push({1, 0});
    d[1] = 0;
    intree[1] = true;

    while(pq.size())
    {
        int x = pq.top().x, w = pq.top().w; pq.pop();

        if(intree[x]) continue;
        intree[x] = true;

        ans += w;
        d[x] = 0;

        for (auto &[y, w] : g[x])
        {
            if(!intree[y] && w < d[y])
            {
                d[y] = w;
                pq.push({y, w});
            }
        }
    }

    for (int i = 1; i <= n; i ++)
        if(!intree[i]) ans = -1;

    cout << ans << '\n';

    return 0;
}
