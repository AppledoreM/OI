#include <bits/stdc++.h>
using namespace std;


int main(){
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        bool ok = true;
        if(k % 3 == 0){
            int md = n % (k + 1);
            if(md % 3 == 0 && md != k){
                ok = false;
            }
        }
        else {
            if(n % 3 == 0) ok = false;
        }
        if(ok) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}