#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int ans[maxn];
class SuffixAutomaton{
	public:
		struct node{
			int mx,cnt;
			node *fail,*ch[26];
			node(int a = 0,int b = 0):mx(a),cnt(b),fail(NULL){};
			~node(){ delete fail;}
		}*start,*last,_pool[maxn<<1],*_cur;
		vector<node*> topo;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){ init(); }
		static inline int idx(char c){ return c - 'a';}
		void extend(char cha){
			int c = idx(cha);
			node *u = new (_cur++) node(last->mx + 1,1),*v = last;
			for(; v && !v->ch[c]; v = v->fail) v->ch[c] = u;
			if(!v){
				u->fail = start;
			}
			else if(v->ch[c]->mx == v->mx + 1){
				u->fail = v->ch[c];
			}
			else {
				node *n = new (_cur++) node(v->mx + 1,0), *o = v->ch[c];
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
				mx = max(cur->mx,mx);
			}
			topo.resize(_cur - _pool);
			for(int i = 1; i <= mx; i++) buc[i] += buc[i - 1];
			for(node *cur = _pool; cur != _cur; cur++){
				topo[--buc[cur->mx]] = cur;
			}
		}
		void get_ans(int n){
			for(int i = topo.size() - 1; i >= 0; i--){
				node *v = topo[i];
				if(v->fail) v->fail->cnt += v->cnt;
				ans[v->mx] = max(ans[v->mx],v->cnt);
			}
			for(int i = n - 1; i >= 1; i--){
				ans[i] = max(ans[i],ans[i + 1]);
			}
		}

}*sa;
char str[maxn];

int main(){
	scanf("%s",str);
	sa = new SuffixAutomaton();
	sa->extend(str);
	sa->toposort();
	int n = strlen(str);
	sa->get_ans(n);
	for(int i = 1; i <= n; i++) printf("%d\n",ans[i]);
	return 0;
}
