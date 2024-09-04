#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>

using namespace std;
using ll = long long;

const int N = 13;

int a[N], n;

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    bool go = true;
    while (go)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << a[i] << ' ';
        }
        go = next_permutation(a + 1, a + 1 + n);
        cout << '\n';
    }
    return 0;
}