// 最大1e6
#include <iostream>
#include <bitset>

using namespace std;

const int N = 2e6 + 5;

bitset<N> vis;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;

    vis[0] = vis[1] = true;

    for(int i = 2; i <= n; ++ i)
        if(!vis[i]) for(int j = i * i; j <= n; j += i) vis[j] = true;

    for (int i = 1; i <= n; i ++) if(!vis[i]) cout << i << ' ';

    return 0 ;
}