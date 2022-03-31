#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
int N,M;
class Splay{
	public:
		struct node{
			node *fa,*ch[2];
			int sz,val;
			bool rev;
			node(int x = 0):fa(NULL),rev(0),val(x),sz(1){
				ch[0] = ch[1] = NULL;
			}
		} *root;
		void pushdown(node* cur){
			if(!cur || !cur->rev) return;
			swap(cur->ch[0],cur->ch[1]);
			if(cur->ch[0]) cur->ch[0]->rev ^= 1;
			if(cur->ch[1]) cur->ch[1]->rev ^= 1;
			cur->rev = 0;
		}
		int relation(node *cur){
			return cur->fa->ch[1] == cur;
		}
		void maintain(node *cur){
			cur->sz = 1;
			if(cur->ch[0]) cur->sz += cur->ch[0]->sz;
			if(cur->ch[1]) cur->sz += cur->ch[1]->sz;
		}
		void rotate(node *cur){
			node *y = cur->fa;
			node *z = y->fa;
			pushdown(y);
			pushdown(cur);
			int x = relation(cur);
			cur->fa = z;
			if(z) z->ch[relation(y)] = cur;	
			y->ch[x] = cur->ch[!x];
			if(cur->ch[!x]) cur->ch[!x]->fa = y;
			cur->ch[!x] = y;	
			y->fa = cur;
			maintain(y);
			maintain(cur);
		}
		void splay(node *cur,node *target = NULL){
			while(cur->fa != target){
				if(cur->fa->fa == target){
					rotate(cur);
				}
				else if(relation(cur) == relation(cur->fa)){
					rotate(cur->fa);
					rotate(cur);
				}
				else {
					rotate(cur);
					rotate(cur);
				}
			}
			if(target == NULL) root = cur;
		}
		node* find_pos(node *cur,int tot){
			pushdown(cur);
			if(!cur) return NULL;
			int sz = (cur->ch[0] ? cur->ch[0]->sz : 0);
			if(sz >= tot) return find_pos(cur->ch[0],tot);
			else if(sz + 1 == tot) {
				return cur;
			}
			else return find_pos(cur->ch[1], tot - 1 - sz);
		}
		void build(node* &cur, int l,int r){
			if(l > r) return;
			int mid = (l + r) >> 1;
			cur = new node(mid);
			if(l == r) return;
			build(cur->ch[0],l,mid - 1);
			build(cur->ch[1],mid + 1,r);
			if(cur->ch[0]) cur->ch[0]->fa = cur;
			if(cur->ch[1]) cur->ch[1]->fa = cur;
			maintain(cur);
		}
		Splay(int N){
			root = NULL;
			build(root,1,N + 2);
		}
		void print(node *cur){
			if(!cur) return;
			pushdown(cur);
			if(cur->ch[0]) print(cur->ch[0]);
			printf("%d ",cur->val - 1);
			if(cur->ch[1]) print(cur->ch[1]);
		}
		void reverse_seq(int l,int r){
			node *st = find_pos(root,l);
			node *ed = find_pos(root,r);
			splay(st);
			splay(ed,root);
			if(root->ch[1]->ch[0]) root->ch[1]->ch[0]->rev ^= 1;
		}	
		void print_ans(){
			node *st = find_pos(root,1);
			node *ed = find_pos(root,N + 2);
			splay(st,NULL);
			splay(ed,root);
			print(root->ch[1]->ch[0]);
		}
};
int main(){
	scanf("%d%d",&N,&M);
	Splay *sp = new Splay(N);
	for(int i = 1; i <= M; i++){
		int l,r;
		scanf("%d%d",&l,&r);
		sp->reverse_seq(l,r + 2);
	}
	sp->print_ans();
	return 0;
}
