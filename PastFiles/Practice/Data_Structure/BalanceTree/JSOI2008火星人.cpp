#include "stdafx.h" 
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <assert.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 1e5 + 10;
const int base = 133;
char s[maxn];
ll ha[maxn], pw[maxn];
int m;
int cnt, tot, ch[maxn][2], fa[maxn], sz[maxn], root, val[maxn];
inline int which(int x) { return ch[fa[x]][1] == x; }

void update(int x) {
	int l = ch[x][0], r = ch[x][1];
	sz[x] = sz[l] + sz[r] + 1;
	ha[x] = ha[r] + pw[sz[r]] * val[x];
	ha[x] += ha[l] * pw[sz[r] + 1];
}

void rotate(int x) {
	int y = fa[x], z = fa[y];
	int k = which(x), r = which(y);
	ch[y][k] = ch[x][!k]; fa[ch[y][k]] = y;
	fa[y] = x; ch[x][!k] = y;
	if (z) ch[z][r] = x;
	fa[x] = z;
	update(y);
	update(x);
}

void splay(int x, int goal = 0) {
	for (; fa[x] != goal; rotate(x)) {
		int y = fa[x], z = fa[y];
		if (z != goal) which(x) == which(y) ? rotate(y) : rotate(x);
	}
	if (!goal) root = x;
}

int find_nod(int pos) {
	int cur = root;
	while (cur) {
		if (pos <= sz[ch[cur][0]]) {
			cur = ch[cur][0];
		}
		else if (pos == sz[ch[cur][0]] + 1) {
			return cur;
		}
		else {
			pos = pos - sz[ch[cur][0]] - 1;
			cur = ch[cur][1];
		}
	}
	return -1;
}

int newnode(int &x, int f, int k,int v) {
	x = ++tot;
	fa[x] = f;
	val[x] = ha[x] = v;
	if(f) ch[f][k] = x;
	update(x);
	if(f) update(f);
	return x;
}

void _insert(int v, int pos) {
	int cur = find_nod(pos + 1);
	splay(cur);
	int right = find_nod(pos + 2);
	splay(right, cur);
	int now = newnode(ch[right][0], right, 0, v);
	splay(now);
}

void _replace(int v, int pos) {
	int cur = find_nod(pos + 1);
	assert(cur != -1);
	val[cur] = ha[cur] = v;
	splay(cur);
}

bool okay(int x, int y, int len) {
	int nod = find_nod(x);
	if (nod == -1) return false;
	splay(nod, 0);
	nod = find_nod(x + len + 1);
	if (nod == -1) return false;
	splay(nod, root);
	ll has1 = ha[ch[nod][0]];

	nod = find_nod(y);
	if (nod == -1) return false;
	splay(nod, 0);
	nod = find_nod(y + len + 1);
	if (nod == -1) return false;
	splay(nod, root);
	ll has2 = ha[ch[nod][0]];
	return has1 == has2;
}

int get_ans(int x, int y) {
	int l = 1, r = cnt;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (okay(x, y, mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}

void build(int &x, int f, int k, int l, int r) {
	if (l > r) return;
	int mid = (l + r) / 2;
	newnode(x, f, k, s[mid] - 'a' + 1);
	build(ch[x][0], x, 0, l, mid - 1);
	build(ch[x][1], x, 1, mid + 1, r);
	update(x);
}

void dfs(int cur) {
	if (!cur) return;
	dfs(ch[cur][0]);
	cout << (char) (val[cur] + 'a' - 1) << " ";
	dfs(ch[cur][1]);
}
void print() {
	puts("------------");
	dfs(root);
	puts("\n------------");
}
int main() {
	scanf("%s", s + 2);
	scanf("%d", &m);
	pw[0] = 1;
	for (int i = 1; i < maxn; i++) pw[i] = pw[i - 1] * base;
	int n = strlen(s + 2);
	s[1] = 'z' + 1;
	s[n + 2] = 'z' + 1;
	build(root, 0, 0, 1, n + 2);
	cnt = n;
//	print();
	for (int i = 1; i <= m; i++) {
		char opt[2];
		scanf("%s", opt);
		if (opt[0] == 'Q') {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", get_ans(x, y));
		}
		else if(opt[0] == 'R') {
			int pos;
			scanf("%d", &pos);
			scanf("%s", opt);
			_replace(opt[0] - 'a' + 1, pos);
		}
		else {
			cnt++;
			int pos;
			scanf("%d", &pos);
			scanf("%s", opt);
			_insert(opt[0] - 'a' + 1, pos);
		}
	//	print();
	}
	return 0;
}
