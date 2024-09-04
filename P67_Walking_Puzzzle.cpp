// 用bfs
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int m, n;
const int N = 1e3 + 9;
int mat[N][N];
bool vis[N][N];
int d[N][N];    // 存最小距离
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool inmp(int x, int y)
{
    return (x <= n) && (y <= m) && 1<= x && 1 <= y;
}

void dfs(int x, int y)
{
    // if(vis[x][y])return;
    vis[x][y] = true;

    for(int t = 0; t < 4; ++ t)
    {
        int nx = x + dx[t], ny = y + dy[t];
        if(!mat[nx][ny] && inmp(nx, ny) && !vis[nx][ny])
        {
            d[nx][ny] = min(d[x][y] + 1, d[nx][ny]);
            dfs(nx, ny);
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    memset(d, 0x3f, sizeof(d));
    d[1][1] = 0;
    q.push({x, y});
    vis[x][y] = true;
    while(q.size())
    {
        int x = q.front().first, y = q.front().second; q.pop();

        for(int i = 0; i < 4; ++ i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(!mat[nx][ny] && inmp(nx, ny) && !vis[nx][ny])
            {
                d[nx][ny] = d[x][y] + 1;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];

    bfs(1, 1);

    if(vis[n][m]) cout << d[n][m] << '\n';
    else cout << -1 << '\n';

    return 0;
}