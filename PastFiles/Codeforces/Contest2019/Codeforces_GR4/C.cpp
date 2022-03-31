#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int maxn = 1005;
constexpr ll mod = 998244353;
int n,m;
ll dp[maxn][maxn][4];
queue<pii> q;
bool vis[maxn][maxn];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;

    ll ans = 1;
    for(int i = 1; i <= n + m; i++){
        ans = (ans * 2) % mod;
    }

    cout<<ans<<endl;





    return 0;
}