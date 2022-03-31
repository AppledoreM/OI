#include "stdafx.h"
#include<cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 1e6 + 10;
int N, a, b, c, x[maxn], sum[maxn], q[maxn], head, tail;
long long dp[maxn];

double slop(int k, int j) {
	double tmp = (dp[j] - dp[k] + b * (sum[k] - sum[j]) + a * ((long long)sum[j] * sum[j] - (long long)sum[k] * sum[k]));
	return tmp / (2.0 * a * (sum[j] - sum[k]));
}

int main() {
	scanf("%d", &N);
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &x[i]);
		sum[i] = sum[i - 1] + x[i];
	}
	head = tail = 1;
	for (int i = 1; i <= N; i++) {
		while(head < tail && slop(q[head],q[head + 1]) < (double) sum[i]) head++;
		long long x = sum[i] - sum[q[head]];
		dp[i] = dp[q[head]] + a * x * x + b * x + c;
		while (head < tail && slop(q[tail], i) < slop(q[tail - 1], q[tail])) tail--;
		q[++tail] = i;
	}
	printf("%lld\n", dp[N]);
	return 0;
}