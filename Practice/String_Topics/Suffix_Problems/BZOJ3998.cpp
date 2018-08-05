#include <bits/stdc++.h>
using namespace std;
#define out(x) cout<<x<<endl;
#define FAST_IO ios::sync_with_stdio(false);
#define rep(i,st,ed,k) for(int i = st; i <= ed; i += k)
const int maxn = 1e6 + 10;
struct node{
	int len,link,nxt[30],siz;
} tree[maxn];
int wv[maxn],wss[maxn];
string str;
int t,k,tot[maxn];
int sz,last;
inline int idx(char c){ return c - 'a';}
void sam_init(){
	sz = last = 1;
}
void sam_extend(char ch){
	int cur = ++sz;
	tree[cur].len = tree[last].len + 1;
	tree[cur].siz = 1;
	int c = idx(ch);
	int p;
	for(p = last; p  && !tree[p].nxt[c]; p = tree[p].link) tree[p].nxt[c] = cur;
	if(!p) tree[cur].link = 1;
	else{
		int q = tree[p].nxt[c];
		if(tree[p].len + 1 == tree[q].len) tree[cur].link = q;
		else{
			int clone = ++sz;
			tree[clone].len = tree[p].len + 1;
			tree[clone].link = tree[q].link;
			memcpy(tree[clone].nxt,tree[q].nxt,sizeof(tree[q].nxt));
			for(; p  && tree[p].nxt[c] == q; p = tree[p].link) tree[p].nxt[c] = clone;
			tree[q].link = tree[cur].link = clone;
		}
	}
	last = cur;
}

void build(){
	for(int i = 1; i <= sz; i++) wv[tree[i].len]++;
	for(int i = 1; i <= str.size(); i++) wv[i] += wv[i - 1];
	for(int i = 1; i <= sz; i++) wss[wv[tree[i].len]--] = i;
	for(int i = sz; i; i--){
		int v = wss[i];
		if(t) tree[tree[v].link].siz += tree[v].siz;
		else tree[v].siz = 1;
	}
	tree[1].siz = 0;
	for(int i = sz; i >= 1; i--){
		int v = wss[i]; 
		tot[v] = tree[v].siz;
		for(int j = 0; j < 26; j++){
			if(tree[v].nxt[j]) tot[v] += tot[tree[v].nxt[j]];
		}
	}
}
int main(){
	FAST_IO
		cin>>str;
	cin>>t>>k;
	sam_init();
	for(int i = 0; i < str.size(); i++) sam_extend(str[i]);
	build();
	if(k > tot[1]) {
		cout<<-1<<endl;
		return 0;
	}
	int now = 1;
	while((k -= tree[now].siz) > 0){
		int p = 0;
		while(k > tot[tree[now].nxt[p]]) k -= tot[tree[now].nxt[p++]];
		now = tree[now].nxt[p];
		cout<<(char)('a' + p);
	}
	cout<<endl;
	return 0;
}

