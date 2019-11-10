#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
constexpr int maxn = 1e6 + 10;

using namespace std;

int n,q;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>q;

    while(q--){
        cin>>n;
        bool ok = false;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            if(x <= 2048){sum += x;}
        }
        if(sum >= 2048){
            ok = true;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }






    return 0;
}