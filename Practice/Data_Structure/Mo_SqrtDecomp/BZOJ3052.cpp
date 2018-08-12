#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;
#define _ 0
const int maxn = 200010;
int N,M,Q,val[maxn],wei[maxn],col[maxn],bel[maxn],st[maxn][20],cnt[maxn];
int tim[maxn],change_col[maxn],ver[maxn],totq,totc,stac[maxn],dep[maxn];
int cur,seq_pos[maxn],seq[maxn],seq_cnt,fa[maxn],pre[maxn];
long long ans_a[maxn];
bool vis[maxn];
int pu,pv;
vector<int> G[maxn];
int blocksz,top,block_cnt;
long long ans = 0;
struct query{
	int l,r,tim,id;
	query(int a = 0,int b = 0):l(a),r(b),tim(0),id(0){};
	bool operator < (const query &oth) const{
		if(bel[l] != bel[oth.l]) return bel[l] < bel[oth.l];
		if(bel[r] != bel[oth.r]) return bel[r] < bel[oth.r];
		return tim < oth.tim;
	}
}que[maxn];

void reverse(int u){
	if(vis[u]) {
		ans -= (long long) wei[cnt[col[u]]] * val[col[u]];
		cnt[col[u]]--;
	}
	else{
		cnt[col[u]]++;
		ans += (long long) wei[cnt[col[u]]] * val[col[u]];
	}
	vis[u] ^= 1;
}

void dfs(int u,int par){
	fa[u] = par;
	seq[++seq_cnt] = u;
	seq_pos[u] = seq_cnt;
	dep[u] = dep[par] + 1;
	int st = top;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(v == par) continue;
		dfs(v,u);
		seq[++seq_cnt] = u;
		if(top - st > blocksz) {
			block_cnt++;
			while(top > st) bel[stac[top--]] = block_cnt;
		}
	}
	stac[++top] = u;
}	

inline int get_min(int u,int v){
	return dep[u] < dep[v] ? u : v;
}

void build_lca(){
	for(int i = 1; i <= seq_cnt; i++) st[i][0] = seq[i];
	for(int i = 1; (1 << i) <= seq_cnt; i++){
		for(int j = 1; j + (1 << i) - 1 <= seq_cnt; j++){
			st[j][i] = get_min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]); 
		}
	}
}

int get_lca(int u,int v){
	u = seq_pos[u],v = seq_pos[v];
	if(u > v) swap(u,v);
	int k = (double) log(v - u + 1) / (double) log(2);
	return get_min(st[u][k],st[v - (1 << k) + 1][k]);
}

void move(int u,int v){
	int w = get_lca(u,v);
	while(u != w) reverse(u),u = fa[u];
	while(v != w) reverse(v),v = fa[v];
}

void forward(int now){
	bool f = 0;
	if(vis[ver[now]]) f = 1,reverse(ver[now]);
	pre[now] = col[ver[now]];
	col[ver[now]] = change_col[now];
	if(f) reverse(ver[now]);
}
void backward(int now){
	bool f = 0;
	if(vis[ver[now]]) f = 1,reverse(ver[now]);
	col[ver[now]] = pre[now];
	if(f) reverse(ver[now]);
}
void time_travel(int now){
	while(cur < totc && tim[cur + 1] <= now) forward(++cur);
	while(cur && tim[cur] > now) backward(cur--);
}	
int main(){
	scanf("%d%d%d",&N,&M,&Q);
	blocksz = pow((double)N,(double) 2 / (double) 3);
	for(int i = 1; i <= M; i++) scanf("%d",&val[i]);
	for(int i = 1; i <= N; i++) scanf("%d",&wei[i]);
	for(int i = 1; i < N; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= N; i++) scanf("%d",&col[i]);
	for(int i = 1; i <= Q; i++){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt == 0){
			++totc;
			tim[totc] = i;
			change_col[totc] = y;
			ver[totc] = x;
		}
		else{
			++totq;
			que[totq] = query(x,y);
			que[totq].tim = i;
			que[totq].id = totq;
		}
	}
	dfs(1,0);
	while(top) bel[stac[top--]] = block_cnt;
	build_lca();
	sort(que + 1,que + 1 + totq);
	pu = pv = 1;
	for(int i = 1; i <= totq; i++){
		time_travel(que[i].tim);		
		move(pu,que[i].l);
		move(pv,que[i].r);
		pu = que[i].l, pv = que[i].r;
		reverse(get_lca(pu,pv));
		ans_a[que[i].id] = ans;
		reverse(get_lca(pu,pv));
	}
	for(int i = 1; i <= totq; i++) printf("%lld\n",ans_a[i]);
	return ~~(0^_^0); 
}




