#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
typedef long long ll;
const ll maxn = 3005;
ll parent[maxn][maxn], sz[maxn][maxn];
ll f[maxn][maxn];
vector<ll> G[maxn];
ll rt;

void dfs(ll u,ll fa){
	parent[rt][u] = fa;
	sz[rt][u] = 1;
	for(ll nxt: G[u]){
		if(nxt != fa){
			dfs(nxt, u);
			sz[rt][u] += sz[rt][nxt];
		}
	}
}

ll dp(ll u,ll v){
	if(u == v) return 0;
	if(f[u][v]) return f[u][v];
	return f[u][v] = max(dp(u, parent[u][v]), dp(v, parent[v][u])) + sz[u][v] * sz[v][u];
}


int main(){
	ll n;
	cin>>n;
	for(ll i = 1; i < n; i++){
		ll u,v;
		cin>>u>>v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	for(ll i = 1; i <= n; i++){
		rt = i;
		dfs(rt, rt);
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			ans = max(ans, dp(i, j));
		}
	}
	cout<<ans<<endl;
	return 0;
}
