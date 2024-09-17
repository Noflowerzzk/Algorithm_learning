#include <stdio.h>
#include <math.h>

const int N = 2e6 + 2;
const int M = 5e3 + 2;
bool lamp[N];
int t[M];
double a[M];

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) scanf("%lf %d", &a[i], &t[i]);

    for(int j = 1; j <= n; ++ j)
    {
        int i = 1;
        while(i <= t[j])
        {
            lamp[(int)floor(a[j] * i)] = 1 - lamp[(int)floor(a[j] * i)];
            ++ i;
        }
    }

    for(int i = 1; i <= N; ++ i)
        if(lamp[i])
        {
            printf("%d", i);
            break;
        }
    

   return 0;
}