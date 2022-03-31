#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353; 
constexpr int maxn = 100005;
ll a[maxn], pre[30];
int cnt[15], sum_cnt[15];


void init(){
    pre[0] = 1;
    for(int i = 1; i < 30; i++){
        pre[i] = pre[i - 1] * 10 % mod;
    }
} 


int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        cnt[(int)to_string(a[i]).size()]++;
    }

    ll ans = 0;
    ll prev = 0;
    for(int i = 1; i <= n; i++){
        string tmp = to_string(a[i]);
        reverse(tmp.begin(), tmp.end());
        ll sum = 0;
        prev = ans;
        for(int j = 1; j <= 10; j++){
            ll tmp_pow = pre[10, 2 * (j - 1)];
            if(j <= (int) tmp.size()) sum = (sum + tmp_pow * 1ll * ((int) tmp[j - 1] - '0') % mod) % mod;
            ll tmp_sum = 0;
            for(int k = j + 1; k <= tmp.size(); k++){
                tmp_pow = pre[10, 2 * (j - 1) + (k - j) + 1];
                tmp_sum = (tmp_sum + tmp_pow * 1ll * ((int) tmp[k - 1] - '0') % mod) % mod;
            }
            ans = (ans + tmp_sum * cnt[j] % mod) % mod;
            ans = (ans + sum * cnt[j] % mod) % mod;
        }
        sum = 0;
        prev = ans;
        for(int j = 1; j <= 10; j++){
            ll tmp_pow = pre[2 * (j - 1) + 1];
            if(j <= (int) tmp.size()) sum = (sum + tmp_pow * 1ll * ((int) tmp[j - 1] - '0') % mod) % mod;
            ll tmp_sum = 0;
            for(int k = j + 1; k <= tmp.size(); k++){
                tmp_pow = pre[2 * (j - 1) + 1 + (k - j)];
                tmp_sum = (tmp_sum + tmp_pow * 1ll * ((int) tmp[k - 1] - '0') % mod) % mod;
            }
            ans = (ans + tmp_sum * cnt[j] % mod) % mod;
            ans = (ans + sum * cnt[j] % mod) % mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}