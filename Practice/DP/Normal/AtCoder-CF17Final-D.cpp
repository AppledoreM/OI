#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 5000 + 10;
int n;
long long dp[maxn][maxn];
vector<pii> v;


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin() + 1,v.end(), [](auto x,auto y){ return x.first + x.second < y.first + y.second;});
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i < (int) v.size(); i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i - 1][j];
            if(dp[i - 1][j - 1] <= v[i].first) dp[i][j] = min(dp[i - 1][j - 1] + v[i].second,dp[i][j]); 
        }
    }
    int ans = 0;
    for(int i = 1; i < (int) v.size(); i++){
        if(dp[n][i] != dp[1][0]) ans = i;
    }
    cout<<ans<<endl;
    
    return 0;
}

