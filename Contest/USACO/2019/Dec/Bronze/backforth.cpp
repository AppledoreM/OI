#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
bool dp[6][2005][2005];
vector<int> buc_siz[2];
map<int,bool>mp;
void dfs(int day,int sz1,int sz2){
    if(day == 5){
        mp[sz1] = 1;
        return;
    }
    if(day % 2 == 0){
        for(int j = 0; j < (int) buc_siz[0].size(); j++){
            int x = buc_siz[0][j];
            buc_siz[1].emplace_back(x);
            buc_siz[0].erase(buc_siz[0].begin() + j);
            dfs(day + 1,sz1 - x,sz2 + x);
            buc_siz[1].pop_back();
            buc_siz[0].insert(buc_siz[0].begin() + j,x);
        }
    }
    else{
        for(int j = 0; j < (int) buc_siz[1].size(); j++){
            int x = buc_siz[1][j];
            buc_siz[0].emplace_back(x);
            buc_siz[1].erase(buc_siz[1].begin() + j);
            dfs(day + 1,sz1 + x,sz2 - x);
            buc_siz[0].pop_back();
            buc_siz[1].insert(buc_siz[1].begin() + j,x);

        }
    }
}

int main()
{
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    FAST_IO;
    for(int i = 0; i <= 1; i++){
        for(int j = 1; j <= 10; j++){
            int x;
            cin>>x;
            buc_siz[i].emplace_back(x);
        }
    }
    dfs(1,1000,1000);
    cout<<(int)mp.size()<<endl;
    return 0;
}

