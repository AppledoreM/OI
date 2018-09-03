#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int N,M,BIT1[maxn],BIT2[maxn];

struct ord{
	char opt;
	int a,b;
	ord(char x = 0,int y = 0,int z = 0):opt(x),a(y),b(z){};
} orders[maxn];
void add1(int x,int delta){
	while(x <= N){
		BIT1[x] += delta;
		x += x & -x;
	}
}

int sum1(int x){
	int re = 0;
	while(x){
		re += BIT1[x];
		x -= x & -x;
	}
}

void add2(int x,int delta){
	while(x <= N){
		BIT2[x] += delta;
		x += x & -x;
	}
}

int sum2(int x){
	int re = 0;
	while(x){
		re += BIT2[x];
		x -= x & -x;
	}
}

int main(){
	scanf("%d$d",&N,&M);
	for(int i = 1; i <= M; i++){
		char opt[2];
		scanf("%s",opt);
		int a,b;
		scanf("%d%d",&a,&b);
		orders[i] = ord(opt[0],a,b);
	}

	return 0;
}
