#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 250005;
int ans[maxn];
class SuffixAutomaton{
	public:
		struct node{
			int mx,cnt;
			node *fail,*ch[26];
			~node(){delete fail;}
			node(int a = 0):mx(a),fail(NULL){};
		}*start,*last,_pool[maxn<<2],*_cur;
		vector<node*> topo;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){init();}
		static inline int idx(char c){return c - 'a';}
		void extend(char cha){
			int c = idx(cha);
			node *u = new (_cur++) node(last->mx + 1);
			u->cnt = 1;
			node *v = last;
			for(;v && !v->ch[c]; v = v->fail) v->ch[c] = u;
			if(!v){
				u->fail = start;
			}
			else if(v->mx + 1 == v->ch[c]->mx){
				u->fail = v->ch[c];
			}
			else{
				node *n = new (_cur++) node(v->mx + 1), *o = v->ch[c];
				copy(o->ch,o->ch+26,n->ch);
				n->fail = o->fail;
				o->fail = u->fail = n;
				for(; v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
			}
			last = u;
		}	
		void get_ans(char *s){
			for(int i = topo.size() - 1; i >= 0; i--){
				node *cur = topo[i];
				if(cur->fail) cur->fail->cnt += cur->cnt;
			}
			int n = strlen(s);
			for(node *cur = _pool; cur != _cur; cur++){
				ans[cur->mx] = max(ans[cur->mx],cur->cnt);
			}
			for(int i = n - 1; i >= 1; i--) ans[i] = max(ans[i],ans[i + 1]);
		}
		void toposort(){
			static int buc[maxn<<2];
			int mx = 0;
			for(node *cur = _pool; cur != _cur; cur++){
			   buc[cur->mx]++;
			   mx = max(mx,cur->mx);
			}
	 		for(int i = 1; i <= mx; i++) buc[i] += buc[i - 1];
			topo.resize(_cur - _pool);
			for(node *cur = _pool; cur != _cur; cur++){
				topo[--buc[cur->mx]] = cur;
			}	
		}
		void extend(char *s){
			int n = strlen(s);
			for(int i = 0; i < n; i++) extend(s[i]);
		}
}*sa;
char str[maxn];
int main(){
	scanf("%s",str);
	sa = new SuffixAutomaton();
	sa->extend(str);
	sa->toposort();
	sa->get_ans(str);
	int n = strlen(str);
	for(int i = 1; i <= n; i++) printf("%d\n",ans[i]); 	   
	return 0;
}
