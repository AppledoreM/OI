#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 3e5 + 10;
typedef long long ll;
int N,val[maxn],top[maxn],son[maxn],sz[maxn],tid[maxn],rnk[maxn],tot,mx[maxn<<2],dep[maxn],fa[maxn];
ll sum[maxn<<2];
vector<int> G[maxn];

void dfs1(int u,int par){
	dep[u] = dep[par] + 1;
	fa[u] = par;
	sz[u] = 1;
	for(int i = 0; i <  G[u].size(); i++){
		int v = G[u][i];
		if(v == par) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(son[u] == 0 || sz[v] > sz[son[u]]){
			son[u] = v;
		}
	}
}
void dfs2(int u,int tp){
	top[u] = tp;
	tid[u] = ++tot;
	rnk[tot] = u;
	if(!son[u]) return;
	dfs2(son[u],tp);
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v,v);
	}
}
void maintain(int cur){
	mx[cur] = max(mx[cur<<1],mx[cur<<1|1]);
	sum[cur] = sum[cur<<1] + sum[cur<<1|1];
}
void build(int cur,int l,int r){
	if(l == r){
		mx[cur] = sum[cur] = val[rnk[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(cur<<1,l,mid);
	build(cur<<1|1,mid + 1,r);
	maintain(cur);
}
void change(int cur,int l,int r,int a,int b,int delta){
	if(a <= l && r <= b){
		sum[cur] = mx[cur] = delta;
		return;
	}
	int mid = (l + r) / 2;
	if(a <= mid) change(cur<<1,l,mid,a,b,delta);
	if(b > mid) change(cur<<1|1,mid + 1,r,a,b,delta);
	maintain(cur);
}
ll query_sum(int cur,int l,int r,int a,int b){
	if(a <= l && r <= b){
		return sum[cur];
	}
	ll ans = 0;
	int mid = (l + r) / 2;
	if(a <= mid) ans += query_sum(cur<<1,l,mid,a,b);
	if(b > mid) ans += query_sum(cur<<1|1,mid + 1,r,a,b);
	return ans;
}
int query_mx(int cur,int l,int r,int a,int b){
	if(a <= l && r <= b){
		return mx[cur];
	}
	int ans = -999999;
	int mid = (l + r) / 2;
	if(a <= mid) ans = max(ans,query_mx(cur<<1,l,mid,a,b));
	if(b > mid) ans = max(ans,query_mx(cur<<1|1,mid + 1,r,a,b));
	return ans;
}
int path_query_mx(int u,int v){
	int fx = top[u],fy = top[v];
	int re = -999999;
	while(fx != fy){
		if(dep[fx] > dep[fy]){
			re = max(re,query_mx(1,1,tot,tid[fx],tid[u]));	
			u = fa[fx];
		}
		else {
			re = max(re,query_mx(1,1,tot,tid[fy],tid[v]));
			v = fa[fy];
		}
		fx = top[u],fy = top[v];
	}
	if(tid[u] < tid[v]) re = max(re,query_mx(1,1,tot,tid[u],tid[v]));
	else re = max(re,query_mx(1,1,tot,tid[v],tid[u]));
	return re;
}
ll path_query_sum(int x,int y){
	ll re = 0;
	int fx = top[x],fy = top[y];
	while(fx != fy){
		if(dep[fx] > dep[fy]){
			re += query_sum(1,1,tot,tid[fx],tid[x]);
			x = fa[fx];
		}
		else{
			re += query_sum(1,1,tot,tid[fy],tid[y]);
			y = fa[fy];
		}
		fx = top[x],fy = top[y];
	}
	if(tid[x] < tid[y]) re += query_sum(1,1,tot,tid[x],tid[y]);
	else re += query_sum(1,1,tot,tid[y],tid[x]);
	return re;
}
int main(){
	scanf("%d",&N);
	for(int i = 1; i < N; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);		
	}
	for(int i = 1; i <= N; i++) scanf("%d",&val[i]);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,tot);
	int Q;
	scanf("%d",&Q);
	for(int i = 1; i <= Q; i++){
		char opt[10];
		scanf("%s",opt);
		int x,y;
		scanf("%d%d",&x,&y);
		if(opt[1] == 'M'){
			printf("%d\n",path_query_mx(x,y));	
		}
		else if(opt[1] == 'S'){
			printf("%lld\n",path_query_sum(x,y));
		}
		else{
			change(1,1,tot,tid[x],tid[x],y);
		}
	}
	return 0;
}

