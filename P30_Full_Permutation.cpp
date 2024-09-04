// dfs + 回溯
#include <iostream>
#include <vector>
// #include <string>

using namespace std;
using ll = long long;
const int N = 11;
int n;

vector<int> g[N];
bool vis[N];
int c[N];

void dfs(int x) // x 表示深度
{
    if (x == n + 1){
        for (int i = 1; i <= n ; ++ i){
            cout << c[i];
            if(i == n) cout << '\n';
            else cout << ' ';
            }
    }

    else
    {
        for (int i = 1; i <= n; ++i)
        { // 回溯法
            if (vis[i])
                continue;
            vis[i] = true;
            c[x] = i;
            dfs(x + 1);
            vis[i] = false; // 恢复
            c[x] = 0;
        }
    }
}

// void generate(int n )
// {
//     for (int i  = 1; i <= n; i ++)
//     {
//         if(used[i])continue;
//         g[n].push_back(i);
//         used[i] = true;
//     }
// }

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(1);
    return 0;
}