#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
ll last;
int Q,tot,lca[maxn][21],cnt;
ll wei[maxn],sum[maxn][21];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>Q;
    tot = 1;
    for(int i = 0; i <= 20; i++) sum[1][i] = 1e16;
    wei[0] = INT_MAX;
    for(int i = 1; i <= Q; i++){
        ll opt,p,q;
        cin>>opt>>p>>q;
        if(opt == 1){
            ll u = p xor last;
            ll w = q xor last;
            wei[++tot] = w;
            if(wei[u] >= wei[tot]) lca[tot][0] = u;
            else{
                int now = u;
                for(int i = 20; i >= 0; i--){
                    int ances = lca[now][i];
                    if(!ances) continue;
                    if(wei[ances] < wei[tot]) now = ances;
                }
                lca[tot][0] = lca[now][0];
            }
            sum[tot][0] = (lca[tot][0] == 0 ? 1e16 : wei[lca[tot][0]]);
            for(int i = 1; i <= 20; i++){
                lca[tot][i] = lca[lca[tot][i - 1]][i - 1];
                sum[tot][i] = (lca[tot][i] == 0 ? 1e16 : sum[tot][i - 1] + sum[lca[tot][i - 1]][i - 1]);
            }
        }
        else{
            ll u = p xor last;
            ll x = q xor last;
            if(wei[u] > x) {
                cout<<0<<endl;
                last = 0;
            }
            else{
                x -= wei[u];
                int ans = 1;
                for(int i = 20; i >= 0; i--){
                    if(sum[u][i] <= x){
                        x -= sum[u][i];
                        u = lca[u][i];
                        ans += (1 << i);
                    }
                }
                cout<<ans<<endl;
                last = ans;
            }
        }
    }
    return 0;
}
