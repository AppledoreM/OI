#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
typedef pair<int,int> pii;
ll n,L,S,w[maxn],fa[maxn],lca[maxn][20],dep[maxn],top[maxn],use[maxn],ans;
ll sum[maxn];
vector<int> G[maxn];

void dfs1(int u){
	sum[u] = sum[fa[u]] + w[u];
	dep[u] = dep[fa[u]] + 1;
	int dis = L;
	top[u] = u;
	for(int k = 20; k >= 0; k--){
		int f = lca[top[u]][k];
		if(!f || (1 << k) >= dis) continue;
		if(sum[u] - sum[f] + w[f] > S) continue;
		dis -= (1 << k);
		top[u] = f;
	}
	for(int v: G[u]) dfs1(v);
}

void dfs2(int u){
	int best = -1;
	for(int v : G[u]){
		dfs2(v);
		if(use[v] == v) continue;
		if(best == -1 || dep[best] > dep[use[v]]) best = use[v];
	}
	if(best == -1) {
		best = top[u];
		ans++;
	}
	use[u] = best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>L>>S;
    for(int i = 1; i <= n; i++) {
		cin>>w[i];
		if(w[i] > S) {
			cout<<-1<<endl;
			exit(0);
		}
	}
    for(int i = 2; i <= n; i++){
        cin>>fa[i];
        G[fa[i]].emplace_back(i);
		lca[i][0] = fa[i];
    }
	for(int i = 1; (1 << i) <= n; i++){
		for(int j = 1; j <= n; j++){
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
		}
	}
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl;
    return 0;
}
