#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
int N,B;
int top,cap[maxn],bel[maxn],stac[maxn],cnt;
vector<int> G[maxn];
void dfs(int u,int par){
	int st = top;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(v == par) continue;
		dfs(v,u);
		if(top - st >= B){
			cap[++cnt] = u;
			while(top > st) bel[stac[top--]] = cnt;
		}
	}
	stac[++top] = u;
}
int main(){
	scanf("%d%d",&N,&B);
	for(int i = 1; i < N; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	dfs(1,0);
	while(top) bel[stac[top--]] = cnt;
	cout<<cnt<<endl;
	for(int i = 1; i <= N; i++) cout<<bel[i]<<" ";
	cout<<endl;
	for(int i = 1; i <= cnt; i++) cout<<cap[i]<<" ";
	return 0;
}
