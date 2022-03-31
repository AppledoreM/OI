#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 4e5 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
char str[maxn];
struct Trie{
	int nxt[26],fail;
} tree[maxn];
struct query{
	int first,second,id,ans;
} que[maxn];
int tot,N,in[maxn],out[maxn],BIT[maxn];
bool cmp(query a,query b){ return a.second < b.second; }
bool cmp1(query a,query b){ return a.id < b.id; }
vector<int> G[maxn];
int dfs_clock,fa[maxn],end_id[maxn];

inline int idx(char c){return c - 'a';}

void dfs(int u){
	in[u] = ++dfs_clock;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		dfs(v);
	}
	out[u] = ++dfs_clock;
}
void change(int x,int delta){
	while(x <= dfs_clock){
		BIT[x] += delta;
		x += x & -x;
	}
}

int ask(int x){
	int re = 0;
	while(x){
		re += BIT[x];
		x -= x & -x;
	}
	return re;
}


void add_string(){
	int n = strlen(str + 1);
	int top = 0;
	int cnt = 0;
	int rt = 0;
	for(int i = 1; i <= n; i++){
		if(str[i] == 'P'){
			end_id[++cnt] = rt;
		}
		else if(str[i] == 'B') rt = fa[rt]; 
		else {
			int c = idx(str[i]);
			if(!tree[rt].nxt[c]) tree[rt].nxt[c] = ++tot;
			fa[tree[rt].nxt[c]] = rt;
			rt = tree[rt].nxt[c];
		}
	}
}	
queue<int> q;
void build_ac(){
	for(int i = 0; i < 26; i++){
		if(tree[0].nxt[i]){
			q.push(tree[0].nxt[i]);
			tree[tree[0].nxt[i]].fail = 0;
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		G[tree[u].fail].push_back(u);
		for(int i = 0; i < 26; i++){
			if(tree[u].nxt[i]){
				tree[tree[u].nxt[i]].fail = tree[tree[u].fail].nxt[i];
				q.push(tree[u].nxt[i]);
			}
			else tree[u].nxt[i] = tree[tree[u].fail].nxt[i];
		}
	}
}

int main(){
	scanf("%s",str + 1);
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		int x,y;
		scanf("%d%d",&que[i].first,&que[i].second);	
		que[i].id = i;
	}
	sort(que + 1,que + 1 + N,cmp); 
	add_string();
	build_ac();
	dfs(0);
	int len = strlen(str + 1);
	int top,cur,num,rt;
	top = cur = num = rt;
	for(int i = 1; i <= len; i++){
		if(str[i] == 'P'){
			num++;
			while(que[cur].second < num && cur <= N) cur++;
			while(que[cur].second == num && cur <= N){
				int x = que[cur].first;
				que[cur].ans = ask(out[end_id[x]]) - ask(in[end_id[x]] - 1);
				cur++;
			}
		}
		else if(str[i] == 'B'){
			change(in[rt],-1);
			rt = fa[rt];
		}
		else {
			int c = idx(str[i]);
			rt = tree[rt].nxt[c];
			change(in[rt],1);
		}
	}
	sort(que + 1,que + 1 + N,cmp1);
	for(int i = 1; i <= N; i++) printf("%d\n",que[i].ans); 
	return 0;
}

