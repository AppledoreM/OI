#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 1e5 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
int N,M;
char tmp[105];
struct SA{
	int idx(char c) {
		if(c == 'E') return 1;
		else if(c == 'S') return 2;
		else if(c == 'W') return 3;
		else if(c == 'N') return 0;
		return assert(0),0;
	}
	struct node{
		node *fail, *ch[4];
		int mx;
		node(int a = 0):fail(NULL),mx(a){};
	} *start,*last;
	void init(){
		start = last = new node();
	}
	node *extend(char ch){
		int c = idx(ch);
		node *u = new node(last->mx + 1), *v = last;
		for(;v && !v->ch[c]; v = v->fail) v->ch[c] = u;
		if(!v){
			u->fail = start;
		}
		else if(v->ch[c]->mx == v->mx + 1){
			u->fail = v->ch[c];
		}
		else{
			node *n = new node(v->mx + 1), *o = v->ch[c];
			copy(o->ch,o->ch + 4,n->ch);
			n->fail = o->fail;
			o->fail = u->fail = n;
			for(; v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
		}
		last = u;
		return u;
	}
	int calc(){
		node *rt = start;
		char ch;
		int n = strlen(tmp);
		for(int i = 1; i <= n; i++){
			int c = idx(tmp[i - 1]);
			if(rt->ch[c] == NULL) return i - 1;
			rt = rt->ch[c];
		}
		delete rt;
		return n;
	}
} *sa;

int main(){
	scanf("%d%d",&N,&M);
	sa = new SA();
	sa->init();
	getchar();
	for(int i = 0; i < N; i++) {
		char ch;
		ch = getchar();
		sa->extend(ch);
	}
	for(int i = 1; i <= M; i++){
		scanf("%s",tmp);
		printf("%d\n",sa->calc());		
	}
	delete sa;
	return 0;
}

