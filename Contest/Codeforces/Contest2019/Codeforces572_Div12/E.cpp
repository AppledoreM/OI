#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll n,p,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>p>>k;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll x;
        cin>>x;
        ll tmp = x;
        for(int j = 1; j <= 3; j++){
            x = x * tmp % p;
        }
        x = x - k * tmp % p;
        if(x < 0) x += p;
        ans += mp[x];
        mp[x]++;
    }

    cout<<ans<<endl;




    return 0;
}

