#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
char s[N];
int main()
{
	scanf("%s",s+1);
	int n=(int)strlen(s+1);
	if(s[n]=='1'||s[1]=='0'||s[n-1]=='0'){
		printf("-1\n");
		return 0;
	}
	int now = 2;
	while(now<=n-now){
		if(s[now]!=s[n-now]) {
			printf("-1\n");
			return 0;
		}
		now++;
	}
	int root=2,num=1;
	now=2;
	printf("2 1\n");
	while(now<=n-now){
		if(s[now]=='1'){
			printf("%d %d\n",++now,root);
			root=now;
		}else{
			printf("%d %d\n",++now,root);
		}
		num++;
	}
	for(int i=num+1;i<n;i++){
		printf("%d %d\n",root,++now);
	}

}
