#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int N,M,K,dp[35][35],p[35][35],fail[35];
char str[35];

void mul(int a[35][35],int b[35][35],int ans[35][35]){
	int tmp[35][35];
	memset(tmp,0,sizeof(tmp));
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < M; k++){
				tmp[i][j] = ((a[i][k] * b[k][j] % K) + tmp[i][j]) % K;
			}
		}
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			ans[i][j] = tmp[i][j];
		}
	}	
}
int main(){
	cin>>N>>M>>K;
	scanf("%s",str);
	int i = 0,j = -1;
	fail[0] = -1;
	while(i < M){
		if(j == -1 || str[i] == str[j]){ 
			fail[++i] = ++j;
		}
		else j = fail[j];
	}
	
	for(i = 0; i < M; i++){
		for(int k = 0; k <= 9; k++){
			j = i;
			while(j != -1 && str[j] != k + '0') j = fail[j];
			if(j == -1 || str[j] == k + '0') j++;
			if(j != M) p[i][j] = (p[i][j] + 1) % K;
		}
	}
	
	for(int i = 0; i < M; i++) dp[i][i] = 1;
	while(N){
		if(N & 1) mul(dp,p,dp);
		mul(p,p,p);
		N >>= 1;
	}
	
	int ans = 0;
	for(i = 0; i < M; i++){
		ans = (ans + dp[0][i]) % K;
	}
	printf("%d\n",ans);
	return 0;
}	
