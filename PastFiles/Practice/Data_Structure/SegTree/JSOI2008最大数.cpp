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
int n;
long long D;
long long tree[maxn<<2];
int tot;

void change(int cur, int l, int r, int a, int b, long long delta) {
	if (a <= l && r <= b) {
		tree[cur] = delta;
		return;
	}
	int mid = l + r >> 1;
	if (a <= mid) change(cur << 1, l, mid, a, b, delta);
	if (b > mid) change(cur << 1 | 1, mid + 1, r, a, b, delta);
	tree[cur] = max(tree[cur << 1], tree[cur << 1 | 1]);
}

long long query(int cur, int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return tree[cur];
	}
	long long ans = 0;
	int mid = l + r >> 1;
	if (a <= mid) ans = max(ans, query(cur << 1, l, mid, a, b));
	if (b > mid) ans = max(ans, query(cur << 1 | 1, mid + 1, r, a, b));
	return ans;
}

struct q {
	char o;
	long long val;
}ques[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> D;
	long long t = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ques[i].o >> ques[i].val;
		if (ques[i].o == 'A') tot++;
	}
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		char opt;
		long long v;
		opt = ques[i].o;
		v = ques[i].val;
		if (opt == 'A') {
			pos++;
			change(1, 1, tot, pos, pos, (v + t) % D);
		}
		else {
			t = query(1, 1, tot, pos - v + 1, pos);
			printf("%lld\n", t);
		}
	}
	
	return 0;
}
