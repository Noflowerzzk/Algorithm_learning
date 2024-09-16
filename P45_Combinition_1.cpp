// 用dp计算
#include <iostream>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7, N = 2024;
int m, n;
ll c[N][N];


ll com(int i, int j)
{
    if (i < j) return 0;

}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++ i) c[i][0] = 1ll;

    for(int i = 1; i < n; i ++)
        for(int j = 1; j <= i && j < m; j ++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;

    for(int i = 0; i < n; ++ i)
    {
       for(int j = 0; j < m; ++ j) cout << c[i][j] << ' ';
       cout << '\n';
    }
    return 0;
}