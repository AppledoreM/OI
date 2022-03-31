#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int n,sz[maxn],cnt;
ll ans;
vector<int> G[maxn];

void dfs(int u,int par,int dep){
    sz[u] = 1;
    if(dep & 1) cnt++;
    for(int v: G[u]){
        if(v == par) continue;
        dfs(v,u,dep + 1);
        sz[u] += sz[v];
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1,0,1);
    for(int i = 1; i <= n; i++){
        ans += 1ll * sz[i] * (n - sz[i]);
    }
    ans += 1ll * cnt * (n - cnt);
    cout<<ans/2<<endl;
    return 0;
}
