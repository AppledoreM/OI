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
const int maxn = 1e5 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
int T,N;
int s[maxn],wa[maxn],wb[maxn],wss[maxn],wv[maxn],rnk[maxn],sa[maxn],height[maxn];
int ST[maxn][20];
inline int idx(char c) {return c - 'a' + 1;}

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void build_sa(int n,int m){
	int i,j,p,*x = wa,*y = wb;
	for(i = 0; i < m; i++) wss[i] = 0;
	for(i = 0; i < n; i++) wss[x[i] = s[i]]++;
	for(i = 1; i < m; i++) wss[i] += wss[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
	for(j = 1,p = 1; p < n; j <<= 1, m= p){
		for(p = 0,i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; i++) wss[i] = 0;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < n ;i++) wss[wv[i]]++;
		for(i = 1; i < m; i++) wss[i] += wss[i - 1];
		for(i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
		swap(x,y);
		for(i = 1,p = 1,x[sa[0]] = 0; i < n; i++){
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1 : p++;
		}
	}
}

void get_height(int n){
	int i,j,k = 0;
	for(i = 1; i <= n; i++) rnk[sa[i]] = i;
	for(i = 0; i < n; height[rnk[i++]] = k){
		for(k ? k-- : 0, j = sa[rnk[i] - 1]; s[i + k] == s[j + k]; k++);
	}
}

void build_st(){
	for(int i = 1; i <= N; i++) ST[i][0] = height[i];
	for(int j = 1; j <= 19; j++){
		for(int i = 1; i + (1 << j) - 1 <= N; i++){
			ST[i][j] = mymin(ST[i][j - 1],ST[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l,int r){
	if(l == r) return height[l];
	int k = (int)log2(r - l + 1);
	return mymin(ST[l][k],ST[r - (1 << k) + 1][k]);
}

int main(){
	FAST_IO
	cin>>T;
	while(T--){
		cin>>N;
		for(int i = 0; i < N; i++) {
			char ch;
			cin>>ch;
			s[i] = idx(ch);
		}
		s[N] = 0;
		build_sa(N + 1,30);
		get_height(N);
		build_st();
		int ans = 0;
		for(int len = 1; len <= N; len++){
			for(int j = 0; j + len < N; j++){
				int l = rnk[j],r = rnk[j + len];
				if(l > r) swap(l,r); l++;
				int tmp = query(l,r);
				int pre = j - (len - tmp % len);
				if(pre >= 0 && query(pre,pre + len) >= len) tmp += len;
				ans = mymax(ans, tmp / len + 1);	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

