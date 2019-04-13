#include <bits/stdc++.h>


using namespace std;
vector<int> v;
map<int,int> mp[2];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	v.resize(n + 1);
	for(int i = 1; i <= n; i++) cin>>v[i];
	mp[0][0] = 1;
	int x = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		x ^= v[i];
		ans += mp[i%2][x];
		mp[i % 2][x]++;

	}
	cout<<ans<<endl;

	return 0;
}
