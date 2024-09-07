// 并查集 维护联通关系
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int m, n;
int pre[N], cnt[N];

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int u, int v)
{
    pre[root(u)] = root(v);
    return;
}

// 暂时没用
bool is_connected(int x, int y)
{
    return root(x) == root(y);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n ; ++ i) pre[i] = i;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    // 用桶
    for(int i = 1; i <= n; ++ i ) cnt[root(i)] ++;

    vector<int> v;

    for (int i = 1; i <= n; ++ i) if(cnt[i]) v.push_back(cnt[i]);

    sort(v.begin(), v.end());

    for (auto &i : v) cout << i << ' ';

}