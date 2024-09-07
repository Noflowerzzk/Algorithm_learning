// Dijkstra 单源最短路 贪心(每次找最近点) + dp(选最优方案)
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;
using ll = long long;

struct node
{
    int x, w;   // x为出点, w为权值
};


const int N = 1e5 + 5;
int m, n;
vector<node> g[N];
bitset<N> vis;
ll d[N];

void Dijkstra(int st)
{
    memset(d, 0x3f, sizeof(ll) * (n + 1));
    d[st] = 0;

    for(int i = 1; i <= n; ++ i)
    {
        // 找最小点
        int u = 1;
        for(int j = 1; j <= n; ++ j)
            if(vis[u] || (!vis[j] && d[j] < d[u])) u = j;

        vis[u] = true;

        // 此时d[u]是最小的(贪心)
        // 更新其出点
        for (auto &[v, w] : g[u])
            if(!vis[v])
                d[v] = min(d[v], d[u] + w);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(u != v) g[u].push_back({v, w});
    }


    Dijkstra(1);

    cout << (d[n] >= 0x3f3f3f3f3f3f3f3f ? -1 : d[n]) << '\n';

    return 0;
}
