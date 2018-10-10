#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 +10;
typedef long long ll;
int n,q,a[maxn],w[maxn];
const int mod = 1e9 + 7;
vector<ll> seg1,seg2;

void init(int n){
    seg1.resize(n + 1);
    seg2.resize(n + 1);
}

void add(ll &x, ll y){
    x = (x + y) % mod;
}

void mul(ll &x, ll y){
    x = (x * y) % mod;
}


void modify1(int cur,int l,int r,int a,int b,ll delta){
    if(a <= l && r <= b){
        seg1[cur] = delta;
        return;
    }
    int mid = l + r >> 1;
    if(a <= mid) modify1(cur<<1,l,mid,a,b,delta);
    if(b > mid) modify1(cur<<1|1,mid + 1,r,a,b,delta);
    seg1[cur] = seg1[cur<<1] + seg1[cur<<1|1];
}

void modify2(int cur,int l,int r,int a,int b,ll delta){
    if(a <= l && r <= b){
        seg2[cur] = delta;
        return;
    }
    int mid = l + r >> 1;
    if(a <= mid) modify1(cur<<1,l,mid,a,b,delta);
    if(b > mid) modify1(cur<<1|1,mid + 1,r,a,b,delta);
    add(seg2[cur],(seg2[cur<<1] + seg2[cur<<1|1]) % mod);
}

ll query_sum1(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        return seg1[cur];
    }
    int mid = l + r >> 1;
    ll re = 0;
    if(a <= mid) re += query_sum1(cur<<1,l,mid,a,b);
    if(b > mid) re += query_sum1(cur<<1|1,mid + 1,r,a,b);
    return re;
}

ll query_sum2(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        return seg2[cur];
    }
    ll re = 0;
    int mid = l + r >> 1;
    if(a <= mid) add(re,query_sum2(cur<<1,l,mid,a,b));
    if(b > mid) add(re,query_sum2(cur<<1|1,mid + 1,r,a,b));
    return re % mod;;
}

int query_pos(int cur,int l,int r,int a,int b,ll val){
    if(l == r) return l;
    int mid = l + r >> 1;
    if(a <= mid) return query_pos(cur<<1,l,mid,a,b,val);
    if(b > mid) return query_pos(cur<<1|1,mid + 1,r,a,b,val);
    ll s = query_sum1(1,1,n,l,mid);
    if(s >= val) return query_pos(cur<<1,l,mid,a,mid,val);
    else return query_pos(cur<<1|1,mid + 1,r,mid + 1,b,val - s);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    init(n);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 1; i <= n; i++){
        a[i] -= i;
        modify1(1,1,n,i,i,w[i]);
        modify2(1,1,n,i,i,(a[i] * w[i]) % mod);
    }
    for(int i = 1; i <= q; i++){
        int x,y;
        cin>>x>>y;
        if(x < 0){
            x = -x;
            w[x] = y;
            modify1(1,1,n,x,x,y);
            modify2(1,1,n,x,x,(a[x] * y) % mod);
        }
        else{
            ll sum1 = query_sum1(1,1,n,x,y);
            int pos = query_pos(1,1,n,x,y,(sum1 + 1) / 2);
            ll ans = 0;
            ans = (ans + a[pos] * (query_sum1(1,1,n,x,pos) - query_sum1(1,1,n,pos,y))% mod) % mod;
            ans = (ans - query_sum2(1,1,n,x,pos) + query_sum2(1,1,n,pos,y)) % mod;
            cout<<ans<<endl;
        }
    }


    return 0;
}
