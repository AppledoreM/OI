#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 105;
struct cow{
    int s,t,buc;
    cow(int a = 0,int b = 0,int c = 0):s(a),t(b),buc(c){ };
} cows[maxn];
int tim[1005];

int main()
{
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    FAST_IO;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>cows[i].s>>cows[i].t>>cows[i].buc;
        for(int j = cows[i].s; j <= cows[i].t; j++){
            tim[j] += cows[i].buc;
        }
    }   
    sort(tim + 1, tim + 1000 + 1);
    cout<<tim[1000]<<endl;
    return 0;
}

