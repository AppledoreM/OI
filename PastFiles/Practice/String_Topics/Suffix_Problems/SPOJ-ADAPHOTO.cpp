#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
string str1,str2;
const int maxn = 2e6 + 10;
int wa[maxn],wb[maxn],wv[maxn],wss[maxn];
int s[maxn],sa[maxn],height[maxn],rnk[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void build(int *r,int *sa,int n,int m){
    int i,j,*x = wa,*y = wb,*t,p;
    for(i = 0; i < m; i++) wss[i] = 0;
    for(i = 0; i < n; i++) wss[x[i] = r[i]]++;
    for(i = 1; i < m; i++) wss[i] += wss[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < m; i++) wss[i] = 0;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < n; i++) wss[wv[i]]++;
        for(i = 1; i < m; i++) wss[i] += wss[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1,x[sa[0]] = 0,i = 1; i < n; i++){
            x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1 : p++;
        }
    }
}

void cal_height(int *r,int *sa,int n){
    int i,j,k = 0;
    for(i=1; i<=n; i++) rnk[sa[i]]=i;
    for(i=0; i<n; height[rnk[i++]]=k){
        for(k?k--:0,j=sa[rnk[i]-1]; r[i+k]==r[j+k]; k++);
    }
}

bool okay(int a,int b,int sz){
    return a < sz && sz < b;
}
void clean(){
    memset(wa,0,sizeof(wa));
    memset(wb,0,sizeof(wb));
    memset(wv,0,sizeof(wv));
    memset(wss,0,sizeof(wss));
    memset(s,0,sizeof(s));
    memset(height,0,sizeof(height));
    memset(sa,0,sizeof(sa));
    memset(rnk,0,sizeof(rnk));
}
int main(){
	ios::sync_with_stdio(false);
    cin>>str1>>str2;
    int m = 10;
    clean();
    int sz = str1.size();
    str1 = str1 + "$" + str2;
    int n = str1.size();
    for(int i = 0; i < str1.size(); i++) { 
        if(str1[i] == '^'){
			s[i] = 1;
		}
		else if(str1[i] == '~'){
			s[i] = 2;
		}
		else if(str1[i] == 'v'){
			s[i] = 3;
		}
		else if(str1[i] == '-'){
			s[i] = 4;
		}
		else s[i] = 6;
    }
    build(s,sa,n + 1,m);
    cal_height(s,sa,n);
    int ans = 0;
    for(int i = 1; i <= str1.size(); i++){
        if(okay(sa[i - 1],sa[i],sz) || okay(sa[i],sa[i - 1],sz)) ans = max(ans,height[i]);
    }
    cout<<ans<<endl;
    return 0;
}
