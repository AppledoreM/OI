#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
ll n,dp[maxn],cnt[maxn],par[maxn],sum[maxn];
const ll mod = 1e9 + 7;

void update(ll &x, ll y){
    x += y;
    if(x >= mod) x -= mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>sum[i];
    for(int i = 2; i <= n; i++) cin>>par[i];
    for(int i = n; i >= 1; i--) sum[par[i]] += sum[i];
    for(int i = n; i >= 1; i--){
        ll tmp = sum[1] / __gcd(sum[1],sum[i]);
        if(tmp <= n) cnt[tmp]++;
    }
    for(int i = n; i >= 1; i--){
        for(int j = 2 * i; j <= n; j += i){
            update(cnt[j],cnt[i]);
        }
    }
    long long ans = 0;
    dp[1] = 1;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == i){
            update(ans,dp[i]);
            for(int j = 2 * i; j <= n; j += i){
                if(cnt[j] == j) update(dp[j],dp[i]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
