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
#include <stack>
using namespace std;
#define inf 0x3f3f3f3f
int n, x, y, z, a, b, dp[55][25][25][5];

void shift(int ii, int jj, int kk, int ll, int i, int j, int k, int l) {
	jj = min(jj, a);
	kk = min(kk, b);
	dp[ii][jj][kk][ll] = min(dp[ii][jj][kk][ll], dp[i][j][k][l] + 1);
}

int main() {
	scanf("%d%d%d%d%d%d", &n, &x, &y, &z, &a, &b);
	memset(dp, inf, sizeof(dp));
	dp[n][0][0][0] = 0;
	int ans = inf;
	for (int i = n; i < 35; i++) {
		for (int last = 0; last < 4; last++) {
			for (int j = 0; j <= a; j++) {
				for (int k = 0; k <= b; k++) {
					if (dp[i][j][k][last] == inf) continue;
					if (j >= a && k >= b) {
						ans = min(ans, dp[i][j][k][last]);
						continue;
					}
					if (dp[i][j][k][last] >= ans) continue;
					for (int p = 0; p <= i; p++) {
						int newj = j + p * x;
						int newk = k + (i - p) * y;
						int newi = i;
						if (last == 3) newi++;
						if (last == 0 || last == 3) {
							shift(newi, newj, newk, 0, i, j, k, last);
							if(newj - z >= 0) shift(newi, newj - z, newk, 1, i, j, k, last);
						}
						else shift(newi, newj, newk, last + 1, i, j, k, last);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
