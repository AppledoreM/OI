#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stdio.h>
#include <queue>
inline int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9')ch = getchar();
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x;
}
using namespace std;
const int maxn = 305;
int N, M;
int BIT[maxn][maxn][maxn], mp[maxn][maxn];
inline int lowbit(int x) { return x & -x; }

void update(int x, int y, int c, int delta) {
	for (int i = x; i <= N; i += lowbit(i)) {
		for (int j = y; j <= M; j += lowbit(j)) {
			BIT[c][i][j] += delta;
		}
	}
}

inline int query(int x, int y, int c) {
	int re = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			re += BIT[c][i][j];
		}
	}
	return re;
}

int main() {
	N = read();
	M = read();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			mp[i][j] = read();
			update(i, j, mp[i][j], 1);
		}
	}
	int Q;
	Q = read();
	for (int i = 1; i <= Q; i++) {
		int opt;
		opt = read();
		if (opt == 1) {
			int x1, y1, x2, y2, c;
			x1 = read(); y1 = read(); x2 = read(); y2 = read(); c = read();
			printf("%d\n", query(x2, y2, c) - query(x1 - 1, y2, c) - query(x2, y1 - 1, c) + query(x1 - 1, y1 - 1, c));
		}
		else {
			int x, y, c;
			x = read(); y = read(); c = read();
			update(x, y, mp[x][y], -1);
			mp[x][y] = c;
			update(x, y, mp[x][y], 1);
		}
	}
	return 0;
}
