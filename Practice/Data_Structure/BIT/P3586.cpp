#include "stdafx.h" 
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e6 + 10;
const int mx = 1e6 + 1;
int N, M, tot, val[maxn];
long long BIT1[maxn],BIT2[maxn];
map<int, int> mp;
struct ord{
	char opt;
	int a,b;
	ord(char x = 0,int y = 0,int z = 0):opt(x),a(y),b(z){};
} orders[maxn];

void add1(int x,int delta){
	while(x <= mx){
		BIT1[x] += delta;
		x += x & -x;
	}
}

long long sum1(int x){
	long long re = 0;
	while(x > 0){
		re += BIT1[x];
		x -= x & -x;
	}
	return re;
}

void add2(int x,long long delta){
	while(x <= mx){
		BIT2[x] += delta;
		x += x & -x;
	}
}

long long sum2(int x){
	long long re = 0;
	while(x > 0){
		re += BIT2[x];
		x -= x & -x;
	}
	return re;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= M; i++){
		char opt[2];
		scanf("%s",opt);
		int a,b;
		scanf("%d%d",&a,&b);
		orders[i] = ord(opt[0],a,b);
		mp[b] = 1;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) it->second = ++tot;
	for (int i = 1; i <= M; i++) {
		if (orders[i].opt == 'U') {
			int k = orders[i].a, a = orders[i].b;
			if (val[k] != 0) {
				add1(mp[val[k]], -1);
				add2(mp[val[k]], -val[k]);
			}
			val[k] = a;
			if (a != 0) {
				add1(mp[a], 1);
				add2(mp[a], a);
			}
		}
		else {
			long long c = orders[i].a, s = orders[i].b;
			long long sm1 = c - sum1(mx) + sum1(mp[s]);
			if (sm1 * s <= sum2(mp[s])) printf("TAK\n");
			else printf("NIE\n");
		}
	}
	return 0;
}
