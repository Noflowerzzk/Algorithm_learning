#include <iostream>
using namespace std;

const int N = 1e3 + 9;

using ll = long long;
ll prefix[N][N], a[N][N], d[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    // 二维差分
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            d[i][j] += a[i][j];
            d[i + 1][j] -= a[i][j];
            d[i][j + 1] -= a[i][j];
            d[i + 1][j + 1] += a[i][j];
            // 修改同理
        }
    // 还原a
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}