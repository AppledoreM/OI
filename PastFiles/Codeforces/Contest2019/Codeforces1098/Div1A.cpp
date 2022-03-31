#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1e5 + 10;
int n,a[maxn];
vector<int> s,G[maxn];

void dfs(int u,int sum, int dep){
    if((int) G[u].size() == 0){
        if(dep % 2 == 0) a[u] = 0;
        else {
            a[u] = s[u] - sum;
            if(a[u] < 0){
                cout<<-1<<endl;
                exit(0);
            }
        }
        return ;
    }
    if(dep % 2 == 0){
        int val = INT_MAX;
        for(int v : G[u]){
            val = min(val, s[v] - sum);
        }
        if(val < 0) {
            cout<<-1<<endl;
            exit(0);
        }
        a[u] = val;
        for(int v : G[u]){
            dfs(v, sum + a[u], dep + 1);
        }
    }
    else{
        if(u != 1) a[u] = s[u] - sum;
        if(a[u] < 0){
            cout<<-1<<endl;
            exit(0);
        }
        for(int v : G[u]){
            dfs(v, s[u], dep + 1);
        }
    }
}

int main()
{
    FAST_IO;
    cin>>n;
    for(int i = 1;i < n; i++){
        int p;
        cin>>p;
        G[p].emplace_back(i + 1);
    }
    s.emplace_back(0);
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        s.emplace_back(x);
    }
    a[1] = s[1];
    dfs(1,a[1],1);
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += (long long) a[i];
    cout<<ans<<endl;
    return 0;
}

