#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,limit;


class Splay{
	public:
		struct node{
			node *fa,*ch[2];
			int val,sz,cnt,tag;
			bool relation() { return this->fa->ch[1] == this;}	
			node(int a = 0):val(a),cnt(1),sz(1),tag(0),fa(NULL){};
			~node(){ delete fa;}
		}*root;
		Splay(){ root = NULL;}
		void pushdown(node *cur){
			if(!cur || !cur->tag) return;
			if(cur->ch[0]){
				cur->ch[0]->tag += cur->tag;
				cur->ch[0]->val += cur->tag;
			}
			if(cur->ch[1]){
				cur->ch[1]->tag += cur->tag;
				cur->ch[1]->val += cur->tag;
			}
			cur->tag = 0;
		}
		void maintain(node *cur){
			cur->sz = cur->cnt;
			if(cur->ch[0]) cur->sz += cur->ch[0]->sz;
			if(cur->ch[1]) cur->sz += cur->ch[1]->sz;	
		}
		void rotate(node *x){
			node* y = x->fa;
			node* z = y->fa;
			pushdown(y); pushdown(x);
			x->fa = z; if(z) z->ch[y->relation()] = x;
			int k = x->relation();
			y->ch[k] = x->ch[!k]; if(x->ch[!k]) x->ch[!k]->fa = y;
			x->ch[!k] = y; y->fa = x;
			maintain(y); maintain(x);
		}
		void splay(node *cur,node *target = NULL){
			while(cur->fa != target){
				if(cur->fa->fa == target){
					rotate(cur);
				}
				else if(cur->relation() == cur->fa->relation()){
					rotate(cur->fa); rotate(cur);
				}
				else{
					rotate(cur); rotate(cur);
				}
			}
			if(target == NULL) root = cur;
		}
		node* extreme(node* cur,int k){
			while(cur->ch[k]) cur = cur->ch[k];
			return cur;
		}
		void insert(node *&cur,int val){
			if(cur == NULL){
				cur = new node(val);
				return;
			}
			if(cur->val == val){
				cur->cnt++;
				cur->sz++;
				return;
			}
			if(val < cur->val){
				cur->sz++;
				insert(cur->ch[0],val);
				cur->ch[0]->fa = cur;
			}
			else {
				cur->sz++;
				insert(cur->ch[1],val);
				cur->ch[1]->fa = cur;
			}
		}
		node* pred(node* cur){
			cur = cur->ch[0];
			while(cur->ch[1]) cur = cur->ch[1];
			return cur;
		}
		node* succ(node* cur){
			cur = cur->ch[1];
			while(cur->ch[0]) cur = cur->ch[0];
			return cur;
		}
		void remove(node* cur){
			node *pre = pred(cur), *suc = succ(cur);
			cout<<pre<<" "<<suc<<endl;
		/*	splay(pre); splay(suc,pre);
			if(cur->sz > 1){
				cur->cnt--;
				cur->sz--;
			}
			else{
				delete suc->ch[0];
				suc->ch[0] = NULL;
			}
			maintain(suc);
			maintain(pre);
			*/
		}
		void print(node* cur){
			if(cur == NULL) return;
			pushdown(cur);
			print(cur->ch[0]);
			cout<<cur->val<<" ";
			print(cur->ch[1]);
		}
		node* find_val(node* cur,int val){
			if(!cur) return NULL;
			if(val < cur->val) return find_val(cur->ch[0],val);
			else if(val == cur->val) return cur;
			else return find_val(cur->ch[1],val);	
		}
		node* first_great(int val){
			node* p = root, *p1 = root;
			while(p){
				if(p->val < val) p = p->ch[1];
				else p1 = p, p = p->ch[0];
			}
			if(p1->val < limit) {root = NULL; return NULL;}
			return p1;
		}
};
int main(){
	ios::sync_with_stdio(false);
	Splay *sp = new Splay();
	cin>>N>>limit;
	sp->insert(sp->root,-99999);
	for(int i = 1; i <= N; i++){
		char opt;
		int val;
		cin>>opt>>val;
		if(opt == 'I'){
			if(val >= limit) sp->insert(sp->root,val);
		}
		else if(opt == 'A'){
			sp->root->tag += val;
			sp->root->val += val;	
		}
		else if(opt == 'S'){
			sp->root->tag -= val;
			sp->root->val -= val;
			sp->print(sp->root);
			sp->splay(sp->extreme(sp->root,0));
			Splay::node* oth = sp->first_great(limit);
			if(oth == NULL) continue;
			sp->splay(oth,sp->root);
			sp->remove(sp->root->ch[1]->ch[0]);
		}
		else sp->print(sp->root);
	}
	return 0;
}
