#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 5e5 * 4 + 10;
int n,c;
vector<int> v,sumc,pos[maxn];
int main()
{
    FAST_IO;
    cin>>n>>c;
    v.resize(n + 1);
    sumc.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        pos[v[i]].emplace_back(i);
    }
    for(int i = 1; i <= n; i++) sumc[i] = (v[i] == c);
    for(int i = 1; i <= n; i++) sumc[i] += sumc[i - 1];
    int mx_ans = 0;
    for(int i = 0; i < maxn - 10; i++){
        if(i == c) continue;
        int tmp_mx = 0;
        for(int j = 0; j < (int) pos[i].size();  j++){
            int r = pos[i][j]; int l = (j == 0 ? 0 : pos[i][j - 1]);
            if(l) l--;
            tmp_mx = max(tmp_mx - sumc[r] + sumc[l] + 1, 1);
            mx_ans = max(mx_ans,tmp_mx);
        }
    }
    cout<<mx_ans + sumc[n]<<endl;
    return 0;

}

