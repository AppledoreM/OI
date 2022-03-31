#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

int n;
typedef long long ll;
vector<pair<int,int>> v;


int main()
{
    FAST_IO;
    cin>>n;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        double x;
        cin>>x;
        if(x == (double)((int)x)){
            v.emplace_back(pair<int,int>(x,0));
        }
        else v.emplace_back(pair<int,int>(floor(x),1));
        sum += (ll) floor(x);
    }
    int i = 0;
    while(i < n){
        if(v[i].second && sum != 0){
            v[i].first++;
            sum++;
        }
        i++;
    }

    for(auto x : v){
        cout<<x.first<<endl;
    }


    return 0;
}

