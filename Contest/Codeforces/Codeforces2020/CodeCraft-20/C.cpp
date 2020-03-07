#include <iostream>
#include <algorithm>
using namespace std;
constexpr int maxn = 2e6 + 5;
typedef long long ll;
ll suma[maxn], sumb[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n,m,p;
    cin>>n>>m>>p;
    int ans = 0;
    bool choice = false;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        if(x % p && !choice){
            choice = true;
            ans += i;
        }
    }
    choice = false;
    for(int i = 0; i < m; i++){
        int x;
        cin>>x;
        if(x % p && !choice){
            choice = true;
            ans += i;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}