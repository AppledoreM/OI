#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, a[maxn], mat[maxn];
bool ex[maxn];
set<int> s;
int pre[maxn], suf[maxn];

int main() {
	freopen("cardgame.in","r",stdin);
	freopen("cardgame.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ex[a[i]] = 1;
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!ex[i]) s.insert(i);
	}

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		auto it = s.lower_bound(a[i]);
		if (it != s.end()) {
			pre[i]++;
			s.erase(it);
		}
	}
	s.clear();
	for (int i = 1; i <= 2 * n; i++) {
		if (!ex[i]) s.insert(-i);
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1];
		auto it = s.lower_bound(-a[i]);
		if (it != s.end()) {
			suf[i]++;
			s.erase(it);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, pre[i] + suf[i + 1]);
	}
	cout << ans << endl;
	return 0;
}
