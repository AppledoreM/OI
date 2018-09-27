#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tot;
ll n,m,k;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    if((2 *  n * m) % k){
        cout<<"NO"<<endl;
        exit(0);
    }
    else{
        cout<<"YES"<<endl;
    }
    bool odd = false;
    if(k % 2 == 0){
        k /= 2;
    }
    else odd = true;
    ll g = __gcd(n, k);
    ll x = n / g;
    ll kp = k / g;
    ll y = m / kp;
    if(odd) {
        if(2 * x <= n) x *= 2;
        else y *= 2;
    }
    cout<<0<<" "<<0<<endl;
    cout<<x<<" "<<0<<endl;
    cout<<0<<" "<<y<<endl;

    return 0;
}
