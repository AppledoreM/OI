#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 1e6 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
int N,K;
int s[maxn],wa[maxn],wb[maxn],wss[maxn],wv[maxn],rnk[maxn],height[maxn],sa[maxn];
bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void build_sa(int *r,int *sa,int n,int m){
	int i,j,p,*x = wa,*y = wb;
	for(i = 0; i < n; i++) wss[x[i] = r[i]]++;
	for(i = 1; i < m; i++) wss[i] += wss[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
	for(j = 1,p = 1; p < n; j <<= 1,m = p){
		for(p = 0,i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0;i < m; i++) wss[i] = 0;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < n; i++) wss[wv[i]]++;
		for(i = 1; i < m; i++) wss[i] += wss[i - 1];
		for(i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
		swap(x,y);
		for(p = 1,i = 1,x[sa[0]] = 0; i < n; i++){
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1: p++;
		}
	}
}

void get_height(int *r,int n){
	int i,j,k = 0;
	for(i = 1; i <= n;i ++) rnk[sa[i]] = i;
	for(i = 0; i < n; height[rnk[i++]] = k){
		for(k ? k-- : 0,j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
	}
}

bool ok(int len){
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		if(height[i] >= len) cnt++;
		else cnt = 1;
		if(cnt >= K) return true;
	}
	return false;
}
int main(){
	FAST_IO
	cin>>N>>K;
	int m = 0;
	for(int i = 0; i < N; i++) {
		cin>>s[i];
		m = max(m,s[i] + 1);
	}
	build_sa(s,sa,N + 1,m);
	get_height(s,N);
	int lo = 0,hi = N;
	int ans = 0;
	while(lo <= hi){
		int mid = lo + hi >> 1;
		if(ok(mid)){
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout<<ans<<endl;
	return 0;
}

