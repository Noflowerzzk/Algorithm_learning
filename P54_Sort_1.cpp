#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 9;
vector<long long> a;

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        long long t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (auto &i : a)
        cout << i << ' ';
    return 0;
}