#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int N,M;
const int maxn = 2e5 + 10;
vector<int> G[maxn];
int stac[maxn],top;
int dep[maxn],fa[maxn],seq[maxn],seq_pos[maxn],seq_cnt,st[maxn][20];
int ans[maxn];

void dfs(int u,int par){
	fa[u] = par;
	seq[++seq_cnt] = u;
	seq_pos[u] = seq_cnt;
	for(int v : G[u]){
		if(v == par) continue;
		dep[v] = dep[u] + 1;
		ans[v] = dep[v];
		dfs(v,u);
		seq[++seq_cnt] = u;
	}
}

int get_min(int u,int v){
	return dep[u] < dep[v] ? u : v;
}

void build_lca(){
	for(int i = 1; i <= seq_cnt; i++) st[i][0] = seq[i];
	for(int i = 1; (1 << i) <= seq_cnt; i++){
		for(int j = 1; j + (1 << i) - 1 <= seq_cnt; j++){
			st[j][i] = get_min(st[j][i - 1],st[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int get_lca(int u,int v){
	u = seq_pos[u], v = seq_pos[v];
	if(u > v) swap(u,v);
	int k = log2(v - u + 1);
	return get_min(st[u][k], st[v - (1 << k) + 1][k]);	
}

void bfs(){
	queue<int> q;
	for(int i = 1; i <= top; i++){
		ans[stac[i]] = 0;
		q.push(stac[i]);
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : G[u]){
			if(v == fa[v]) continue;
			if(ans[v] > ans[u] + 1){
				ans[v] = ans[u] + 1;
				q.push(v);
			}	
		}	
	}
}

int get_ans(int u,int v){
	int lc = get_lca(u,v);
	return dep[u] + dep[v] - dep[lc] * 2;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1; i < N; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1,0);
	build_lca();
	for(int i = 1; i <= M; i++){
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt == 1){
			stac[++top] = x;
			if(top >= 100){
				bfs();
				top = 0;
			}
		}
		else {
			int re = ans[x];;
			for(int i = 1; i <= top; i++){
				re = min(re,get_ans(stac[i],x));
			}		
			printf("%d\n",re);
		}
	}
	return 0;
}
