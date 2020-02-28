#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> a;
        map<int,bool> mp;
        int n,x;
        cin>>n>>x;
        int ans = 0;
        for(int i = 1; i <= n; i++){
           int y;
           cin>>y;
           mp[y] = true;
           a.push_back(y);
           if(y == x) ans = 1;
           else{
               if(!ans && y > x){
                   ans = 2;
               }
           }
        }
        if(ans){
            cout<<ans<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        int bc = a.back();
        if(x % bc == 0) cout<<x / bc<<endl;
        else cout<<x / bc + 1<<endl;
        

    }

    return 0;
}