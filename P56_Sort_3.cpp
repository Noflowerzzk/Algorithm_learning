    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    using ll = long long;

    const int N = 3e6 + 9;

    int a[N];

    int main()
    {
        ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }

        for (int i = 0; i < 2e5; ++i)
            for (int j = 0; j < a[i]; j++)
                cout << i << ' ';

        cout << '\n';
        return 0;
    }