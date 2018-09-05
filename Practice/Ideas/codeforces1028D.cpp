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
const int maxn = 4e5 + 10;
typedef pair<int, int> pii;
int n, tree[maxn << 2], tag[maxn << 2], tot, L, H;
const int mod = 1e9 + 7;
set<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int ans = 1;
	st.insert(-1e9);
	st.insert(1e9);
	L = -1e9;
	H = 1e9;
	int wt = 1;
	for (int i = 1; i <= n; i++) {
		string s;
		int num;
		cin >> s >> num;
		if (s[1] == 'D') {
			st.insert(num);
			if (num > L && num < H) wt++;
		}
		else {
			if (num < L || num > H) {
				cout << 0 << endl;
				return 0;
			}
			if (num != L && num != H) {
				ans = ans * 2 % mod;
			}
			wt = 1;
			st.erase(num);
			auto it = st.lower_bound(num);
			H = (*it);
			L = *(--it);
		}
	}
	cout << (long long) wt * ans % mod<<endl;
	return 0;
}
