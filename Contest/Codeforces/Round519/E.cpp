#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
const int maxn = 3e5 + 10;
typedef pair<int,int> pii;
int n,m;
int x[maxn],y[maxn],u[maxn],v[maxn];
struct obj{
	int sub,x,y,id;
} objs[maxn];
long long ans[maxn],pre[maxn],suf[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>x[i]>>y[i];
		objs[i].sub = x[i] - y[i];
		objs[i].id = i;
		objs[i].x = x[i];
		objs[i].y = y[i];
	}
	for(int i = 1; i <= m; i++){
		cin>>u[i]>>v[i];
	}

	sort(objs + 1, objs + 1 + n, [](auto a,auto b){ return a.sub < b.sub; });
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + objs[i].x;
	for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + objs[i].y;
	

	return 0;
}
