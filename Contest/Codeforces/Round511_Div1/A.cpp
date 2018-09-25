#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxm = 15000001;
int n,a[maxn];
int cnt[maxm];
bool vis[maxm];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	int gcd = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		gcd = __gcd(gcd,a[i]);
	}	
	for(int i = 1; i <= n ;i++) cnt[a[i] / gcd]++;
	int ans = 0;
	for(int i = 2; i < maxm; i++){
		if(!vis[i]){
			int c = 0;
			vis[i] = 1;
			for(int j = i; j < maxm; j += i){
				vis[j] = 1;
				c += cnt[j];
			}
			ans = max(ans,c);
		}		
	}
	if(!ans) cout<<-1<<endl;
	else cout<<n - ans<<endl;
	return 0;
}
