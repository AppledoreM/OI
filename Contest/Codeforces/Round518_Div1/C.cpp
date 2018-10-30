#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int n;
vector<pii> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	v.resize(n + 1);
	for(int i = 1; i <= n; i++){
		int x,y;
		cin>>x>>y;
		v[i] = pii(x,y);	
	}
	

	return 0;
}

