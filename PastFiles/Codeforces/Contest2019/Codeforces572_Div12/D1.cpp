#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1e5 + 10;
int n,deg[maxn];



int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
    }

    for(int i = 1; i <= n; i++){
        if(deg[i] == 2){
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    cout<<"YES"<<endl;


    return 0;
}

