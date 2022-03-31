#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef long long ll;

ll n;
vector<ll> lis_prime;

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;

    auto now = n;
    for(ll i = 2;i * i <= n ; i++){
        if(now % i) continue;
        while(now % i == 0) now /= i;
        lis_prime.emplace_back(i);
    }
    if(now != 1) lis_prime.emplace_back(now);

    if((int) lis_prime.size() == 1) cout<<lis_prime[0]<<endl;
    else cout<<1<<endl;





    return 0;
}

