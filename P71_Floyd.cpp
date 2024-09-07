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

const int N = 1e5 + 5;ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
ll d[N][N];


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> n >> m >> q;

    memset(d, 0x3f, sizeof(d));

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], static_cast<ll>(w));
    }

    for (int k = 1;k <= n; ++ k)
        for (int i = 1; i <= n ; ++ i)
            for (int j = 1; j <= n; ++ j)
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]);

    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (d[u][v] >= inf ? -1 : d[u][v]) << '\n';
    }
    return 0;
}