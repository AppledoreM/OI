#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
int N,Q;
const int maxn = 4e5 + 10;
char str[maxn];
struct SuffixAutomaton{
	struct node{
		int mx,cnt,col;
		node *fail,*ch[26];
		node(int a = 0,int b = 0,int c = 0) :mx(a),cnt(b),col(c){}
		~node(){
			delete fail;
		}
	}*start,*last,_pool[maxn],*_cur;
	void init(){
		_cur = _pool;
		start = last = new (_cur++) node();
	}
	SuffixAutomaton(){ init();}
	inline int idx(char c){return c - 'a';}
	void recover(){ last = start;	} 
	void extend(char cha,int type){
		int c = idx(cha);
		node *u;	
		u = new (_cur++) node(last->mx + 1);
		node *v = last;
		for(;v && !v->ch[c]; v = v->fail) v->ch[c] = u;
		if(!v){
			u->fail = start;
		}
		else if(v->ch[c]->mx == v->mx + 1){
			u->fail = v->ch[c];
		}
		else{
			node *n = new (_cur++) node(v->mx + 1,v->ch[c]->cnt,v->ch[c]->col),*o = v->ch[c];
			copy(o->ch,o->ch + 26,n->ch);
			n->fail = o->fail;
			o->fail = u->fail = n;
			for(; v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
		}
		last = u;
		for(;u;u = u->fail){
			if(u->col != type){
				u->cnt++;
				u->col = type;
			}
		}
	}
	int query(){
		int ans = 0;
		node *cur = start;
		int n = strlen(str);
		for(int i = 0; i < n; i++){
			int c = idx(str[i]);
			if(cur->ch[c] == NULL){
				return 0;
			}
			cur = cur->ch[c];
		}
		return cur->cnt;
	}	
} *sa;

void process(int type){
	int n = strlen(str);
	for(int i = 0; i < n; i++) sa->extend(str[i],type);
	sa->recover();	
}
void process_query(){
	int n = strlen(str);
	printf("%d\n",sa->query());
}
int main(){
	scanf("%d%d",&N,&Q);
	sa = new SuffixAutomaton();
	for(int i = 1; i <= N; i++) {
		scanf("%s",str);
		process(i);
	}
	for(int i = 1; i <= Q; i++){
		scanf("%s",str);
		printf("%d\n",sa->query());
	}	
	return 0;
}
