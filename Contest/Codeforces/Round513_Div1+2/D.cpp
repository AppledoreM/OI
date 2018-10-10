#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
vector<int> ls,rs;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ls.resize(n + 1); rs.resize(n + 1);
    for(int i = 1; i <= n; i++) cin>>ls[i]>>rs[i];
    sort(ls.begin() + 1,ls.end());
    sort(rs.begin() + 1,rs.end());
    ll ans = n;
    for(int i = 1; i <= n; i++) ans += (ll) max(ls[i],rs[i]);
    cout<<ans<<endl;
    return 0;
}
