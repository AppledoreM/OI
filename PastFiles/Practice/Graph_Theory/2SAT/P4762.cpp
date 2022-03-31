#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;
const int maxn = 2e6 + 10;
int N,M,dfn[maxn],dfs_clock,low[maxn],scc_cnt,bel[maxn];
vector<int> G[maxn];
stack<int> S;
bool instac[maxn];


void addedge(int u,int a,int v,int b){
	int nota = a ^ 1;
	int notb = b ^ 1;
	G[u + nota * N].emplace_back(v + b * N);
	G[v + notb * N].emplace_back(u + a * N);	
}

void tarjan(int u){
	dfn[u] = low[u] = ++dfs_clock;
	instac[u] = 1;
	S.push(u);
	for(int v : G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instac[v]) low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u]){
		int v = 0;
		scc_cnt++;
		do{
			v = S.top();
			S.pop();
			instac[v] = 0;
			bel[v] = scc_cnt;
		}
		while(!S.empty() && v != u);	
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= M; i++){
		int u,v,a,b;
		scanf("%d%d%d%d",&u,&a,&v,&b);
		addedge(u,a,v,b);
	}
	for(int i = 1; i <= 2 * N; i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= N; i++) {
		if(bel[i] == bel[i + N]) {
			printf("IMPOSSIBLE\n");
			exit(0);
		}
	}
	printf("POSSIBLE\n");
	for(int i = 1; i <= N; i++){
		printf("%d ",bel[i] > bel[i + N]);
	}
	return 0;
}
