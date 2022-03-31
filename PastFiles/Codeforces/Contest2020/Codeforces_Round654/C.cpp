#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int t;
ll a, b, n, m;

int main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>n>>m;

        if(n + m > a + b){
            cout<<"No"<<endl;
        }
        else if(min(a, b) < m){
            cout<<"No"<<endl;
        }
        else cout<<"Yes"<<endl;
    }


    return 0;
}