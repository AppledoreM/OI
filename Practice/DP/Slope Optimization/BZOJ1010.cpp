#include "stdafx.h"
#include<cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 5e4 + 10;
int N, L, q[maxn], head, tail;
long long sum[maxn], dp[maxn], f[maxn];

double ok( int k, int j) {
	return ((dp[k] + f[k] * f[k] + 2 * f[k] * (L + 1)) - (dp[j] + f[j] * f[j] + 2 * f[j] * (L + 1))) / (2.0 * (f[k] - f[j]));
}

int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &sum[i]);
		sum[i] += sum[i - 1];
		f[i] = sum[i] + i;
	}
	head = 1, tail = 1;
	for (int i = 1; i <= N; i++) {
		while (head < tail && ok(q[head], q[head + 1]) <= (double) f[i]) head++;
		dp[i] = dp[q[head]] + (f[i] - f[q[head]] - 1 - L) * (f[i] - f[q[head]] - 1 - L);
		while (head < tail && ok(q[tail], i) < ok(q[tail - 1], q[tail])) tail--;
		q[++tail] = i;
	}
	printf("%lld\n", dp[N]);
	return 0;
}