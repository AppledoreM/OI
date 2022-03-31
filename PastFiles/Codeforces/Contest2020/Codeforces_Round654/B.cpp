#include <iostream>

typedef long long ll;

using namespace std;
int t;
ll n,r;




int main(){
    cin>>t;
    while(t--){
        cin>>n>>r;
        ll ans = 0;

        if(r < n){
            ans += r * (r + 1) / 2;
        }
        else{
            n--;
            ans += n * (n + 1) / 2 + 1;
        }
        
        cout<<ans<<endl;

    }

    return 0;
}