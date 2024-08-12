#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct books
{
public:
    ll h, s, w;
    bool operator<(const books &rhs) const
    {
        if (h != rhs.h)
            return h < rhs.h;
        else if (s != rhs.s)
            return s < rhs.s;
        else if (w != rhs.w)
            return w < rhs.w;
        else
            return false;
    }
};

int cmp(const books &a, const books &b)
{
    return b < a;
}

const int N = 2e5 + 9;
books a[N];

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i].h >> a[i].s >> a[i].w;

    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
        cout << a[i].h << ' ' << a[i].s << ' ' << a[i].w << '\n';

    return 0;
}