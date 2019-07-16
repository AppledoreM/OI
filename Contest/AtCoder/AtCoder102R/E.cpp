#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 4005;
constexpr int mod = 998244353;
int n,k,c[maxn][maxn],bin[maxn];

void init(){
    c[0][0] = 1;
    for(int i = 1; i <= 4000; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    bin[0] = 1;
    for(int i = 1; i <= 4000; i++) bin[i] = (bin[i - 1] * 2) % mod;
}

ll calc(int p, int y){
    if(y < 0) return 0;
    ll res = 0;
    for(int q = 0; q <= p && q <= n; q++){
        if(q + y - 1 < 0) continue;
        if(n + y - 1 < q + y - 1) continue;
        ll tmp = 1ll * c[p][q] * bin[q] % mod;
        tmp = tmp * c[n + y - 1][q + y - 1] % mod;
        res = (res + tmp) % mod;
    }
    return res;
}

void work(){
    
    for(int i = 2; i <= 2 * k; i++){
        ll ans = 0;
        int cnt = 0;
        for(int j = 1; j <= k; j++){
            if(1 <= i - j && i - j <= k) cnt++;
        }
        if(i & 1) ans = calc(cnt / 2, k - cnt);
        else {
            ans += calc((cnt - 1) / 2, k - cnt);
            n--;
            ans = (ans + calc((cnt - 1) / 2, k - cnt)) % mod;
            n++; 
        }
        cout<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>n;
    init();
    work();

    return 0;
}