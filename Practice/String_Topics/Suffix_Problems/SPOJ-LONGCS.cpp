#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector> 
#include <limits.h>
using namespace std;
const int maxn = 1e6 + 10;
class SuffixAutomaton{
	public:
		struct node{
			node *fail,*ch[26];
			int mx,ans,mn;
			node(int a  = 0):mx(a),fail(NULL),ans(0),mn(INT_MAX){};
			~node(){delete fail;}	
		} *start,*last,_pool[maxn],*_cur;
		vector<node*> topo;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}		
		SuffixAutomaton(){ init();}
		static inline int idx(char c){return c - 'a';}
		void extend(char cha){
			int c = idx(cha);
			node *u = new (_cur++) node(last->mx + 1);
			node *v = last;
			for(; v && !v->ch[c]; v = v->fail) v->ch[c] = u;
			if(!v){
				u->fail = start;
			}
			else if(v->ch[c]->mx == v->mx + 1){
				u->fail = v->ch[c];
			}
			else {
				node *n = new (_cur++) node(v->mx + 1), *o = v->ch[c];
				copy(o->ch,o->ch + 26,n->ch);
				n->fail = o->fail;
				o->fail = u->fail = n;
				for(;v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
			}
			last = u;
		}
		void update(char *s){
			int n = strlen(s);
			node* rt = start;
			int ans = 0;
			for(int i = 0; i < n; i++){
				int c = idx(s[i]);
				ans++;
				while(rt && !rt->ch[c]) rt = rt->fail;
				if(!rt){
					rt = start;
				   	ans = 0;
				}
				else{
					ans = min(ans,rt->mx + 1);
					rt = rt->ch[c];
				}
				rt->ans = max(rt->ans,ans);
			}				
		}

		void update_fa(){
			for(int i = topo.size() - 1; i >= 0; i--){
				node *cur = topo[i];
				if(cur->fail) cur->fail->ans = max(cur->fail->ans,min(cur->ans,cur->fail->mx));
				cur->mn = min(cur->mn,cur->ans);
				cur->ans = 0;
			}
		}

		void recover(){last = start;}
		void extend(char *s){
			int n = strlen(s);
			for(int i = 0; i < n; i++) extend(s[i]);
		}
		void toposort(){
			topo.clear();
			static int buc[maxn];
			int mx = 0;
			for(node *cur = _pool; cur != _cur; cur++){
				buc[cur->mx]++;
				mx = max(mx,cur->mx);
			}
			topo.resize(_cur - _pool);
			for(int i = 1; i <= mx; i++){
				buc[i] += buc[i - 1];
			}
			for(node *cur = _pool; cur != _cur; cur++){
				topo[--buc[cur->mx]] = cur;
			}
			fill(buc,buc + 1 + mx,0);
		}
		int get_ans(){
			int ans = 0;
			for(node *cur = _pool; cur != _cur; cur++){
				ans = max(ans,cur->mn);
			}
			return ans;
		}
} *sa;

char str[maxn>>2];
int main(){
	sa = new SuffixAutomaton();
	scanf("%s",str); sa->extend(str);
	sa->toposort();
	while(~scanf("%s",str)){
		sa->update(str);
		sa->update_fa();
	}
	printf("%d\n",sa->get_ans());
	return 0;
}
