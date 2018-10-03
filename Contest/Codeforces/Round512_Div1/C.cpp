#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n,q,a[maxn],w[maxn];
ll seg1[maxn<<2],seg2[maxn<<2];
ll add(ll x,ll y){ return (x + y) % mod;}
ll mul(ll x,ll y){ return x * y % mod;}

ll norm(ll x){
	x %= mod;
	while(x < 0) x += mod;
	while(x >= mod) x -= mod;
	return x;
}

 void change1(int cur,int l,int r,int a,int b,ll delta){
	if(a <= l && r <= b) {
		seg1[cur] += delta;
		return;
	}
	int mid = l + r >> 1;
	if(a <= mid) change1(cur<<1,l, mid,a,b,delta);
	if(b > mid) change1(cur<<1|1,mid + 1,r,a,b,delta);
	seg1[cur] = seg1[cur<<1] + seg1[cur<<1|1];
}

void change2(int cur,int l,int r,int a,int b,ll delta){
	if(a <= l && r <= b) {
		seg2[cur] = add(seg2[cur],delta);
		return;
	}
	int mid = l + r >> 1;
	if(a <= mid) change2(cur<<1,l,mid,a,b,delta);
	if(b > mid) change2(cur<<1|1,mid + 1,r,a,b,delta);
	seg2[cur] = add(seg2[cur<<1],seg2[cur<<1|1]);
}

ll query1(int cur,int l,int r,int a,int b){
	if(a <= l && r <= b){
		return seg1[cur];
	}
	int mid = l + r >> 1;
	ll re = 0;
	if(a <= mid) re += query1(cur<<1,l,mid,a,b);
   	if(b > mid) re += query1(cur<<1|1,mid + 1,r,a,b);	
	return re;
}

ll query2(int cur,int l,int r,int a,int b){
	if(a <= l && r <= b){
		return seg2[cur];
	}
	int mid = l + r>> 1;
	ll re = 0;
	if(a <= mid) re = add(re,query2(cur<<1,l,mid,a,b));
	if(b > mid) re = add(re,query2(cur<<1|1,mid + 1,r,a,b));
	return re;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++) cin>>w[i];
	for(int i = 1;i <= n; i++){
		a[i] -= i;
		change1(1,1,n,i,i,w[i]);
		change2(1,1,n,i,i,mul(w[i],a[i]));
	}
	for(int i = 1; i <= q; i++){
		int x,y;
		cin>>x>>y;
		if(x < 0){
			x = -x;
			change1(1,1,n,x,x,-w[x]);
			change2(1,1,n,x,x,-mul(a[x],w[x]));
			w[x] = y;
			change1(1,1,n,x,x,w[x]);	
			change2(1,1,n,x,x,mul(a[x],w[x]));

		}
		else{
			int lo = x, hi = y;
			int an = x;
			ll tot = query1(1,1,n,x,y);
			while(lo <= hi){
				int mid = lo + hi >> 1;
				ll lft = query1(1,1,n,x,mid);
				if(lft >= (tot + 1) / 2) {
					an = mid;
					hi = mid - 1;
				}
				else lo = mid + 1;	
			}	
			ll ans = query2(1,1,n,an,y) - (query1(1,1,n,an,y) % mod) * a[an] % mod - query2(1,1,n,x,an) + (query1(1,1,n,x,an) % mod) * a[an] % mod;
			ans = (ans % mod + mod) % mod;
			cout<<ans<<endl;
		}
	}
	return 0;
}
