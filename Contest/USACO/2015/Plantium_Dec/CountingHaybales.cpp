#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long tree[maxn<<2],mn[maxn<<2],tag[maxn<<2];
int n,q,a[maxn];
void maintain(int cur){
    tree[cur] = tree[cur<<1] + tree[cur<<1|1];
    mn[cur] = min(mn[cur<<1], mn[cur<<1|1]);
}
void build(int cur,int l,int r){
    if(l == r) {
        mn[cur] = tree[cur] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(cur<<1,l,mid);
    build(cur<<1|1,mid + 1,r);
    maintain(cur);
}

void pushdown(int cur,int l,int r){
    if(tag[cur]){
        int mid = l + r >> 1;
        tree[cur<<1] += (mid - l + 1) * tag[cur];
        tree[cur<<1|1] += (r - mid) * tag[cur];
        mn[cur<<1] += tag[cur];
        mn[cur<<1|1] += tag[cur];
        tag[cur<<1] += tag[cur];
        tag[cur<<1|1] += tag[cur];
        tag[cur] = 0;
    }
}

void change(int cur,int l,int r,int a,int b,long long delta){
    if(a <= l && r <= b){
        tag[cur] += delta;
        mn[cur] += delta;
        tree[cur] += delta * (long long)(r - l + 1);
        return;
    }
    pushdown(cur,l,r);
    int mid = l + r >> 1;
    if(a <= mid) change(cur<<1,l,mid,a,b,delta);
    if(b > mid) change(cur<<1|1,mid + 1,r,a,b,delta);
    maintain(cur);
}

long long query_sum(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        return tree[cur];
    }
    long long re = 0;
    pushdown(cur,l,r);
    int mid = l + r >> 1;
    if(a <= mid) re += query_sum(cur<<1,l,mid,a,b);
    if(b > mid) re += query_sum(cur<<1|1,mid + 1,r,a,b);
    maintain(cur);
    return re;
}


long long query_min(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        return mn[cur];
    }
    long long re = 1e10;
    int mid = l + r >> 1;
    pushdown(cur,l,r);
    if(a <= mid) re = min(re,query_min(cur<<1,l,mid,a,b));
    if(b > mid) re = min(re,query_min(cur<<1|1,mid + 1,r,a,b));
    return re;
}

int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1,1,n);
    for(int i = 1; i <= q; i++){
        string opt;
        cin>>opt;
        int u,v;
        cin>>u>>v;
        if(opt[0] == 'M'){
            cout<<query_min(1,1,n,u,v)<<endl;
        }
        else if(opt[0] == 'S'){
            cout<<query_sum(1,1,n,u,v)<<endl;
        }
        else{
            long long val;
            cin>>val;
            change(1,1,n,u,v,val);
        }
    }
    return 0;
}
