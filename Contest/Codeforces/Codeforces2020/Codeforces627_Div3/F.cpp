#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
constexpr int maxn = 2e5 + 10;
typedef pair<int,int> pii;
vector<pii> G[maxn];
int n;
int col[maxn], black[maxn],white[maxn];
int ans[maxn], temp[maxn];

void solve(int u, int fa){
    ans[u] += col[u];
    for(auto& v : G[u]){
        if(v.first == fa) continue;
        solve(v.first, u);
        v.second = ans[v.first];
        ans[u] += (ans[v.first] > 0 ? ans[v.first] : 0);
    }
}

void solve1(int u,int fa, int val){
    int x = -9999999;
    if(ans[fa] > 0) {
        x = ans[fa];
        if(val > 0) x -= val;
    }
    ans[u] = max(ans[u], max(x + col[u], ans[u] + x));
    for(auto v : G[u]){
        if(v.first == fa) continue;
        solve1(v.first, u, v.second);
    }
}

int main()
{
    FAST_IO;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>col[i];
        if(!col[i]) col[i]--;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        G[u].emplace_back(make_pair(v,0));
        G[v].emplace_back(make_pair(u,0));
    }
    solve(1, 0);
    solve1(1, 0, 0);
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

