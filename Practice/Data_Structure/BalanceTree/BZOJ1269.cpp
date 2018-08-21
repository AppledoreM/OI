#include <iostream>
#include <stdio.h> 
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 5e6 + 10;
const int INF = 999;
int root,cur,tot,val[maxn],ch[maxn][2],fa[maxn],sz[maxn];
bool rev[maxn];
char str[maxn];
int which(int x){ return ch[fa[x]][1] == x;}
void clear(int cur){
	ch[cur][0] = ch[cur][1] = sz[cur] = fa[cur] = val[cur] = rev[cur] = 0;	
}

void newnode(int &cur,int f,int v,int z = 1){
	cur = ++tot;
	fa[cur] = f;
	val[cur] = v;	
	sz[cur] = z;
}

void pushdown(int cur){
	if(!rev[cur]) return;
	swap(ch[cur][0],ch[cur][1]);
	rev[ch[cur][0]] ^= 1;
	rev[ch[cur][1]] ^= 1;
	rev[cur] = 0;
}

void maintain(int cur){
	sz[cur] = 1 + sz[ch[cur][0]] + sz[ch[cur][1]];
}

void rotate(int x){
	int y = fa[x], z = fa[y];
	pushdown(y); pushdown(x);
   	int k = which(x); int r = which(y);	
	ch[y][k] = ch[x][!k]; if(ch[y][k]) fa[ch[y][k]] = y;
	ch[x][!k] = y; fa[y] = x;
	fa[x] = z; if(z) ch[z][r] = x;
	maintain(y);
	maintain(x);
}

void splay(int x,int goal = 0){
	for(; fa[x] != goal; rotate(x)){
		pushdown(fa[x]);
		if(fa[fa[x]] != goal) which(fa[x]) == which(x) ? rotate(fa[x]) : rotate(x);
	}
	if(goal == 0) root = x;
}

int find_k(int k){
	int now = root;
	while(k){
		pushdown(now);
		if(ch[now][0] && k <= sz[ch[now][0]]) now = ch[now][0];
		else{
			if(k == sz[ch[now][0]] + 1) return now;
			else {
				k -= sz[ch[now][0]] + 1;
				now = ch[now][1];
			}
		}	
	}
	return now;
}
void insert(int val){
	if(root == 0){
		newnode(root,0,val);	
		return;
	}
	newnode(ch[root][1],root,val);
	maintain(root);
}

void rotate(int l,int r){
	int x = find_k(l), y = find_k(r + 2);
	splay(x); splay(y,x);
	rev[ch[y][0]] ^= 1;
}
void erase(int l,int r){
	int x = find_k(l), y = find_k(r + 2);
	splay(x); splay(y,x);
	clear(ch[y][0]);
	ch[y][0] = 0;
	maintain(y);
	maintain(x);
}
void insert_string(int cur,int len){
	pushdown(cur);
	newnode(ch[cur][0],cur,str[1],len);
	int pre = ch[cur][0];
	for(int i = 2; i <= len; i++){
		pushdown(pre);
		ch[pre][1] = ++tot;
		fa[tot] = pre;
		sz[tot] = len - i + 1;
		val[tot] = str[i];
		pre = tot;
	}	
}
void output(int cur){
	if(val[cur] == -INF || val[cur] == INF);// cout<<val[cur]<<" ";
	else cout<<(char)(val[cur])<<" ";
}
void dfs(int x){
	if(!x) return;
	dfs(ch[x][0]);
	output(x);
	cout<<" ";
	dfs(ch[x][1]);
}
void print(){
	dfs(root);
	puts("");
	puts("-----------");
}

int main(){
	int N;
	scanf("%d",&N);
	insert(-INF);
	insert(INF);
	for(int i = 1; i <= N; i++){
		char opt[15];
		scanf("%s",opt);
		if(opt[0] == 'I'){
			int len; 
			scanf("%d",&len);
			getchar();
			for(int i = 1; i <= len; i++) str[i] = getchar();
			int l = find_k(cur + 1);
			int r = find_k(cur + 2);
			splay(l); splay(r,l);
			insert_string(r,len);
			splay(tot);
		}
		else if(opt[0] == 'M') scanf("%d",&cur);
		else if(opt[0] == 'D'){
			int n;
			scanf("%d",&n);
			erase(cur + 1,cur + n);		
		}
		else if(opt[0] == 'R'){
			int n;
			scanf("%d",&n);
			rotate(cur + 1,cur + n);
		}
		else if(opt[0] == 'P') cur--;
		else if(opt[0] == 'N') cur++;
		else{
			int now = find_k(cur + 2);
			putchar((char)val[now]);
			if(val[now] != 10) puts(""); 
			splay(now);
		}
	}
	return 0;
}
