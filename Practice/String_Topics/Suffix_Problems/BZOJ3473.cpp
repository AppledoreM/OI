#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int N,K;
const int maxn = 4e5 + 10;
const int CH_SIZE = 26;
string s[100005];
class SuffixAutomaton{
	public:
		vector<int> G[maxn];
		struct node{
			node *fail,*ch[CH_SIZE];	
			vector<node*> nxt;
			int mx,cnt;
			set<int> s;
			node(int a = 0,int b = 0):mx(a),cnt(b),fail(NULL){};
			~node(){ delete fail; }
		}*start,*last,_pool[maxn],*_cur;
		void init(){ 
			_cur = _pool;
			start = last = new (_cur++) node();
		}
		SuffixAutomaton(){
			init();
		}
		static inline int idx(char c){ return c - 'a';}
		void recover() { last = start;}
		void extend(char cha,int id){
			int c = idx(cha);
			node *u = new (_cur++) node(last->mx + 1),*v = last;
			u->s.insert(id);
			for(;v && !v->ch[c]; v = v->fail) v->ch[c] = u;
			if(!v){
				u->fail = start;
			}
			else if(v->ch[c]->mx == v->mx + 1){
				u->fail = v->ch[c];
			}
			else{
				node *n = new (_cur++) node(v->mx + 1), *o = v->ch[c];
				copy(o->ch,o->ch + CH_SIZE,n->ch);
				n->fail = o->fail;
				o->fail = u->fail = n;
				for(;v && v->ch[c] == o; v = v->fail)v->ch[c] = n;
			}
			last = u;
		}
		void extend(string s,int id){
			int n = s.size();
			for(int i = 0; i < n; i++) extend(s[i],id);
		}
		void addedge(){
			for(node *cur = _pool; cur != _cur ; cur++){
				if(cur->fail) cur->fail->nxt.push_back(cur);
			}				
		}
		void dfs(node *cur){
			for(int i = 0; i < cur->nxt.size(); i++){
				dfs(cur->nxt[i]);
				for(set<int>::iterator it = cur->nxt[i]->s.begin(); it != cur->nxt[i]->s.end(); it++){
					cur->s.insert(*it);
				}
			}
			cur->cnt = cur->s.size();		
		}
		long long query(string s){
			node *rt = start;
			long long ans = 0;
			for(int i = 0; i < s.size(); i++){
				rt = rt->ch[idx(s[i])];
				while(rt->fail && rt->cnt < K) rt = rt->fail;
				ans += rt->mx;
			}
			return ans;
		}
}*sa;



int main(){
	scanf("%d%d",&N,&K);
	sa = new SuffixAutomaton();
	for(int i = 1; i <= N; i++){
		cin>>s[i];
		sa->extend(s[i],i);
		sa->recover();
	}
	sa->addedge();
	sa->dfs(sa->start);
	for(int i = 1; i <= N; i++) printf("%lld ",sa->query(s[i]));
	return 0;
}
