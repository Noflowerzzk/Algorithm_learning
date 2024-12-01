// 相当于等权最短路
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const int N = 2e6 + 3;

vector<int> dep(N, -1);

int (*func[3])(int) = {
    [](int x){return static_cast<int>(1.6 * x);}, 
    [](int x){return static_cast<int>(0.6 * x);},
    [](int x){return x + 1;}
};

int bfs(int x, int y)
{
    dep[x] = 0;
    queue<int> q;
    q.push(x);

    while(q.size())
    {
        int u = q.front(); q.pop(); 
        for(int i = 0; i < 3; ++ i)
        {
            int v = func[i](u);
            if(v >= 2e6 || v < 0 || dep[v] != -1) continue;

            dep[v] = dep[u] + 1;
            if(v == y) return dep[v];
            q.push(v);
        }
    }
}

void solve()
{
    int x, y; cin >> x >> y;
    cout << bfs(x, y) << '\n';
    fill(dep.begin(), dep.end(), -1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;

    while(_ --) solve();

    return 0;
}