#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n,k,h[maxn],a[maxn],f[maxn];
vector<int> G[maxn];

void dfs(int u){
    h[u] = INT_MAX;
    for(int v : G[u]){
        dfs(v);
        h[u] = min(h[u],h[v] + 1);
        a[u] += a[v];
        f[u] = max(f[u],f[v] - a[v]);
    }
    f[u] += a[u];
    if(h[u] == INT_MAX){
        h[u] = 0;
        f[u] = a[u] = 1;
    }
    if(h[u] >= k) a[u] = 0;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i = 1; i < n; i++){
        int p;
        cin>>p;
        G[p].emplace_back(i + 1);
    }
    dfs(1);
    cout<<f[1]<<endl;
    return 0;
}
