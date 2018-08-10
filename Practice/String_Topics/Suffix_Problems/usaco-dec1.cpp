#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
using namespace std;
int N;
const int maxn = 2e5 + 10;
vector<string> v;
int ans[maxn];
class SuffixAutomaton {
public:
	struct node {
		node *fail, *ch[26];
		vector<node*> next;
		int mx;
		set<int> s;
		node(int a = 0) :mx(a), fail(NULL) {};
		~node() { delete fail; }
	}*start, *last, _pool[maxn << 1], *_cur;
	void init() {
		_cur = _pool;
		start = last = new (_cur++) node;
	}
	SuffixAutomaton() { init(); }
	static inline int idx(char c) { return c - 'a'; }
	void extend(char cha, int id) {
		int c = idx(cha);
		node *u = new (_cur++) node(last->mx + 1), *v = last;
		u->s.insert(id);
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
	void extend(string s, int id) {
		int n = s.size();
		for (int i = 0; i < n; i++) extend(s[i], id);
	}
	void recover() { last = start; }
	void addedge() {
		for (node *cur = _pool; cur != _cur; cur++) {
			if (cur->fail) {
				cur->fail->next.emplace_back(cur);
			}
		}
	}
	void update(node *cur) {
		for (auto v : cur->next) {
			update(v);
			for (auto it = v->s.begin(); it != v->s.end(); it++) {
				cur->s.insert(*it);
			}
		}
	}
	void get_ans() {
		for (node *v = _pool; v != _cur; v++) {
			if (v->fail) {
				if (v->s.size() == 1) {
					int id = *(v->s.begin());
					ans[id] += v->mx - v->fail->mx;
				}
			}
		}
	}

}*sa;

int main() {
	freopen("standingout.in", "r", stdin);
	freopen("standingout.out", "w", stdout);
	ios::sync_with_stdio(false);
	sa = new SuffixAutomaton();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		v.emplace_back(tmp);
		sa->extend(tmp, i);
		sa->recover();
	}
	sa->addedge();
	sa->update(sa->start);
	sa->get_ans();
	for (int i = 1; i <= N; i++) cout << ans[i] << endl;
	return 0;
}
