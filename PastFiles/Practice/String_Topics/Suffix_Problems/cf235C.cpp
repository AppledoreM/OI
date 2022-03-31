#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
char str[maxn<<1];
int N;

class SuffixAutomaton{
	public:
		struct node{
			node *fail,*ch[26];
			vector<node*> next;
			int mx,cnt,vis;
			node(int a = 0,int b = 0):vis(0),mx(a),cnt(b),fail(NULL){};
			~node(){ delete fail;}
		}*start,*last,_pool[maxn<<1],*_cur;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){ init(); }
		static inline int idx(char c){return c - 'a';}
		void extend(char cha){
			int c = idx(cha);
			node *u = new (_cur++) node(last->mx + 1,1), *v = last;
			for(; v && !v->ch[c]; v = v->fail) v->ch[c] = u;
			if(!v){
				u->fail = start;
			}
			else if(v->ch[c]->mx == v->mx + 1){
				u->fail = v->ch[c];
			}
			else{
				node *n = new (_cur++) node(v->mx + 1), *o = v->ch[c];
				memcpy(n->ch,o->ch,sizeof(o->ch));
				n->fail = o->fail;
				o->fail = u->fail = n;
				for(; v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
			}
			last = u;
		}
		void extend(char *s){
			int n = strlen(s + 1);
			for(int i = 1; i <= n; i++) extend(s[i]);
		}
		void addedge(){
			for(node *cur = _pool; cur != _cur; cur++){
				if(cur->fail){
					cur->fail->next.emplace_back(cur);
				}
			}
		}
		void pass_fa(node *cur){
			for(auto v : cur->next){
				pass_fa(v);
				cur->cnt += v->cnt;
			}
		}
		int get_ans(char *s,int n, int len, int id){
			node *cur = start;
			int val = 0,re = 0;
			for(int i = 1; i <= n; i++){
				int c = idx(s[i]);
				if(cur->ch[c]){
					val++;
					cur = cur->ch[c];
				}
				else {
					while(cur && !cur->ch[c]) cur = cur->fail;
					if(!cur){
						val = 0;
						cur = start;
					}
					else{
						val = cur->mx + 1;
						cur = cur->ch[c];
					}
				}
				if(val >= len){
					while(cur->fail && cur->fail->mx >= len) cur = cur->fail;
					if(cur->vis != id){
						cur->vis = id;
						re += cur->cnt;
					}
				}	
			}
			return re;
		}
}*sa;

int main(){
	scanf("%s",str + 1);
	sa = new SuffixAutomaton();
	sa->extend(str);
	sa->addedge();
	sa->pass_fa(sa->start);
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		scanf("%s",str + 1);
		int tot = strlen(str + 1);
		int n = 0;
		for(n = tot;tot < 2 * n - 1;) {
			tot++;
			str[tot] = str[tot - n];
		}
		printf("%d\n",sa->get_ans(str,tot,n,i));
	}
	return 0;
}

