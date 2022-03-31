#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int maxn = 3e5 + 10;
int n, m, cur1, cur2, ans;;
long long a[maxn], b[maxn], sum1, sum2;

int main() {
	ios_base::sync_with_stdio(false);
	cur1 = cur2 = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum1 += a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		sum2 += b[i];
	}
	if (sum1 != sum2) {
		cout << "-1" << endl;
		exit(0);
	}
	sum1 = sum2 = 0;
	if (n > m) {
		swap(a, b);
		swap(n, m);
	}

	while (cur1 <= n && cur2 <= m) {
		if (!sum1){
			sum1 += a[cur1++];
			sum2 += b[cur2++];
		}
		else if (sum1 < sum2) sum1 += a[cur1++];
		else sum2 += b[cur2++];
		if (sum1 == sum2) {
	//		cout << "A breaking point at " << cur1 - 1<< " " << cur2 - 1<< endl;
			ans++;
			sum1 = sum2 = 0;
		}
	}
	while (cur1 <= n) sum1 += a[cur1++];
	while (cur2 <= m) sum2 += b[cur2++];
	if (sum1 && sum1 == sum2) {
		ans++;
		cur1++;
		cur2++;
	}
	if (cur1 <= n || cur2 <= m || ans == 0) {
		cout << "-1" << endl;
	}
	else cout << ans << endl;

	return 0;
}