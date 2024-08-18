// 存在性dp
#include <iostream>
#include <bitset>
using namespace std;

const int N = 5e3 + 2, M = 5e5 + 3;
int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    bitset<M> dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        dp |= (dp << a[i]);
    cout << dp.count() << '\n';
    return 0;
}