// 数据很多，修改很少
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll inf = 8e18;
const int N = 3e5 + 9;
vector<int> X;   // 离散化数组
ll a[N];

struct Pair
{
    int a;ll b;
}add[N], que[N];

// 获取下标, 二分, STL
int getIdX(int x){
    // 找出数组中最前面的 >= x的元素的迭代器,
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;  // 从1开始
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q; 
    // 先存下来
    for (int i = 1; i <= n; i++){
        int x, w; cin >> x >>w;
        X.push_back(x); 
        add[i] = {x, w};
    }
    for (int i = 1; i <= q; i ++)
    {
        int l, r; cin >> l >> r;
        X.push_back(l); X.push_back(r);
        que[i] = {l, r};
    }

    // 排序去重
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    // 更改
    for(int i = 1; i <= n;++i){
        Pair t = Pair{getIdX(add[i].a), add[i].b};
        a[t.a] += t.b;
    }

    // 前缀和
    for(int i =1; i <= X.size(); i ++) a[i] += a[i - 1];
    // 询问与输出
    for (int i = 1; i <= q; ++ i){
        Pair t = Pair{getIdX(que[i].a), getIdX(que[i].b)};
        cout << a[t.b] - a[t.a - 1] << '\n';
    }
    return 0;
}   