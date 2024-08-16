#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;

ll a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--)
    {
        int l = 0, r = n;

        int x;
        cin >> x;
        while (l + 1 != r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] < x)
                l = mid;
            else
                r = mid;
        }
        cout << ((a[r] == x) ? (l + 1) : -1) << ' ';
    }

    return 0;
}
