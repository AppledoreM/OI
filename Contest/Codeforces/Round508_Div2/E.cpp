#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int maxn = 2e2 + 10;
int n, deg[maxn];
long long sum;

inline int comp(int u, int v) {
	if (u > v) swap(u, v);
	return u * 4 + v;
}

struct edge {
	int u, v, val, idx;
	edge(int a = 0, int b = 0, int c = 0, int d = 0) :u(a), v(b), val(c), idx(d) {};
};

vector<edge> es[maxn], G[5];
bool cmp(edge a, edge b) { return a.val < b.val; }
bool vis[maxn], ban[maxn];

void dfs(int u) {
	for (auto e : G[u]) {
		int idx = e.idx;
		if (vis[idx] || ban[idx]) continue;
		vis[idx] = 1;
		dfs(e.v);
		sum += e.val;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v, val;
		cin >> u >> val >> v;
		u--, v--;
		deg[u]++;
		deg[v]++;
		G[u].emplace_back(edge(u, v, val, i));
		G[v].emplace_back(edge(v, u, val, i));
		es[comp(u, v)].emplace_back(edge(u,v,val,i));
	}

	for (int i = 0; i < 16; i++) {
		if (!es[i].empty()) sort(es[i].begin(), es[i].end(), cmp);
	}
	long long ans = 0;
	for (int i = 0; i < (1 << 16); i++) {
		memset(ban, 0, sizeof(ban));
		vector<int> aff;
		for (int j = 0; j < 16; j++) {
			if (!((i >> j) & 1)) continue;
			if (!es[j].empty()) {
				deg[es[j][0].u]--;
				deg[es[j][0].v]--;
				ban[es[j][0].idx] = 1;
				aff.emplace_back(j);
			}
		}
		int odd_cnt = 0;
		int rt = 0;
		for (int i = 0; i < 4; i++) {
			if (deg[i] & 1) {
				odd_cnt++;
				rt = i;
			}
		}

		if (odd_cnt != 2 && odd_cnt != 0) {
			goto A;
		}
		if (odd_cnt == 2) {
			memset(vis, 0, sizeof(vis));
			dfs(rt);
			ans = max(ans, sum);
			sum = 0;
		}
		else{
			for (int i = 0; i < 4; i++) {
				memset(vis, 0, sizeof(vis));
				dfs(i);
				ans = max(ans, sum);
				sum = 0;
			}
		}
		A:;
		for (int v : aff) {
			deg[es[v][0].u]++; deg[es[v][0].v]++;
			ban[es[v][0].idx] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}