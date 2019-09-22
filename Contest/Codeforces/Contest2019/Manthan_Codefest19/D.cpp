#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef long long ll;
const ll maxn = 2e5 + 10;
ll a[maxn], n, ans[maxn];
ll tree[maxn << 2], tag[maxn<<2];
 
void build(ll cur, ll l,ll r){
    if(l == r){
        tree[cur] = a[l];
        return;
    }
 
    ll mid = (l + r) >> 1;
    build(cur<<1,l,mid);
    build(cur<<1|1, mid + 1,r);
    tree[cur] = min(tree[cur<<1], tree[cur<<1|1]);
}
 
 
void push(ll cur){
    if(tag[cur]){
        tag[cur<<1] += tag[cur];
        tag[cur<<1|1] += tag[cur];
        tree[cur<<1] += tag[cur];
        tree[cur<<1|1] += tag[cur];
        tag[cur] = 0;
    }
}
 
void add(ll cur,ll l,ll r,ll a,ll b, ll x){
    if(a <= l && r <= b){
        tree[cur] += x;
        tag[cur] += x;
        return;
    }
    push(cur);
    ll mid = (l + r) >> 1;
    if(a <= mid) add(cur<<1, l,mid,a,b,x);
    if(b > mid) add(cur<<1|1, mid + 1,r, a, b, x);
    tree[cur] = min(tree[cur<<1],tree[cur<<1|1]);
}
 
ll moved(ll cur,ll l,ll r){
    if(l == r){
        return l;      
    }
    else{
        push(cur);
        ll mid = (l + r) / 2;
        ll res = -1;
        if(tree[cur<<1|1] == 0){
            res = moved(cur<<1|1,mid + 1,r);
        }
        else{
            res = moved(cur<<1,l, mid);
        }
        tree[cur] = min(tree[cur<<1], tree[cur<<1|1]);
        return res;
    }
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin>>n;
    for(ll i = 1; i <= n; i++) cin>>a[i];
    
    build(1,1,n);
 
    for(ll i = 1; i <= n; i++){
        ll pos = moved(1,1,n);
        ans[pos] = i;
        add(1,1,n,pos,pos,1e14l);
        add(1,1,n,pos,n,-i);
    }
 
    for(ll i = 1; i <= n; i++) cout<<ans[i]<<" ";
 
 
 
    return 0;
}
 