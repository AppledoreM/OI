#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 5e5 + 10;
int n, a[maxn];
bool yesn, yesp;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans += abs(a[i]);
		if (a[i] < 0) yesn = 1;
		if (a[i] > 0) yesp = 1;
	}
	if (n == 1) {
		cout << a[1] << endl;
		return 0;
	}
	long long tmp = 1e9 + 10;
	if((!(yesn&&yesp))) {
		for (int i = 1; i <= n; i++) {
			if (abs(tmp) > abs(a[i])) {
				tmp = a[i];
			}
		}
	}
	else tmp = 0;
	if (!yesp) tmp = -tmp;
	cout << ans - 2 * tmp << endl;
	return 0;
}