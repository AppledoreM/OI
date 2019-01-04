#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1e4 + 10;
int N,K,dp[maxn],tree[maxn];
int a[maxn];
void build(int cur,int l,int r){
    if(l == r){
        tree[cur] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(cur<<1,l,mid);
    build(cur<<1|1,mid + 1,r);
    tree[cur] = max(tree[cur<<1],tree[cur<<1|1]);
}

int query_mx(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        return tree[cur];
    }
    int ans = 0;
    int mid = (l + r) >> 1;
    if(a <= mid) ans = max(ans,query_mx(cur<<1,l,mid,a,b));
    if(b > mid) ans = max(ans,query_mx(cur<<1|1,mid + 1,r,a,b));
    return ans;
}

int main()
{
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    FAST_IO;
    cin>>N>>K;
    for(int i = 1; i <= N; i++) cin>>a[i];
    build(1,1,N);
    for(int i = 1; i <= N; i++){
        for(int j = max(1, i - K + 1); j <= i; j++){
            dp[i] = max(dp[i],query_mx(1,1,N,j,i) * (i - j + 1) + dp[j - 1]);
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}

