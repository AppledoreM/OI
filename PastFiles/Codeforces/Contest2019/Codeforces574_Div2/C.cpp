#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
long long n, a[maxn],b[maxn], dp[maxn][2];


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];

    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i]); 
    }
    cout<<max(dp[n][0], dp[n][1])<<endl;



    return 0;
}