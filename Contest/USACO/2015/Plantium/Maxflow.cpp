#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n,k;
vector<int> G[maxn];
int tot,tree[maxn<<2],tag[maxn<<2], mx[maxn<<2];
int fa[maxn], dep[maxn], top[maxn], son[maxn], sz[maxn], tid[maxn], rnk[maxn], fath[maxn][20];

void dfs1(int u,int par){
    sz[u] = 1;
    fa[u] = par;
    fath[u][0] = par;
    dep[u] = dep[par] + 1;
    for(int v : G[u]){
        if(v == par) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        if(son[u] == 0 || sz[v] > sz[son[u]]) son[u] = v;
    }
}

void dfs2(int u,int tp){
     top[u] = tp;
     rnk[++tot] = u;
     tid[u] = tot;
     if(!son[u]) return;
     dfs2(son[u],tp);
     for(int v : G[u]){
        if(v == son[u] || v == fa[u]) continue;
        dfs2(v,v);
     }
}

void build_lca(){
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n; j++){
            fath[j][i] = fath[fath[j][i - 1]][i - 1];
        }
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    int t = log2(dep[x] - dep[y]);
    for(int i = t; i >= 0; i--){
        if(dep[x] - dep[y] >= (1 << i)) x = fath[x][i];
    }
    if(x == y) return x;
    t = log2(dep[x]);
    for(int i = t; i >= 0; i--){
        if(fath[x][i] != fath[y][i]){
            x = fath[x][i];
            y = fath[y][i];
        }
    }
    return fath[x][0];
}

void pushdown(int cur){
    if(tag[cur]){
        tree[cur<<1] += tag[cur];
        tree[cur<<1|1] += tag[cur];
        mx[cur<<1] += tag[cur];
        mx[cur<<1|1] += tag[cur];
        tag[cur] = 0;
    }
}

void change(int cur,int l,int r,int a,int b,int delta){
    if(a <= l && r <= b){
        tree[cur] += delta;
        mx[cur] += delta;
        tag[cur] += delta;
        return;
    }
    pushdown(cur);
    int mid = (l + r) / 2;
    if(a <= mid) change(cur<<1,l,mid,a,b,delta);
    if(b > mid) change(cur<<1|1,mid +1,r,a,b,delta);
    mx[cur] = max(mx[cur<<1],mx[cur<<1|1]);
}


void query(int cur,int l,int r){
    if(l >= r) return;
    pushdown(cur);
    int mid = l + r >> 1;
    query(cur<<1,l,mid);
    query(cur<<1|1,mid + 1,r);
    mx[cur] = max(mx[cur<<1],mx[cur<<1|1]);
}

void change_chain(int x,int y){
    int fx = top[x], fy = top[y];
    while(fx != fy){
        if(dep[fx] > dep[fy]){
            change(1,1,tot,tid[fx],tid[x],1);
            x = fa[fx];
        }
        else{
            change(1,1,tot,tid[fy],tid[y],1);
            y = fa[fy];
        }
        fx = top[x], fy = top[y];
    }
    if(tid[x] < tid[y]) change(1,1,tot,tid[x],tid[y],1);
    else change(1,1,tot,tid[y],tid[x],1);
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
    dfs1(1,0);
    dfs2(1,1);
    for(int i = 1; i <= k; i++){
        int u,v;
        cin>>u>>v;
        change_chain(u,v);
    }
    query(1,1,tot);
    cout<<mx[1]<<endl;
    return 0;
}
