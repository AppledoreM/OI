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
void insert(int &cur,int v) {
	pushdown(cur);
	if (!cur) {
		cur = ++tot;
		cnt[cur] = sz[cur] = 1;
		val[cur] = v;
	}
	else if (v == val[cur]) {
		cnt[cur]++;
		sz[cur]++;
	}
	else if (v < val[cur]) {
		insert(ch[cur][0], v);
		fa[ch[cur][0]] = cur;
		maintain(cur);
	}
	else {
		insert(ch[cur][1], v);
		fa[ch[cur][1]] = cur;
		maintain(cur);
	}
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
	pushdown(cur);
	if (sz[ch[cur][0]] >= s) return find_k(ch[cur][0], s);
	else if (sz[ch[cur][0]] < s && s <= sz[ch[cur][0]] + cnt[cur]) return cur;
	else return find_k(ch[cur][1], s - cnt[cur] - sz[ch[cur][0]]);
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
		insert(root, limit - 1);
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
	insert(root, INF); insert(root, -INF);
	for (int i = 1; i <= N; i++) {
		char opt;
		int v;
		cin >> opt >> v;
		if (opt == 'I') {
			if (v < limit) continue;
			insert(root, v);
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