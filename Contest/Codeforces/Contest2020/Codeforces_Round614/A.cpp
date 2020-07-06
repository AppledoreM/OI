#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

inline int abs(int x){
    return x < 0 ? -x : x;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,s,k;
        cin>>n>>s>>k;
        map<int,int>mp;
        for(int i = 0; i < k; ++i){
            int x;
            cin>>x;
            mp[x] = 1;
        }
        for(int i = 0; i <= s || s + i <= n; i++){
            if(s + i <= n && !mp[s + i]){
                cout<<i<<endl;
                break;
            }
            if(s - i > 0 && !mp[s - i]){
                cout<<i<<endl;
                break;
            }
        }
    }

    return 0;
}

