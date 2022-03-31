#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005;
constexpr long long mod = 998244353;
typedef long long ll;
int n,m;
vector<int> v, tmp;
vector<int> pos[maxn];
int LoID[maxn];
ll dp[maxn][maxn];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        int x;
        cin>>x;
        tmp.emplace_back(x);
    }

    for(int i = 0; i < m; i++){
        if(i > 0){
            if(v.back() == tmp[i]){
                continue;
            }
        }
        v.emplace_back(tmp[i]);
        pos[tmp[i]].emplace_back((int) v.size());
    }

    m = (int) v.size();
    if(m > 2 * n){
        cout<<0<<endl;
        exit(0);
    }
    for(int i = 0; i < m; i++){
        LoID[i + 1] = v[i];
    }
    for(int i = 1; i <= m + 1; i++) for(int j = 1; j <= m + 1; j++) dp[i][j] = 1;

    for(int len = 0; len <= m; len++){
        for(int i = 1; i + len <= m; i++){
            int mnid = 999;
            for(int j = i; j <= i + len; j++) mnid = min(mnid, LoID[j]);
            int mn = m + 1, mx = 0;
            for(auto x : pos[mnid]){
                mn = min(mn, x);
                mx = max(mx, x);
            } 
            if(mn < i || mx > i + len) 
            {
                dp[i][i + len] = 0;
                continue;
            }
            ll sumleft = (i != mn) ? 2 * dp[i][mn - 1] % mod : 1;
            for(int j = i; j < mn - 1; j++){
                sumleft = (sumleft + dp[i][j] * dp[j + 1][mn - 1] % mod) % mod;
            }
         
            ll sumright = (mx != i + len) ? 2 * dp[mx + 1][i + len] % mod : 1;
            for(int j = mx + 1; j < i + len; j++){
                sumright = (sumright + dp[mx + 1][j] * dp[j + 1][i + len] % mod) % mod;
            }
            ll res = sumleft * sumright % mod;
            for(int i = 1; i < (int) pos[mnid].size(); i++){
                res = res * dp[pos[mnid][i - 1] + 1][pos[mnid][i] - 1] % mod;
            }
            dp[i][i + len] = res;
        }
    }

    cout<<dp[1][m]<<endl;





    return 0;
}