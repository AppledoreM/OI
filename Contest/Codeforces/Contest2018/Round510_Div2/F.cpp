#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> G[maxn];
int n,k,ans;

int dfs(int u,int par = 0){
    if(G[u].size() == 1) return 0;
    vector<int> ch;
    for(int v : G[u]){
        if(v == par) continue;
        ch.emplace_back(dfs(v,u) + 1);
    }
    sort(ch.begin(),ch.end());
    while(ch.size() >= 2){
        if(ch.back() + ch[ch.size() - 2] <= k) break;
        ans++;
        ch.pop_back();
    }
    return ch.back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;

    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(G[i].size() > 1) {
            dfs(i);
            break;
        }
    }
    cout<<ans + 1<<endl;
    return 0;
}
