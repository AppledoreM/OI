#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;
const int maxn = 2e5 + 10;
char str[maxn];
int s[maxn], sa[maxn], wa[maxn], wb[maxn], wss[maxn], wv[maxn], rnk[maxn], height[maxn];
bool cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void build(int *s,int n,int m){
	int i, j, p, *x = wa, *y = wb;
	for (i = 0; i < m; i++) wss[i] = 0;
	for (i = 0; i < n; i++) wss[x[i] = s[i]]++;
	for (i = 1; i < m; i++) wss[i] += wss[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
	for (p = 1, j = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < m; i++) wss[i] = 0;
		for (i = 0; i < n; i++) wv[i] = x[y[i]];
		for (i = 0; i < n; i++) wss[wv[i]]++;
		for (i = 1; i < m; i++) wss[i] += wss[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
		swap(x, y);
		for (x[sa[0]] = 0, i = 1, p = 1; i < n; i++) {
			x[sa[i]] = cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
		}
	}
}
pair<int, int> a[maxn];
int main() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = n; i < 2 * n; i++) {
		str[i] = str[i - n];
	}
	int m = 0;
	for (int i = 0; i < 2 * n; i++) {
		s[i] = str[i];
		m = max(s[i] + 2, m);
	}
	build(s, 2 * n + 1, m);
	for (int i = 1; i <= 2 * n; i++) if(sa[i] < n) cout << str[sa[i] + n - 1];
	return 0;
}