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
char s[maxn],str[maxn];
int N,tot;
char ans[maxn];
struct Trie{
	int nxt[26],fail,sum;
} tree[maxn];
int nodes[maxn];
inline int idx(char c) {return c - 'a';}

void add(int len){
	int rt = 0;
	for(int i = 1; i <= len; i++){
		int c = idx(str[i]);
		if(!tree[rt].nxt[c]) tree[rt].nxt[c] = ++tot;
		rt = tree[rt].nxt[c];
	}
	tree[rt].sum = len;
}

queue<int> q;
void build_fail(){
	for(int i = 0; i < 26; i++){
		if(tree[0].nxt[i]) {
			q.push(tree[0].nxt[i]);
			tree[tree[0].nxt[i]].fail = 0;
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
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
	scanf("%s",s + 1);
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%s",str + 1);
		add(strlen(str + 1));
	}
	build_fail();
	int rt = 0;
	int top = 0;
	int lens = strlen(s + 1);
	for(int i = 1; i <= lens; i++){
		int c = idx(s[i]);
		ans[++top] = s[i];
	    rt = tree[rt].nxt[c];
		nodes[top] = rt;
		if(tree[rt].sum){
			top -= tree[rt].sum;
			rt = nodes[top];
		}
	}
	for(int i = 1; i <= top; i++) putchar(ans[i]); 
	return 0;	
}

