#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int N,M,tmp[maxn],ans[maxn];

class SuffixAutomaton{
	public:
		struct node {
			node *fail;
			map<int,node*> ch;
			set<int> s;
			vector<node*> next;
			int mx;
			node(int a = 0):mx(a),fail(NULL){};
		}*start,*last,_pool[maxn<<1],*_cur;	
		void init(){
			_cur = _pool;
			start = last = new (_cur++) node;
		}
		SuffixAutomaton(){ init(); }
		void extend(int num,int id){
			node *u = new (_cur++) node(last->mx + 1); 
			u->s.insert(id);
			node *v = last;
			for(; v && !v->ch[num]; v = v->fail) v->ch[num] = u;	
			if(!v){
				u->fail = start;
			}
			else if(v->ch[num]->mx == v->mx + 1){
				u->fail = v->ch[num];
			}
			else{
				node *n = new (_cur++) node(v->mx + 1);
				node *o = v->ch[num];
				n->ch = o->ch;
				n->fail = o->fail;
				o->fail = u->fail = n;
				for(; v && v->ch[num] == o; v = v->fail) v->ch[num] = n;
			}
			for(node *v = u; v; v = v->fail) v->s.insert(id);
			last = u;	
		}
		void recover(){
			last = start;
		}
		void extend(int *s,int len,int id){
			for(int i = 1; i <= len; i++) extend(s[i],id);
			recover();
		}
		void addedge(){
			for(node *cur = _pool; cur != _cur; cur++){
				if(cur->fail) cur->fail->next.push_back(cur);
			}
		}
		void pass_fa(node *cur){
			for(int i = 0; i < cur->next.size(); i++){
				node *v = cur->next[i];
				pass_fa(v);
				for(set<int>::iterator it = v->s.begin(); it != v->s.end(); it++){
					cur->s.insert(*it);
				}
			}
		}

		int match(int *s,int len){
			node *cur = start;
			for(int i = 1; i <= len; i++){
				cur = cur->ch[s[i]];	
				if(!cur) return 0; 
			}
			for(auto it = cur->s.begin(); it != cur->s.end(); it++) ans[*it]++;
			return cur->s.size();	
		}
};



int main(){
	scanf("%d%d",&N,&M);
	SuffixAutomaton *sa = new SuffixAutomaton();
	for(int i = 1; i <= N; i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j = 1; j <= cnt; j++) scanf("%d",&tmp[j]);	
		sa->extend(tmp,cnt,i);
		scanf("%d",&cnt);
		for(int j = 1; j <= cnt; j++) scanf("%d",&tmp[j]);
		sa->extend(tmp,cnt,i);
	}
	sa->addedge();
	sa->pass_fa(sa->start);
	for(int i = 1; i <= M; i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j = 1; j <= cnt; j++) scanf("%d",&tmp[j]);
		printf("%d\n",sa->match(tmp,cnt));		
	}
	for(int i = 1; i <= N; i++) printf("%d ",ans[i]);
	return 0;
}
