#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int s[maxn],wa[maxn],wb[maxn],wss[maxn],wv[maxn],height[maxn],rnk[maxn],sa[maxn];

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void build_sa(int *r,int *sa,int n,int m){
	int i,j,p,*x = wa,*y = wb;
	for(i = 0; i < m; i++) wss[i] = 0;
	for(i = 0; i < n; i++) wss[x[i] = r[i]]++;
	for(i = 1; i < m; i++) wss[i] += wss[i - 1];
	for(i = n - 1; i >= 0; i--) sa[-wss[x[i]]] = i;
	for(j = 1,p = 1; p < n; j <<= 1,m = p){
		for(p = 0,i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; i++) wss[i] = 0;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < n; i++) wss[wv[i]]++;
		for(i = 1; i < m; i++) wss[i] += wss[i - 1];
		for(i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
		swap(x,y);
		for(i = 1,p = 1,x[sa[0]] = 0; i < n; i++){
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1: p++;
		}
	}
}

void get_height(int *r,int n){
	int i,j,k = 0;
	for(i = 1; i <= n; i++) rnk[sa[i]] = i;
	for(i = 0; i < n; height[rnk[i++]] = k){
		for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[a + k] == r[b + k]; k++);
	}
}
