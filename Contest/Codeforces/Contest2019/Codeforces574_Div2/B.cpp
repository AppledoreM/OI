#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long ate = 0;
    long long lo = 0, hi = n;

    while(lo <= hi){
        long long mid = (lo + hi) / 2;
        if(mid * (mid + 1) / 2 - (n - mid) <= k){
            lo = mid + 1;
            ate = mid;
        }
        else hi = mid - 1;
    }
    cout<<ate * (ate + 1) / 2 - k<<endl;


    return 0;
}