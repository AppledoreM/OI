#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int main(){
	cin>>t;
	while(t--){
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		int ans = 0;
		ans = max(ans, a * y);
		ans = max(ans, (a - x - 1) * b);
		ans = max(ans, a * (b - y - 1));
		ans = max(ans, x * b);
		cout<<ans<<endl;
	}

	return 0;
}
