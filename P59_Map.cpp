#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

void solve()
{
    int n;
    cin >> n;
    map<string, int> mp;
    vector<string> v;
    while (n--)
    {
        string t;
        cin >> t;
        if (mp.count(t))
            mp[t]++;
        else
        {
            v.push_back(t);
            mp[t] = 1;
        }
    }
    for (auto &i : v)
        cout << i << ' ' << mp[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}