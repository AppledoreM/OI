#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef long long ll;
const int maxn = 1e5 + 10;
struct cow{
    int sen,arr,t;
    cow(int a = 0,int b = 0,int c = 0):sen(a),arr(b),t(c){};
} cows[maxn];

bool cmp(cow a,cow b){
    return a.sen > b.sen;
}

int main()
{
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    FAST_IO;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cows[i].sen = n - i + 1;
        cin>>cows[i].arr>>cows[i].t;
    }
    sort(cows + 1,cows + 1 + n,[](cow x,cow y){return (x.arr != y.arr) ? x.arr < y.arr : x.sen > y.sen;});
    int prev = 0;
    long long ans = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        if(sum + (ll) cows[prev].arr + (ll) cows[prev].t >= (ll) cows[i].arr){
            sum += (ll) cows[i].t;
        }
        else{
            if(prev){
                vector<cow> v;
                for(int j = prev + 1; j <= i - 1; j++) v.emplace_back(cows[j]);
                sort(v.begin(),v.end(),cmp);
                ll tmp = cows[prev].arr + cows[prev].t;
                for(int j = 0; j < (int) v.size(); j++){
                    ans = max(ans,tmp - v[j].arr);
                    tmp += v[j].t;
                }
            }
            sum = 0;
            prev = i;
        }
    }
    if(prev){
        vector<cow> v;
        for(int j = prev + 1; j <= n; j++) v.emplace_back(cows[j]);
        sort(v.begin(),v.end(),cmp);
        ll tmp = cows[prev].arr + cows[prev].t;
        for(int j = 0; j < (int) v.size(); j++){
            ans = max(ans,tmp - v[j].arr);
            tmp += v[j].t;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}


