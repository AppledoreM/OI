#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 1e3  +10;

int N, C, dp[maxn][1<<9][maxn], t[maxn], b[maxn];

int main(){
	scanf("%d",&C);
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		scanf("%d",&t[i], &b[i]);
	}	

	for(int i = 1; i <= N; i++){
		for(int j = 0; j < (1 << b[i]); j++){

		}
	}
	return 0;
}
