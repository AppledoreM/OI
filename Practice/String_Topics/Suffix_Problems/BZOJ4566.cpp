#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
char str[maxn];
vector<int> G[maxn];
int tot = 0;
int cnt[maxn][2],fail[maxn],maxlen[maxn],ch[maxn][26];
inline int idx(char c){return c - 'a';}
int start,last;
long long ans;

int newnode(int len){
	int nd = ++tot;
	maxlen[nd] = len;
	return nd;
}

void extend(char cha,int type){
	int c = idx(cha);
	int u;
	if(ch[last][c]){
			u = ch[last][c];
			if(maxlen[u] == maxlen[last] + 1){
				cnt[u][type]++;
				last = u;
			}
			else{
				int n = newnode(maxlen[last] + 1);
				fail[n] = fail[u];
				fail[u] = n;
				memcpy(ch[n],ch[u],sizeof(ch[0]));
				for(int v = last; ch[v][c] == u; v = fail[v]) ch[v][c] = n;
				last = n;
				cnt[n][type]++;	
			}
			return;
	}
	u = newnode(maxlen[last] + 1);
	cnt[u][type]++;
	int v;
	for( v = last;  !ch[v][c]; v = fail[v]) ch[v][c] = u;
	if(ch[v][c] == u){
		fail[u] = 0;
	}
	else if(maxlen[ch[v][c]] == maxlen[v] + 1){
	   fail[u] = ch[v][c];
	}
	else {
		int n = newnode(maxlen[v] + 1), o = ch[v][c];
		memcpy(ch[n],ch[o],sizeof(ch[0]));
		fail[n] = fail[o];
		fail[o] = fail[u] = n;
		for(; ch[v][c] == o; v = fail[v])ch[v][c]  = n;
	}	
	last = u;
}

void process(int type){
	int n = strlen(str);
	for(int i = 0; i < n; i++) extend(str[i],type);
	last = 0;
}

void addedge(){
	for(int i = 1; i <= tot; i++){
		G[fail[i]].push_back(i);
	}
}
void dfs(int rt){
	for(int i = 0; i < G[rt].size(); i++){
		dfs(G[rt][i]);
		cnt[rt][0] += cnt[G[rt][i]][0];
		cnt[rt][1] += cnt[G[rt][i]][1];
	}
	ans += (long long) cnt[rt][0] * cnt[rt][1] * (maxlen[rt] - maxlen[fail[rt]]);
}

int main(){
	scanf("%s",str);
	int n = strlen(str);
	process(0);
	scanf("%s",str);
	n = strlen(str);
	process(1);
	addedge();
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
