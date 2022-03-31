#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
int n,w;
int trees[maxn][23],vecs[maxn];
int lg[maxn];
ll ans_lis[maxn], rsum[maxn];
 
 
void build(int sz){
    for(int i = 1;  i <= 20; i++){
        for(int j = 1; j <= sz; j++){
            trees[j][i] = max(trees[j][i - 1], trees[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int query(int l,int r){
    int k = lg[r - l + 1];
    return max(trees[l][k], trees[r - (1 << k) + 1][k]);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>w;
    for(int i = 2; i <= 1000000; i++) lg[i] = lg[i >> 1] + 1;
 
    for(int j = 1; j <= n; j++){
        int x;
        cin>>x;
        for(int i = 1; i <= x; i++) cin>>trees[i][0]; 
        build(x);
        if(x * 2 >= w){
            for(int i = 1; i <= w; i++){
                int sz = x;
                int mx = -1e9;
                int ed = min(i, x);
                int st = max(1, x - (w - i));
                mx = query(st, ed); 
                if(mx < 0){
                    if(i > sz || w - i >= sz); 
                    else ans_lis[i] += (ll) mx;
                }
                else ans_lis[i] += (ll) mx;
            }
        }
        else{
            int v1 = 0, v2 = 0;
            for(int i = 1; i <= x; i++){
                v1 = max(v1, trees[i][0]);
                v2 = max(v2, trees[x - i + 1][0]);
                ans_lis[i] += (ll) v1;
                ans_lis[w - i + 1] += (ll) v2;
            }
            rsum[x + 1] += (ll) v1;
            rsum[w - x + 1] -= (ll) v1;
        }
 
    }
 
    for(int i = 1; i <= w; i++) rsum[i] += rsum[i - 1];
    for(int i = 1; i <= w; i++) cout<<ans_lis[i] + rsum[i]<<" ";
 
 
 
    return 0;
}