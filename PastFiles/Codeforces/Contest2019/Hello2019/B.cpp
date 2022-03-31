#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
vector<int> v;
int n;
bool flag = false;

void dfs(int cur,int cl){
    if(cur == n){
        if(cl == 0) flag = true; 
        return ;
    }
    int nx = cl + v[cur];
    if(nx >= 360) nx -= 360;
    dfs(cur + 1,nx);
    nx = cl - v[cur];
    if(nx < 0) nx += 360;
    dfs(cur + 1, nx);
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        int a;
        cin>>a;
        v.emplace_back(a);
    }
    dfs(0,0);
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

