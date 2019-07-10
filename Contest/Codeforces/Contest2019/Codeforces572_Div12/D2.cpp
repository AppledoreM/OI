#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1005;
typedef pair<int,int> pii;
vector<pii> G[maxn];
vector<pii> son[maxn];
map<pii,int> mp,mp1;
int n, rt, deg[maxn];
struct output{
    int u,v,w;
    output(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
vector<output> ans_lis;

void find_sons(int u,int fa){
    if(u != rt && (int) G[u].size() == 1){
        son[fa].emplace_back(pii(u,u));
        return;
    }

    for(int i = 0; i < (int) G[u].size(); i++){
        int v = G[u][i].first;
        if(v == fa) continue;
        find_sons(v, u);
    }
    
    for(auto x : son[u]) son[fa].emplace_back(pii(x.first,u));
}
int target = 0;
int remove_wei = 0;

bool del_wei(int u,int fa){
    if(u == target){
        return true;
    } 

    for(auto x : G[u]){
        int v = x.first;
        if(v == fa) continue;
        mp[pii(u,v)] -= remove_wei;
        mp[pii(v,u)] -= remove_wei;
        if(del_wei(v,u)) return true;
        mp[pii(u,v)] += remove_wei;
        mp[pii(v,u)] += remove_wei;
    }

    return false;
}

void dfs(int u,int fa){
    if(u != rt && (int) G[u].size() == 1) return;
    for(auto x : G[u]){
        int v = x.first;
        if(v == fa) continue;
        dfs(v,u); 
    }
    if(u != rt){
        int w = (mp[pii(fa,u)] - mp1[pii(fa,u)]);
        int son1,son2;
        int bel1,bel2;
        for(auto x: son[u]){
            if(x.first != u) {
                son1 = x.first;
                bel1 = x.second;
                break;
            }
        }
        for(auto x: son[u]){
            if(x.first != u && bel1 != x.second) {
                son2 = x.first;
                bel2 = x.second;
                break;
            }
        }
        target = son1;
        remove_wei = w / 2;
        del_wei(rt,0);
        target = son2;
        del_wei(rt,0);
        remove_wei = -w/2;
        del_wei(son1,0);
        ans_lis.emplace_back(output(rt,son1,-w/2));
        ans_lis.emplace_back(output(rt,son2,-w/2));
        ans_lis.emplace_back(output(son1,son2,w/2));
    }
    
}



int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].emplace_back(pii(v,w));
        G[v].emplace_back(pii(u,w));
        mp1[pii(u,v)] = mp1[pii(v,u)] = w;
        deg[u]++;
        deg[v]++;
    }


    for(int i = 1; i <= n; i++){
        if(deg[i] == 2){
            cout<<"NO"<<endl;
            exit(0);
        }
        if(deg[i] == 1){
            rt = i;
        }
    }
    cout<<"YES"<<endl;

    find_sons(rt,0);

    for(int i = 1; i <= n; i++){
        if(deg[i] == 1 && i != rt){
            target = i;
            remove_wei = -G[i][0].second;
            del_wei(rt,0);
            ans_lis.emplace_back(output(rt,i,-remove_wei));
        }
    }

    dfs(rt,0);
    cout<<(int)ans_lis.size()<<endl;
    for(auto x : ans_lis) cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
    return 0;
}

