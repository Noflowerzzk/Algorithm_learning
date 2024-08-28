#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bitset<N> vis;

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (vis[x])
            continue; // 来过不看
        vis[x] = true;
        for (auto &y : g[x])
        {
            if (vis[y])
                continue; // 减少队列大小
            q.push(y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (u != v)
            g[u].push_back(v);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
        if (vis[i])
            cout << i << '\n';

    return 0;
}