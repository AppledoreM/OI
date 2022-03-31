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
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
pll a[maxn];

bool cmp(pll a, pll b) {
	return a.second < b.second;
}
int ans;
priority_queue<ll, vector<ll>, less<ll>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + 1 + n, cmp);
	ll now = 0;
	for (int i = 1; i <= n; i++) {
		if (now + a[i].first <= a[i].second) {
			now += a[i].first;
			q.push(a[i].first);
			ans++;
		}
		else {
			ll tmp = q.top();
			if (a[i].first < tmp) {
				now = now - tmp + a[i].first;
				q.pop();
				q.push(a[i].first);
			}
		}
	}
	cout << ans << endl;
	return 0;
}