#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

constexpr int maxn = 2005;
int a[2005], dp[maxn][maxn];
int sum[2005];

int n, h, l, r;
int pt = 1;
int calc(int i,int j){
    int x = (sum[i] - j) % h;
    return l <= x && x <= r;
}

int main()
{
    FAST_IO;
    cin>>n>>h>>l>>r;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; ++i){
        sum[i] += a[i] + sum[i - 1];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= i; ++j){
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + calc(i, j));
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + calc(i, j));
        }
    }

    int ans = 0;
    for_each(begin(dp[n]), end(dp[n]), [&](auto x){ ans = max(ans, x); });
    cout<<ans<<endl;


    return 0;
}

