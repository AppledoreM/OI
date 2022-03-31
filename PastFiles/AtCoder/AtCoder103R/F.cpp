#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<ll,int>> v;
vector<int> fa,siz;
vector<vector<int>> G;
ll tot;
void dfs(int u,int par,ll d){
    tot += d;
    for(int v : G[u]){
        if(v == par) continue;
        dfs(v,u,d + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    v.resize(n + 1);
    fa.resize(n + 1);
    siz.resize(n + 1);
    G.resize(n + 1);
    fill(fa.begin(),fa.end(),0);
    fill(siz.begin(),siz.end(),1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.begin() + 1,v.end(),[](auto x,auto y){ return x.first > y.first;});
    for(int i = 1; i < n; i++){
        ll d = v[i].first;
        int sz = siz[v[i].second];
        ll d_nxt = d - n + 2 * sz;
        int lo = i + 1, hi = n;
        int ans_pos = 0;
        while(lo <= hi){
            int mid = lo + hi >> 1;
            if(v[mid].first > d_nxt){
                lo = mid + 1;
            }
            else if(v[mid].first < d_nxt){
                hi = mid - 1;
            }
            else {
                ans_pos = mid;
                break;
            }
        }
        if(ans_pos == 0){
            cout<<-1<<endl;
            exit(0);
        }
        int u = v[i].second;
        int f = v[ans_pos].second;
        fa[u] = f;
        G[f].emplace_back(u);
        G[u].emplace_back(f);
        siz[f] += siz[u];
    }
    dfs(v[n].second,0,0);
    if(tot != v[n].first){
        cout<<-1<<endl;
        exit(0);
    }
    for(int i = 1; i < n; i++){
        cout<<v[i].second<<" "<<fa[v[i].second]<<endl;
    }

    return 0;
}
