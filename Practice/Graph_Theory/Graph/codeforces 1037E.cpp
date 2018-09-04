#include "stdafx.h" 
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
const int maxn = 2e5 + 10;
typedef pair<int, int> pii;
vector<pii> G[maxn];
vector<pii> es;
int n, m, k, deg[maxn], ans[maxn];
bool vis[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(pii(v, i));
		G[v].emplace_back(pii(u, i));
		es.emplace_back(pii(u, v));
		deg[u]++; deg[v]++;
	}
	vector<int> que;
	for (int i = 1; i <= n; i++) {
		if (deg[i] < k) {
			que.emplace_back(i);
		}
	}
	int b = 0;
	for (int i = m; i; i--) {
		while (b < que.size()) {
			int u = que[b];
			for (auto v : G[u]) {
				if (vis[v.second]) continue;
				vis[v.second] = 1;
				if (deg[v.first] == k) {
					que.emplace_back(v.first);
				}
				deg[v.first]--; deg[u]--;
			}
			b++;
		}
		ans[i] = n - que.size();
		if (!vis[i]) {
			vis[i] = 1;
			if (deg[es[i - 1].first] == k) {
				que.emplace_back(es[i - 1].first);
			}
			if (deg[es[i - 1].second] == k) {
				que.emplace_back(es[i - 1].second);
			}
			deg[es[i - 1].first]--;
			deg[es[i - 1].second]--;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}