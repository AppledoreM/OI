#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,dp[1005][12];
pii a[1005];

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int c;
        cin>>c;
        string s;
        cin>>s;
        int b = 0;
        for(int j = 0; j < s.size(); j++){
            b |= 1 << (s[j] - 'A');
        }
        a[i] = pii(c,b);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int val = a[i].first;
        int comb = a[i].second;
        for(int j = 0; j < 8; j++) dp[i][j] = dp[i - 1][j];
        for(int j = 0; j < 8; j++){
            dp[i][j | comb] = min(dp[i][j | comb], dp[i - 1][j] + val) ;
        }
    }

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) ans = min(ans, dp[i][7]);
    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
