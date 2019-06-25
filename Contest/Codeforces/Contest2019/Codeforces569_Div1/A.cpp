#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

int n,q;
vector<int> v,mx;

int main()
{
    cin>>n>>q;
    v.resize(n + 1);
    mx.resize(n + 1);
    mx[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        mx[i] = v[i];
        mx[i] = max(mx[i],mx[i - 1]);
    }
    vector<int> a(v.begin() + 1,v.end());

    for(int i = 1; i <= n - 1; i++){
        if(a[0] > a[1]){
            int tmp = a[1];
            a.erase(a.begin() + 1);
            a.emplace_back(tmp);
        }
        else{
            int tmp = a[0];
            a.erase(a.begin());
            a.emplace_back(tmp);
        }
    }


    for(int i = 1; i <= q; i++){
        long long m;
        cin>>m;
        if(m < n){
            cout<<mx[m]<<" "<<v[m + 1]<<endl;
        }
        else{
            int res = m % (n - 1);
            if(res == 0) res = n - 1;
            cout<<mx[n]<<" "<<a[res]<<endl;
        }
    }

    return 0;
}

