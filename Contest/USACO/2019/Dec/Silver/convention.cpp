#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
int N,M,C;
vector<int> v;


bool okay(int tim){
    int cnt = 0;
    int car = 1;
    int mn = v[0];
    int i = 0;
    for(; i < (int) v.size() && car <= M; i++){
        if(v[i] - mn <= tim && cnt + 1 <= C){
            cnt++;
        }
        else{
            cnt = 1;
            car++;
            mn = v[i];
        }
    }
    return car <= M;
}

int main()
{
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    FAST_IO;
    cin>>N>>M>>C;
    for(int i = 0; i < N; i++){
        int x;
        cin>>x;
        v.emplace_back(x);
    }
    sort(v.begin(),v.end());
    int lo = 0, hi = 1e9;
    int ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(okay(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}

