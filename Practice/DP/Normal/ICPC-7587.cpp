#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
vector<pii> v;
int n;


int main()
{
    while(cin>>n){
        v.resize(n + 1);
        for(int i = 1 ;i <= n; i++){
            cin>>v[i].first>>v[i].second;
        }    
        sort(v.begin() + 1,v.end(),[](auto x,auto y){ x.first + x.second < y.first + y.second; });
        
    }

    return 0;
}

