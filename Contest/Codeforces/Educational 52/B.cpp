#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cout<<max(0ll,n - 2 * m)<<" ";
    ll l = 0, r = n;
    while(l <= r){
        ll mid = l + r >> 1;
        if(mid * (mid - 1) / 2 < m) l = mid + 1;
        else r = mid - 1;
    }
    cout<<max(0ll,n - l)<<endl;
    return 0;
}
