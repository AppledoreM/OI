#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 2e5 + 10; 
typedef long long ll;
ll n, dp[maxn][2], sz[maxn];
vector<int> G[maxn];

void dfs1(int u,int fa){
    sz[u] = 1;
    for(int x : G[u]){
        if(x == fa) continue;
        dfs1(x,u);
        sz[u] += sz[x];
    }
    for(int x: G[u]){
        if(x == fa) continue;
        dp[u][0] += dp[x][0];
    }
    dp[u][0] += sz[u];
}


void dfs2(int u,int fa){

    for(int x : G[u]){
        if(x == fa) continue;
        dp[x][1] = dp[u][1] + n - 2 * sz[x];
        dfs2(x,u);
    }
}
int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(1,0);
    dp[1][1] = dp[1][0];
    dfs2(1,0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i][1]);
    }
    cout<<ans<<endl;


    return 0;
}

