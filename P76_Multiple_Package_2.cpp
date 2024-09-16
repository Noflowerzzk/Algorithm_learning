// 二进制优化 log 
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int N = 2004;

int dp[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m, n; cin >> m >> n;

    for(int i = 1; i <= n; ++ i)
    {
        int s, w, v; cin >> s >> w >> v;

        vector<int> v1;
        int x = 1;

        while(s >= x) v1.push_back(x), s -= x, x <<= 1;
        if(s) v1.push_back(s);

        for(auto &k: v1)
            for(int j = m; j >= v * k; -- j)
                dp[j] = max(dp[j], dp[j - k * v] + k * w);

    }

    cout << dp[m] << '\n';
    
    return 0;
}