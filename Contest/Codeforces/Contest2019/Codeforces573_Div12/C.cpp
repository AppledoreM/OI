#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
vector<ll> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        ll x;
        cin>>x;
        v.emplace_back(x);
    }
    v.insert(v.begin(), 0);
    ll tmp = k;
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        int j = i - 1;
        while(j + 1 <= m && v[j + 1] <= tmp) j++;
        if(j - i >= 0) {
            cnt++;
            tmp += (j - i + 1);
            i = j;
            continue;
        }
        else {
            ll lo = 1, hi = n / k + 1;
            ll ans = 0;
             while(lo <= hi){
                ll mid = (lo + hi) / 2;
                if(tmp + mid * k >= v[i]){
                    ans = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            tmp += ans * k;
            i--;
        }
    }
    cout<<cnt<<endl;

    


    return 0;
}