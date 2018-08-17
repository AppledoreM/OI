#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 1e6 + 10;
int fa[maxn],cnt[maxn],ch[maxn][2],val[maxn],tag[maxn],sz[maxn];
int root,tot,limit,N,ans;
const int INF = -9999999;
void maintain(int cur) {
	sz[cur] = sz[ch[cur][0]] + sz[ch[cur][1]] + cnt[cur];
}
void update(int cur, int delta) {
	if (val[cur] != INF && val[cur] != -INF) val[cur] += delta;
	tag[cur] += delta;
}
void pushdown(int cur) {
	update(ch[cur][0],tag[cur]);
	update(ch[cur][1],tag[cur]);
	tag[cur] = 0;
}
void newnode(int cur,int f,int v) {
	sz[cur] = cnt[cur] = 1;
	fa[cur] = f;
	val[cur] = v;
	if(f) ch[f][val[cur] > val[f]] = cur;
	maintain(cur);
	maintain(f);
}
void clear(int cur) {
	val[cur] = ch[cur][0] = ch[cur][1] = sz[cur] = cnt[cur] = fa[cur] = 0;
}
int which(int x) { return ch[fa[x]][1] == x; }
void rotate(int x) {
	int y = fa[x], z = fa[y];
	pushdown(y); pushdown(x);
	int k = which(x); int r = which(y);
	ch[y][k] = ch[x][!k]; fa[ch[y][k]] = y;
	ch[x][!k] = y; fa[y] = x;
	if(z) ch[z][r] = x; fa[x] = z;
	maintain(y); maintain(x);
}

void splay(int x, int target = 0){
	for (; fa[x] != target; rotate(x)) {
		pushdown(fa[x]);
		int y = fa[x], z = fa[y];
		if (z != target) which(x) == which(y) ? rotate(y) : rotate(x);
	}
	if (!target) root = x;
}
void insert(int v) {
	if (root == 0) {
		clear(root);
		root = ++tot;
		newnode(root, 0, v);
		return;
	}
	int now = root, f = 0;
	while (1) {
		pushdown(now);
		if (v == val[now]) {
			cnt[now]++;  maintain(now); maintain(f); splay(now);
			break;
		}
		f = now;
		now = ch[now][v > val[now]];
		if (now == 0) {
			now = ++tot;
			clear(now);
			newnode(now, f, v);
			splay(now);
			break;
		}
	}
}
int find_min(int cur) {
	pushdown(cur);
	if (val[cur] == INF) return cur;
	else return find_min(ch[cur][0]);
}
int find_val(int cur, int v) {
	if (!cur) return 0;
	pushdown(cur);
	if (val[cur] == v) return cur;
	else if (val[cur] < v) return find_val(ch[cur][1], v);
	else return find_val(ch[cur][0], v);
}
int succ(int cur) {
	splay(cur);
	cur = ch[cur][1];
	while (ch[cur][0]) cur = ch[cur][0];
	return cur;
}
int find_k(int cur, int s) {
	while (cur) {
		pushdown(cur);
		if (s <= sz[ch[cur][0]]) cur = ch[cur][0];
		else {
			if (sz[ch[cur][0]] < s && s <= sz[ch[cur][0]] + cnt[cur]) return cur;
			else {
				s -= cnt[cur] + sz[ch[cur][0]];
				cur = ch[cur][1];
			}
		}
	}
	return 0;
}
void dfs(int cur) {
	if(!cur) return;
	dfs(ch[cur][0]);
	cout << val[cur] << " ";
	dfs(ch[cur][1]);
}
void print() {
	dfs(root);
	puts("");
	puts("-----------------------");
}
void erase() {
	int x = find_min(root);
	int y = find_val(root,limit - 1);
	int add = 0;
	if (!y) {
		add++;
		insert(limit - 1);
		y = find_val(root, limit - 1);
	}
	y = succ(y);
	splay(x);
	splay(y, x);
	ans += sz[ch[y][0]] - add;
	clear(ch[y][0]);
	ch[y][0] = 0;
	maintain(y);
	maintain(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> limit;
	insert(INF); insert(-INF);
	for (int i = 1; i <= N; i++) {
	//	cout << "On Query No." << i << endl;
		char opt;
		int v;
		cin >> opt >> v;
		if (opt == 'I') {
			if (v < limit) continue;
			insert(v);
		}
		else if(opt == 'A'){
			update(root, v);
		}
		else if (opt == 'S') {
			update(root, -v);
			erase();
		}
		else {
			if (v < 1 || v > sz[root] - 2) cout << -1 << endl;
			else {
				int re = val[find_k(root, sz[root] - v)];
				if (re == INF || re == -INF) cout << -1 << endl; 
				else cout << re << endl;
			}
		}
//		print();
	}
	cout << ans << endl;
	return 0;
}