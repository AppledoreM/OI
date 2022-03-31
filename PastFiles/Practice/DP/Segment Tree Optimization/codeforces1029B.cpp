#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 2e5 + 10;
int N;
int dp[maxn], a[maxn], b[maxn], tree[maxn<<2];

void change(int cur, int l, int r, int pos, int delta) {
	if (l == r) {
		tree[cur] = delta;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) change(cur << 1, l, mid, pos, delta);
	else change(cur << 1 | 1, mid + 1, r, pos, delta);
	tree[cur] = max(tree[cur << 1], tree[cur << 1 | 1]);
}

int query_mx(int cur, int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return tree[cur];
	}
	int re = 0;
	int mid = l + r >> 1;
	if (a <= mid) re = max(re, query_mx(cur << 1, l, mid, a, b));
	if (b > mid) re = max(re, query_mx(cur << 1 | 1, mid + 1, r, a, b));
	return re;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= N; i++) b[i] = lower_bound(a, a + N + 1, (a[i] + 1) / 2) - a;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int mx = query_mx(1, 0, N, b[i], i);
		dp[i] = mx + 1;
		change(1, 0, N, i, dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}