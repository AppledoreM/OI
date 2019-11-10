#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
constexpr int maxn = 1e6 + 10;

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n ;j++){
            if((i + j) & 1){
                cout<<"W";
            }
            else cout<<"B";
        }
        cout<<endl;
    }




    return 0;
}