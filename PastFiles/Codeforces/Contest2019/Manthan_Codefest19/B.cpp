#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
const int maxn = 2005;
int a[maxn];
map<int,int> mp1,mp2;

int main(){
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++) cin>>a[i];

    int ans = INT_MAX;
    for(int i = 0; i <= n; i++){
        if(i != 0){
            mp1[a[i]]++;
            if(mp1[a[i]] >= 2) break;
        }
        mp2 = mp1;
        for(int j = n; j >= i; j--){
           mp2[a[j]]++;
           if(mp2[a[j]] >= 2){
               ans = min(ans, j - i);
               break;
           } 
        }
    }
    if(ans == INT_MAX) cout<<0<<endl;
    else cout<<ans<<endl;




    return 0;
}