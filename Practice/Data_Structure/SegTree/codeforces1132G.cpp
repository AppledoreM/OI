#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1e6 + 10;

int n,k;
int a[maxn], tree[maxn<<2], dep[maxn];
vector<int> G[maxn];


// Segment Tree
void build1(int cur,int l, int r){
    int mid = (l + r) >> 1;
    if(l == r){
        tree[cur] = a[l];
        return;
    }

    build1(cur<<1,l,mid);
    build1(cur<<1|1, mid + 1, r);
}


int query_mx(int cur,int l,int r,int a,int b){
    if(a > b) return 0;
    if(a <= l && r <= b){
        return tree[cur];
    }

    int mid = (l + r) >> 1;
    int re = 0;
    if(a <= mid) re = max(re, query_mx(cur<<1,l,mid,a,b));
    if(b > mid) re = max(re, query_mx(cur<<1|1,mid + 1,r,a,b));
    return re;
}


void query_fill(int cur,int l,int r,int a,int b,int delta){
    if(a <= l && r <= b){
        tree[cur] = max(tree[cur], delta);
        return ;
    }

    int mid = (l + r) >> 1;
    if(a <= mid) query_fill(cur<<1,l,mid,a,b,delta);
    if(b > mid) query_fill(cur<<1|1,mid + 1,r,a,b,delta);

    tree[cur] = max(tree[cur<<1], tree[cur<<1|1]);
}

void dfs(int cur, vector<int> node){
    int lo = 0, hi = (int) node.size();
    for(int i = 0; i < hi)

}


int main()
{

    FAST_IO;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i];

    build1(1,1,n);
    for(int i = 1; i <= n; i++){
        int lo = i + 1, hi = n;
        int ans = 0;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(query_mx(1,1,n,i + 1,mid) > a[i]){
                hi = mid - 1;
                ans = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        if(ans){
            G[i].emplace_back(ans);
        }
    }






    return 0;
}

