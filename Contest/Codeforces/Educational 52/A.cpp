#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,s,a,b,c;
ll ans;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>s>>a>>b>>c;
        ans = s / c;
        ans += (ans / a) * b;
        cout<<ans<<endl;
    }
    return 0;
}
