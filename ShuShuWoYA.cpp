#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int ty[N];
ll a[N], p[N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> ty[i];
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        ll ess = 0;
        for (int i = 1; i <= n; i++)
            ess += a[i] * ty[i];

        for (int i = 1; i <= n; ++i)
            p[i] = (-2 * ty[i] + 1) * a[i] + p[i - 1];

        ll mi = 0, Fix = 0;
        for (int i = 1; i <= n; ++i)
        {
            Fix = max(Fix, p[i] - mi);
            mi = min(p[i], mi);
        }
        cout << ess + Fix << '\n';
    }
    return 0;
}