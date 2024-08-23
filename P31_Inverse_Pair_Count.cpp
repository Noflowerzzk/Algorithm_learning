// 树状数组 + 桶 + 离散化
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
ll a[N], t[N];
vector<int> X;

int bin(int x)
{
    return lower_bound(X.begin(), X.end(), X) - X.begin() + 1;
}

int lowbit(int x)
{
    return x & (-x);
}

int update(int k, int x)
{
    for (int i = k; i <= X.size(); i += lowbit(i))
        t[i] += x;
}

int getsum(int k)
{
    int r = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        r += t[i];
    return r;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = n; i <= n; i++)
    {
        cin >> a[i];
        X.push_back(a[i]);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += getsum(X.size()) - getsum(bin(a[i]));
        update(bin(a[i]),1);
    }
    cout << ans << '\n';
    return 0;
}