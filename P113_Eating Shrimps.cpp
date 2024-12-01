#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 1e4 + 3;

struct Node{
    int end, w;
};

vector<Node> g[N];
bitset<N> vis;
int v[N];

void solve()
{
    for(int i = 1; i <= N; ++ i) g[i].clear();

    int m, n, k; cin >> m >> n >> k;

    for(int i = 1; i <= k; ++ i) cin >> v[i];

    for(int i = 1; i <= m; ++ i)
    {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    ll sum = -1;
    // for(int i = 1; i <= k; ++ i) sum = max(sum, djistra(v[i]));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _; cin >> _;

    while(_ --) solve();

    return 0;
}