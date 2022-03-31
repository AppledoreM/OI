#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int maxn = 500005;
vector<int> tree[maxn];
int sz[maxn];
ll dp[maxn];
pll que[maxn];
long long ans = 0;
int n;

ll calc(pll a, ll b){
    return a.first * b + a.second;
}

void dfs(int u,int fa){
    sz[u] = 1;
    vector<pii> ch_sz;
    for(int i = 0; i < (int) tree[u].size(); i++){
        int nxt = tree[u][i];
        if(nxt == fa) continue;
        dfs(nxt, u);
        sz[u] += sz[nxt];
        ch_sz.emplace_back(pii(sz[nxt],nxt));
    }

    if(sz[u] == 1){
        dp[u] = 1;
        return;
    }
    dp[u] = 1ll * n * n;

    for(int i = 0; i < (int) tree[u].size(); i++){
        int v = tree[u][i];
        if(v == fa) continue;
        dp[u] = min(dp[u], dp[v] + 1ll * (sz[u] - sz[v]) * (sz[u] - sz[v]));
    }


    sort(ch_sz.begin(), ch_sz.end());

    int top = 0;
    que[++top] = pll(2ll * ch_sz[0].first, dp[ch_sz[0].second] - 2ll * n * ch_sz[0].first + 1ll * ch_sz[0].first * ch_sz[0].first);
    for(int i = 1; i < (int) ch_sz.size(); i++){
        while(top && calc(que[top - 1], ch_sz[i].first) < calc(que[top], ch_sz[i].first)) top--;
        ans = min(ans, calc(que[top], ch_sz[i].first) + dp[ch_sz[i].second] - 2ll * n * ch_sz[i].first + 1ll * ch_sz[i].first * ch_sz[i].first + 1ll * n * n);
        que[++top] = pll(2ll * ch_sz[i].first, dp[ch_sz[i].second] - 2ll * n * ch_sz[i].first + 1ll * ch_sz[i].first * ch_sz[i].first);
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
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    if(n == 2){
        cout<<2<<endl;
        exit(0);
    }

    int root = 0;
    for(int i = 1; i <= n; i++){
        if((int) tree[i].size() > 1) {
            root = i;
            break;
        }
    }
    ans = 1ll * n * n;
    dfs(root, 0);
    ans = 1ll * n * n + 1ll * n * (n - 1) - ans;
    ans /= 2;

    cout<<ans<<endl;



    return 0;
}

