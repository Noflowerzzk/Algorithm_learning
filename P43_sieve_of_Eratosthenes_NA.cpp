// 埃氏筛法
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 2e6 + 5;

vector<int> p;

bool isPrime(int i)
{
    for(auto &j : p)
    {
        if(i % j == 0)return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i = 2; i <= n; i ++) if(isPrime(i)) p.push_back(i);

    for (auto & i : p) cout << i << ' ';
    return 0;
}