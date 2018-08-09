#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
char str[maxn];
class SuffixAutomaton{
	public:
		struct node{
			int mx,cnt;
			node *fail,*ch[26];
			node(int a = 0,int b = 0):cnt(b),mx(a),fail(NULL){}
			~node(){ delete fail;}
		} *start,*last,_pool[maxn<<1],*_cur;
		vector<node*> topo;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){ init();}
		static inline int idx(char c){ return c - 'a';}
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
		void toposort(){
			static int buc[maxn<<1];
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
			fill(buc,buc + 1+ mx,0);
		}
		void get_ans(){
			long long ans = 0;
			for(int i = topo.size() - 1; i >= 0; i--){
				node *v = topo[i];
				if(v->fail) v->fail->cnt += v->cnt;
				if(v->cnt != 1) ans = max(ans,(long long) v->cnt * v->mx);
			}
			printf("%lld\n",ans);
		}
} *sa;
int main(){
	sa = new SuffixAutomaton();
	scanf("%s",str);
	sa->extend(str);
	sa->toposort();
	sa->get_ans();
	return 0;
}
