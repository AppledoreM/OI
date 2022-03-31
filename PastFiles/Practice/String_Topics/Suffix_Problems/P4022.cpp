#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 2e6 + 10;
int N, M;
string s;
int mxlen[maxn], f[maxn], q[maxn];
class SuffixAutomaton {
public:
	struct node {
		node *fail, *ch[3];
		int mx;
		~node() { delete fail; }
		node(int a = 0) :mx(a), fail(NULL) {}
	}*start, *last, _pool[maxn << 1], *_cur;
	void init() {
		_cur = _pool;
		start = last = new (_cur++) node;
	}
	SuffixAutomaton() {
		init();
	}
	static inline int idx(char c) { return c - '0'; }
	void recover() { last = start; }
	void extend(char cha) {
		int c = idx(cha);
		node *u = new (_cur++) node(last->mx + 1), *v = last;
		for (; v && !v->ch[c]; v = v->fail) v->ch[c] = u;
		if (!v) {
			u->fail = start;
		}
		else if (v->ch[c]->mx == v->mx + 1) {
			u->fail = v->ch[c];
		}
		else {
			node *n = new (_cur++) node(v->mx + 1), *o = v->ch[c];
			memcpy(n->ch, o->ch, sizeof(o->ch));
			n->fail = o->fail;
			o->fail = u->fail = n;
			for (; v && v->ch[c] == o; v = v->fail) v->ch[c] = n;
		}
		last = u;
	}
	void extend(string s) {
		int n = s.size();
		for (int i = 0; i < n; i++) extend(s[i]);
	}
	void get_ans(string s) {
		node *cur = start;
		int len = 0;
		for (int i = 0; i < s.size(); i++) {
			int c = idx(s[i]);
			if (cur->ch[c]) {
				len++;
				cur = cur->ch[c];
			}
			else {
				for (; cur && !cur->ch[c]; cur = cur->fail);
				if (!cur) {
					cur = start;
					len = 0;
				}
				else {
					len = cur->mx + 1;
					cur = cur->ch[c];
				}
			}
			mxlen[i + 1] = len;
		}
	}
}*sa;


bool okay(int L) {
	int n = s.size();
	f[0] = q[0] = 0;
	int head, tail;
	head = 1, tail = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		int j = i - L;
		if (j >= 0) {
			while (head <= tail && f[j] - j > f[q[tail]] - q[tail]) tail--;
			q[++tail] = j;
		}
		while (head <= tail && q[head] < i - mxlen[i]) head++;
		if (head <= tail) f[i] = max(f[i], f[q[head]] + i - q[head]);
	}
	return 10 * f[n] >= 9 * n;
}

int main() {
	ios::sync_with_stdio(false);
	sa = new SuffixAutomaton();
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		sa->extend(s);
		sa->recover();
	}
	for (int i = 1; i <= N; i++) {
		cin >> s;
		sa->get_ans(s);
		int lo = 1, hi = s.size(), ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (okay(mid)) {
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}