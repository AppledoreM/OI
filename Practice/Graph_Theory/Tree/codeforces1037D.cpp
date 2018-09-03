#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 2e5 + 10;
int tot, N, ord[maxn], bf[maxn], a[maxn];
bool vis[maxn];
vector<int> G[maxn];
bool cmp(int a, int b) {
	return ord[a] < ord[b];
}
void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 1;
		bf[++tot] = u;
		for (int v : G[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		ord[tmp] = i;
		a[i] = tmp;
	}
	for (int i = 1; i <= N; i++) sort(G[i].begin(), G[i].end(), cmp);
	bfs();
	for (int i = 1; i <= N; i++) {
		if (a[i] != bf[i]) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;
	return 0;
}