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
int wa[maxn],wb[maxn],wss[maxn],wv[maxn],rnk[maxn],height[maxn],sa[maxn],s[maxn];
string s1,s2;

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void build_sa(int *r,int *sa,int n,int m){
	int i,j,p,*x = wa,*y = wb;
	for(i = 0; i < m; i++) wss[i] = 0 ;
	for(i = 0; i < n; i++) wss[x[i] = r[i]]++;
	for(i = 1; i < m; i++) wss[i] += wss[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
	for(p = 1,j = 1; p < n; j *= 2, m = p){
		for(p = 0,i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; i++) wss[i] = 0;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < n ;i++) wss[wv[i]]++;
		for(i = 1; i < m; i++) wss[i] += wss[i - 1];
		for(i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
		swap(x,y);
		for(x[sa[0]] = 0,i = 1,p = 1; i < n; i++){
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1 : p++;
		}
	}
}
void get_height(int *r,int n){
	int i,j,k = 0;
	for(i = 1; i <= n ;i++) rnk[sa[i]] = i;
	for(i = 0 ;i < n; height[rnk[i++]] = k){
		for(k ? k-- : 0,j = sa[rnk[i] - 1]; r[j + k] == r[i + k]; k++);
	}
}


int main(){
	FAST_IO
	cin>>s1>>s2;
	int sz1 = s1.size();
	s1 += "$" + s2;
	for(int i = 0; i < s1.size(); i++){
		if('a' <= s1[i] && s1[i] <= 'z') s[i] = s1[i] - 'a' + 1;
		else s[i] = 28;
	}
	build_sa(s,sa,s1.size() + 1,30);
	get_height(s,s1.size());
	int ans = 0;
	for(int i = 2; i <= s1.size(); i++){
		if((sa[i] <= sz1) ^ (sa[i - 1] <= sz1)) ans = max(ans,height[i]);
	}
	cout<<ans<<endl;
	return 0;
}

