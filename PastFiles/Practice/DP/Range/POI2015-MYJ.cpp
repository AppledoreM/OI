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
const int maxn = 55;
const int maxm = 4005;
typedef long long ll;
int n, m, tot;
int ls[maxm], rs[maxm], val[maxm], p[maxm], c[maxm];
int dp[maxn][maxn][maxm], f[maxn][maxn][maxm], pre[maxn][maxn][maxm], cnt[maxn][maxm];
int cost[maxn];
void form(int l, int r, int k) {
	if (l > r) return;
	int pos = f[l][r][k = pre[l][r][k]];
	cost[pos] = p[k];
	form(l, pos - 1, k);
	form(pos + 1, r, k);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> ls[i] >> rs[i] >> val[i];
		p[i] = val[i];
	}
	sort(p + 1, p + 1 + m);
	tot = unique(p + 1, p + 1 + m) - p - 1;
	for (int i = 1; i <= m; i++) c[i] = lower_bound(p + 1, p + 1 + tot, val[i]) - p;
	
	for (int l = n; l >= 1; l--) {
		for (int r = l; r <= n; r++) {
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= m; i++) {
				if (l <= ls[i] && rs[i] <= r) {
					for (int j = ls[i]; j <= rs[i]; j++) {
						cnt[j][c[i]]++;
					}
				}
			}
			for (int i = l; i <= r; i++) {
				for (int j = tot - 1; j; j--) cnt[i][j] += cnt[i][j + 1];
			}
			for (int mn_val = tot; mn_val; mn_val--) {
				int mx_v = 0;
				for (int k = l; k <= r; k++) {
					int w = dp[l][k - 1][mn_val] + dp[k + 1][r][mn_val] + cnt[k][mn_val] * p[mn_val];
					if (mx_v <= w) {
						mx_v = w;
						f[l][r][mn_val] = k;
					}
				}
				if (mx_v >= dp[l][r][mn_val + 1]) {
					dp[l][r][mn_val] = mx_v;
					pre[l][r][mn_val] = mn_val;
				}
				else {
					dp[l][r][mn_val] = dp[l][r][mn_val + 1];
					pre[l][r][mn_val] = pre[l][r][mn_val + 1];
				}
			}
		}
	}
	cout << dp[1][n][1] << endl;
	form(1, n, 1);
	for (int i = 1; i <= n; i++) cout << cost[i] << " ";
	return 0;
}