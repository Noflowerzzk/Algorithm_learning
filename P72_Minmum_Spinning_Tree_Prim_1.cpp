// 基于点的Prim 朴素 O(n^2)
// 使用邻接矩阵
#include <iostream>
#include <cstring>
#include <bitset>


using namespace std;
using ll = long long;

int n, m;
const int N = 1e5 + 3;
ll a[N][N], d[N];
bitset<N> intree;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    memset(a, 0x3f, sizeof(a));
    memset(d, 0x3f, sizeof(d));

    for(int i = 1; i <= n; i ++) a[i][i] = 0;
    for(int i = 1; i <= n; i ++)
    {
        ll u, v, w; cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);  // 防重边
    }

    intree[1] = true;
    d[1] = 0;   // 将1放入intree

    ll ans = 0;

    for(int i = 1; i <= n; ++ i)
    {
        int u = 1;  // u是离intree的点最近的点
        // 取出树外的离树馁距离最小的点
        for(int j = 1; j <= n; ++ j)
            if(intree[u] || (!intree[u] && d[j] < d[u])) u = j;
        if(u != 1)
            ans += d[u];
        intree[u] = true;
        d[u] = 0;

        // 更新树外点的距离
        for (int j = 1; j <= n; ++ j)
        {
            if(intree[j]) continue;

            d[j] = min(d[j], a[u][j]);
        }

    }

    cout << ans << '\n';

    return 0;
}
