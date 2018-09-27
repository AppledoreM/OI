#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
typedef long long ll;
ll n,a[maxn],b[maxn],sum[maxn],ans;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) b[i] = __builtin_popcountll(a[i]);
    ll cnt_even,cnt_odd;
    cnt_even = 1;
    cnt_odd = 0;
    for(int i = n; i >= 1; i--) {
        sum[i] = sum[i + 1] + b[i];
        if(sum[i] & 1) ans += cnt_odd;
        else ans += cnt_even;
        if(sum[i] & 1) cnt_odd++;
        else cnt_even++;
    }
    for(int i = 1; i <= n; i++){
        ll mx = 0;
        for(int j = i; j <= n && j - i < 64; j++){
            mx = max(mx,b[j]);
            if(sum[i] - sum[j + 1] < 2 * mx && (sum[i] - sum[j + 1]) % 2 == 0) ans--;
        }
    }
    cout<<ans<<endl;

    return 0;
}
