#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef long long ll;
int n,k;
int a,b;
ll ansmin, ansmax;

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a % b);
}


void calc(int l){
    ll tot = (ll) n * k;
    for(ll i = l; i <= tot; i += k){
        ansmin = min(ansmin, tot / gcd(tot, i));
        ansmax = max(ansmax, tot / gcd(tot, i));
    } 
}

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    ansmin = 1e14;
    ansmax = 0;

    cin>>n>>k>>a>>b;

   calc(a + b);
   calc(a + k - b);
   calc(k - a + b);
   calc(k - a + k - b);

    cout<<ansmin<<" "<<ansmax<<endl;

    return 0;
}

