#include <iostream>
#include <cstring>
#include <string>
#include <algorithm> 
using namespace std;
const int maxn = 1e6 + 5;
char str[maxn];
class SuffixAutomaton{
	public:
		struct node{
			int mx;
			node *fail,*ch[26];
			node(int a = 0):mx(a),fail(NULL){}
			~node(){ delete fail;}
		} *start,*last,_pool[maxn<<2],*_cur;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){ init();}
		static inline int idx(char c){ return c - 'a';}
		void extend(char cha){
			int c = idx(cha);
			node *u = new (_cur++) node(last->mx + 1), *v = last;
			for(; v && !v->ch[c]; v = v->fail) v->ch[c] = u;	
			if(!v){
				u->fail = start;
			}
			else if(v->ch[c]->mx == v->mx + 1){
				u->fail = v->ch[c];
			}
			else {
				node *n = new (_cur++) node(v->mx + 1), *o = v->ch[c];
				memcpy(n->ch,o->ch,sizeof(o->ch));
				n->fail = o->fail;
				o->fail = u->fail = n;
				for(; v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
			}
			last = u;
		}

		void extend(char *s){
			int n = strlen(s);
			for(int i = 0; i < n; i++) extend(s[i]);
		}
		long long get_ans(){
			long long re = 0;	
			for(node *cur = _pool; cur != _cur; cur++){
				if(cur->fail) {
					re += cur->mx - cur->fail->mx;
				}
			}
			return re;
		}
} *sa;

int main(){
	scanf("%s",str);
	sa = new SuffixAutomaton();
	sa->extend(str);
	printf("%lld\n",sa->get_ans());
	return 0;
}
