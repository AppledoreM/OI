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
const int maxn = 30;
int n, k;
string s;
int cnt[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A' + 1]++;
	}
	int ans = INT_MAX;
	for (int i = 1; i <= k; i++) {
		ans = min(ans, cnt[i]);
	}
	cout << ans * k << endl;

	return 0;
}