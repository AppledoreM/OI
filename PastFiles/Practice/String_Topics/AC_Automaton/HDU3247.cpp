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
const int maxn = 6e4 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
int N,M,tot;
vector<string> v;
struct Trie{
	int nxt[2],fail,sum;
} tree[maxn];

inline int idx(char c){return c - '0';}

void add(string s,int mark){
	int rt = 0;
	for(int i = 0; i < s.size(); i++){
		int c = idx(s[i]);
		if(!tree[rt].nxt[c]) tree[rt].nxt[c] = ++tot;
		rt = tree[rt].nxt[c];
	}
	tree[rt].sum = mark;
}

queue<int> q;
void build_fail(){
	for(int i = 0; i < 2; i++){
		if(tree[0].nxt[i]) {
			q.push(tree[0].nxt[i]);
			tree[0].fail = 0;
		}
	}
	int rt = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 2; i++){
			if(tree[u].nxt[i]){
				tree[tree[u].nxt[i]].fail = tree[tree[u].fail].nxt[i];
				q.push(tree[u].nxt[i]);
			}
			else tree[u].nxt[i] = tree[tree[u].fail].nxt[i];
		}
	}
}

int cnt,dis[maxn],dp[1505][11],len[15][15],pos[15];;
void bfs(int k){
	q.push(pos[k]);
	memset(dis,-1,sizeof(dis));
	dis[pos[k]] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 2; i++){
			int v = tree[u].nxt[i];
			if(dis[v] < 0 && tree[v].sum >= 0){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 0; i <= cnt; i++) len[k][i] = dis[pos[i]];
}

void solve(){
	pos[0] = 0;
	for(int i = 0; i <= tot; i++){
		if(tree[i].sum > 0) pos[++cnt] = i;
	}
	for(int i = 0; i <= cnt; i++) bfs(i);
	memset(dp,127,sizeof(dp));
	dp[0][0] = 0;
	for(int i = 0; i < (1 << N); i++){
		for(int j = 0; j <= cnt; j++){
			if(dp[i][j] < 1e9){
				for(int k = 0; k <= cnt; k++){
					if(len[j][k] < 0 || j == k) continue;
					int st = i | tree[pos[k]].sum;
					dp[st][k] = min(dp[st][k],dp[i][j] + len[j][k]);
				}
			}
		}
	}
	int ans = INT_MAX;
	for(int i = 1; i <= cnt; i++) ans = min(ans,dp[(1 << N) - 1][i]);
	cout<<ans<<endl;	
}

inline void init(){
	for(int i = 1; i <= N; i++) {
		tree[i].fail = tree[i].sum = 0;
		tree[i].nxt[0] = tree[i].nxt[1] = 0;
	}
	cnt = 0;
	tot = 0;
}

int main(){
	FAST_IO
	while(cin>>N>>M){
		if(!N && !M) break;
		for(int i = 1; i <= N; i++){
			string tmp;
			cin>>tmp;
			add(tmp, 1 << (i - 1));
		}
		for(int i = 1; i <= M; i++){
			string tmp;
			cin>>tmp;
			add(tmp,-1);
		}
		build_fail();
		solve();
		init();
	}
	return 0;
}

