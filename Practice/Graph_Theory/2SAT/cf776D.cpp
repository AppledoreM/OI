#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> G[maxn];
int N,M;
int door[maxn][2],dfn[maxn],dfs_clock,low[maxn],bel[maxn],scc_cnt;
bool st[maxn],instac[maxn];
stack<int> S;

void tarjan(int u){
	dfn[u] = low[u] = ++dfs_clock;
	instac[u] = 1;
	S.push(u);
	for(int v : G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instac[u]) low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u]){
		int v = 0;
		scc_cnt++;
		do{
			v = S.top(); S.pop();
			bel[v] = scc_cnt;
			instac[v] = 0;
		}
		while(!S.empty() && v != u);
	}

}

void addedge(int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i = 1; i <= N; i++) cin>>st[i];
	for(int i = 1; i <= M; i++){
		int num;
		cin>>num;
		for(int j = 1; j <= num; j++){
			int swi;
			cin>>swi;
			if(!door[swi][0]) door[swi][0] = i;
			else door[swi][1] = i;
		}
	}	
	for(int i = 1; i <= N; i++){
		if(st[i] == 0){
			addedge(door[i][0] + M,door[i][1]);
			addedge(door[i][1] + M,door[i][0]);
		}
		else{
			addedge(door[i][0] + M,door[i][1] + M);
			addedge(door[i][1],door[i][0]);
		}
	}
	for(int i = 1; i <= 2 * M; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= M; i++){
		if(bel[i] == bel[i + M]) {
			cout<<"NO"<<endl;
			exit(0);
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
