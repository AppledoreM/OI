#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 1e3 + 10, mod = 998244353;
int n,k,a[maxn],dp[maxn][maxn];

int solve(int x){
    dp[0][0] = 1;
    int now = 0;
    for(int i = 1; i <= n; i++){
        while(a[i] - a[now + 1] >= x) now++;
        dp[i][0] = dp[i - 1][0];
        for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i - 1][j] + dp[now][j - 1]) % mod;
        }
    }
    return dp[n][k];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;

    for(int i = 1; i <= 1e5 / (k - 1); i++){
        ans = (ans + solve(i)) % mod;
    }
    cout<<ans<<endl;

    return 0;
}