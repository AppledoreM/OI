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
const int maxn = 4e6 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
int N,M,tot,mod = 109 + 7;
char str[maxn];
int id[maxn];
struct Trie{
	int nxt[26],fail,sum;
} tree[maxn];

inline int idx(char c){ return c - 'a';}

void add(int d){
	int n = strlen(str + 1);
	int rt = 0;
	for(int i = 1; i <= n; i++){
		int c = idx(str[i]);
		if(!tree[rt].nxt[c]) tree[rt].nxt[c] = ++tot;
		rt = tree[rt].nxt[c];
		tree[rt].sum++;
	}
	id[d] = rt;
}

queue<int> q;
deque<int> q1;
void build_fail(){
	for(int i = 0; i < 26; i++){
		if(tree[0].nxt[i]) {
			q.push(tree[0].nxt[i]);
			q1.push_back(tree[0].nxt[i]);
			tree[tree[0].nxt[i]].fail = 0;
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 26; i++){
			int v = tree[u].nxt[i];
			if(v) {
				tree[v].fail = tree[tree[u].fail].nxt[i];
				q.push(v);
				q1.push_back(v);
			}
			else tree[u].nxt[i] = tree[tree[u].fail].nxt[i];
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%s",str + 1);
		add(i + 1);
	}
	build_fail();
	while(!q1.empty()){
		int u = q1.back();
		tree[tree[u].fail].sum += tree[u].sum;
		q1.pop_back();
	}
	for(int i = 1; i <= N; i++) printf("%d\n",tree[id[i]].sum);
	return 0;
}

