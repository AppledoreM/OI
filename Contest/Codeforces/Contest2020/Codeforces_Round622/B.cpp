#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;

        ll ans1 = 0;
        ll b = min(x - 1, max(0ll, n - y - 1));
        ll p = min(max(0ll, n - x - 1), y - 1);
        ans1 = b + p; 
        ll res = 0;
        if(n - x > p) res = n - x - p; 
        else res = 0;
        if(n - y > b) res = min(res, n - y - b);
        else res = 0;
        ans1 += res;
        ans1 = n - ans1;
        ll ans2 = 0;
        res = 0;
        b = min(x - 1, n - y); 
        p = min(y - 1, n - x);
        ans2 = b + p;
        if(x - 1 > b) res = x - 1 - b;
        else res = 0;
        if(y - 1 > p) res = min(res, y - 1 - p);
        else res = 0;
        ans2 += res + 1;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}