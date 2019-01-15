#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> S, ansS;
char SS[310000];
char ss[] = {'A', 'T', 'G', 'C'};
char s[2][2];
int ans;

void test(vector<string> &cur) {

	int tot = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cur[i][j] != S[i][j])
				tot++;
	if (tot < ans) {
		ans = tot;
		ansS = cur;
	}
}

void test(char s[2][2]) {
	vector <string> cur;
	for (int i = 0; i < n; i++) {
		string ss1, ss2;
		for (int j = 0; j < m; j++)
			ss1.push_back(s[i % 2][j % 2]), 
			ss2.push_back(s[i % 2][1 - j % 2]);
		int diff1 = 0, diff2 = 0;
		for (int j = 0; j < m; j++) {
			if (ss1[j] != S[i][j])
				diff1++;
			if (ss2[j] != S[i][j])
				diff2++;
		}
		if (diff1 < diff2)
			cur.push_back(ss1);
		else
			cur.push_back(ss2);
	}
	test(cur);
	vector <string> cur2;
	for (int i = 0; i < m; i++) {
		string ss1, ss2;
		for (int j = 0; j < n; j++)
			ss1.push_back(s[j % 2][i % 2]), 
			ss2.push_back(s[1 - j % 2][i % 2]);
		int diff1 = 0, diff2 = 0;
		for (int j = 0; j < n; j++) {
			if (ss1[j] != S[j][i])
				diff1++;
			if (ss2[j] != S[j][i])
				diff2++;
		}
		if (diff1 < diff2)
			cur2.push_back(ss1);
		else
			cur2.push_back(ss2);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cur[i][j] = cur2[j][i];
	test(cur);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", SS);
		S.push_back(string(SS));
	}
	ans = 1e9;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				for (int t = 0; t < 4; t++) {
					if (i != j && i != k && i != t && j != k && j != t && k != t) {
						s[0][0] = ss[i];
						s[0][1] = ss[j];
						s[1][0] = ss[k];
						s[1][1] = ss[t];
						test(s);
					}
				}
	// printf("?? %d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%s\n", ansS[i].c_str());

}
