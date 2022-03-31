#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <limits.h>
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
char str[maxn];
int wa[maxn],wb[maxn],wss[maxn],wv[maxn],rnk[maxn],sa[maxn],height[maxn],s[maxn];
//int ST[maxn][20];
int tree[maxn<<2];



bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void build_sa(int *r,int *sa,int n,int m){
	int i,j,p,*x = wa,*y = wb;
	for(i = 0; i < m; i++) wss[i] = 0;
	for(i = 0; i < n; i++) wss[x[i] = r[i]]++;
	for(i = 1; i < m ;i++) wss[i] += wss[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
	for(j = 1,p = 1; p < n; j <<= 1,m = p){
		for(p = 0,i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; i++) wss[i] = 0;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < n; i++) wss[wv[i]]++;
		for(i = 1; i < m; i++) wss[i] += wss[i - 1];
		for(i = n - 1; i >= 0 ;i--) sa[--wss[wv[i]]] = y[i];
		swap(x,y);
		for(p = 1, i = 1, x[sa[0]] = 0; i < n; i++){
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1  : p++;
		}
	}
}

void get_height(int *r,int n){
	int i,j,k = 0;
	for(i = 1; i <= n; i++) rnk[sa[i]] = i;
	for(i = 0; i < n; height[rnk[i++]] = k){
		for(k ? k -- : 0,j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
	}
}

/*void build_st(int n){
	for(int i = 2; i <= n; i++){
		ST[i][0] = height[i];
	}
	for(int j = 1; (1 << j) <= n; j++){
		for(int i = 1; i + (1 << j) <= n; i++){
			ST[i][j] = min(ST[i][j - 1],ST[i + (1<<(j - 1))][j - 1]);
		}
	}
}
int query(int l,int r){
	if(l > r) swap(l,r);
	l++;
	if(l == r) return height[l];
	int k = (int)log2(r - l);
	return min(ST[l][k],ST[r - (1<<k) + 1][k]);
}
*/
void build(int cur,int l,int r){
	if(l == r){
		tree[cur] = height[l];
		return;
	}
	int mid = (l + r) / 2;
	build(cur<<1,l,mid);
	build(cur<<1|1,mid + 1,r);
	tree[cur] = min(tree[cur<<1],tree[cur<<1|1]);
}
int query(int cur,int l,int r,int a,int b){
	if(a <= l && r <= b){
		return tree[cur];
	}
	int ans = INT_MAX;
	int mid = l + r >> 1;
	if(a <= mid) ans = min(ans,query(cur<<1,l,mid,a,b));
	if(b > mid) ans = min(ans,query(cur<<1|1,mid + 1,r,a,b));
	return ans;
}
int main(){
	while(scanf("%s",str)){
		if(str[0] == ',') break;
		int n = strlen(str);
		s[n] = 0;
		//memset(ST,127,sizeof(ST));
		for(int i = 0; i < n; i++) s[i] = str[i] - 'a' + 1;
		build_sa(s,sa,n + 1,30);
		get_height(s,n);
		int ans = 0;
		//build_st(n);
		build(1,1,n);
		for(int len = 1; len <= n / 2; len++){
			if(n % len == 0){
				int lcp = INT_MAX;
				for(int i = 0; i + len < n; i += len){
					int l = rnk[i],r = rnk[i + len];
					if(l > r) swap(l,r);
					l++;
					lcp = min(lcp,query(1,1,n,l,r));
				}
				if(lcp == len) {
					ans = len;
					break;
				}
			}
		}
		if(ans == 0) printf("1");
		else printf("%d",n / ans);
		puts("");
	}
	return 0;
}


