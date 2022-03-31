#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
int remin[maxn],n,k;

int main(){
   cin>>n>>k;
   for(int i = 1; i <= n; i++){
       remin[i % k]++;
   } 

   long long ans = 0;
   ans += 1ll *remin[0] * remin[0] * remin[0];
   if(k % 2 == 0) ans += 1ll * remin[k / 2] * remin[k/ 2] * remin[k / 2];
   cout<<ans<<endl;

    return 0;
}