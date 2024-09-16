#include <iostream>
#include <bitset>

using namespace std;
const int N = 1003;
int a[N];
bitset<N> t;

int main()
{
    int n; cin >> n;
    for(int i = 1; i<= n; ++ i) cin >> a[i];

    for(int i = 1; i < n; ++ i)
    {
        int tp = abs(a[i + 1] - a[i]);
        if(tp <= n && tp >= 1) t[tp] = true;
    }

    bool res = true;
    
    for (int i = 1; i <= n; ++ i) cout << i << '\n';

    // 你好我是键盘测试

    for(int i = 1; i <= n - 1; ++ i) if(!t[i]) res = false;

    cout << (res ? "Jolly" : "Not jolly");

    return 0;
}