#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 2e5 + 10;
char str[maxn];
int ans[maxn];
long long has[maxn], po[maxn];
bool is_ans[maxn];
const int mod = 1e9 + 7;
const int base = 233;
class SuffixAutomaton{
	public:
		struct node{
			node *fail,*ch[26];
			vector<node*> next;
			int mx,cnt;
			node(int a = 0,int b = 0):mx(a),cnt(b),fail(NULL){};
			~node(){ delete fail; }
		}*start,*last,_pool[maxn<<1],*_cur;
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){ init(); }
		static inline int idx(char c){ return c - 'A';}
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
		void get_ans(int n){
			node *cur = start;
			for(int i = 1; i <= n; i++){
				int c = idx(str[i]);
				cur = cur->ch[c];
				ans[i] = cur->cnt;
			}
		}
}*sa;

void get_hash(int n){
	for(int i = 1; i <= n; i++){
		has[i] = (has[i - 1] * base % mod + SuffixAutomaton::idx(str[i])) % mod;
	}
}

bool is_equal(int l1,int r1,int l2,int r2){
	long long has1 = (has[r1] - has[l1 - 1] * po[r1 - l1 + 1] % mod + mod) % mod; 
	long long has2 = (has[r2] - has[l2 - 1] * po[r2 - l2 + 1] % mod + mod) % mod;
	return has1 == has2;
}
void preprocess(int n){
	po[0] = 1;
	for(int i = 1; i <= n; i++){
		po[i] = po[i - 1] * base % mod;
	}
}
int main(){
	scanf("%s",str + 1);
	int n = strlen(str + 1),len = 0;
	sa = new SuffixAutomaton();
	sa->extend(str);
	sa->addedge();
	sa->pass_fa(sa->start);
	sa->get_ans(n);
	get_hash(n);
	preprocess(n);
	for(int i = 1,j = n; i <= n; i++,j--){
		if(is_equal(1,i,j,n)) {
			is_ans[i] = 1;	
			len++;
		}
	}
	printf("%d\n",len);
	for(int i = 1; i <= n; i++) if(is_ans[i]) printf("%d %d\n",i,ans[i]);
	return 0;
}
