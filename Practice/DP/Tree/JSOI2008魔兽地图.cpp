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
typedef pair<int, int> pii;
int n, m, dp[55][105][2005], g[2005], ans[2005];
int stren[55], ish[55], cost[55], num[55], L[55], deg[55];
bool vis[55];
struct 
vector<pii> G[55];

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	if (!G[u].size()) {
		num[u] = min(num[u], m / cost[u]);
		for (int i = num[u]; i >= 0; i--) {
			for (int j = i; j <= num[u]; j++) {
				dp[u][i][j * cost[u]] = stren[u] * (j - i);
			}
		}
		return;
	}
	num[u] = 1e9;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		int need = G[u][i].second;
		dfs(v);
		num[u] = min(num[u], num[v] / need);
		cost[u] += need * cost[v];
	}
	num[u] = min(num[u], m / cost[u]);

	for (int i = num[u]; i >= 0; i--) {
		memset(g, -0x3f, sizeof(g));
		g[0] = 0;
		for (int j = 0; j < G[u].size(); j++) {
			int v = G[u][j].first;
			for (int a = m; a >= 0; a--) {
				int tmp = -1e9;
				for (int b = 0; b <= a; b++) {
					tmp = max(tmp, g[a - b] + dp[v][i * G[u][j].second][b]);
					g[a] = tmp;
				}
			}
		}
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= m; k++) {
				dp[u][j][k] = max(dp[u][j][k], g[k] + stren[u] * (i - j));
			}
		}
	}
}

int main() {
	memset(dp, -0x3f, sizeof(dp));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stren[i]);
		char opt[2];
		scanf("%s", opt);
		if (opt[0] == 'A') {
			int c;
			scanf("%d", &c);
			for (int j = 1; j <= c; j++) {
				int a, b;
				scanf("%d%d", &a, &b);
				G[i].push_back(pii(a, b));
				deg[a]++;
			}
		}
		else {
			scanf("%d%d", &cost[i], &num[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			dfs(i);
			for (int j = m; j >= 0; j--) {
				for (int k = 0; k <= j; k++) {
					ans[j] = max(ans[j], ans[j - k] + dp[i][0][k]);
				}
			}
		}
	}
	printf("%d\n", ans[m]);
	return 0;
}