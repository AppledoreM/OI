#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1e5 + 10;

int n, dia;
int rt1, rt2;
bool flag;
vector<int> tree[maxn],leaf,tmp,lis;
int level[maxn];
int md, ha;



void fd(int u,int fa, int dep){
    if(u != fa && tree[u].size() == 1){ if(md > dep){
            md = dep;
            ha = u;
        }
        return;
    }
    for(int i = 0; i < (int) tree[u].size(); i++){
        int v = tree[u][i];
        if(v == fa || (int) tree[v].size() > 2) continue;
        fd(v, u, dep + 1);
    }
}
void validate(int u,int fa, int dep){
    if(!level[dep]) level[dep] = tree[u].size();
    for(int i = 0; i < (int) tree[u].size(); i++){
        int v = tree[u][i];
        if(v == fa) continue;
        validate(v, u, dep + 1);
    }
    if(level[dep] != (int) tree[u].size()) flag = false;
}

void fd_mid(int u,int fa){
    if(u == rt2){
        lis = tmp;
        return;
    }
    tmp.emplace_back(u);
    for(int i = 0; i < (int) tree[u].size(); i++){
        int v = tree[u][i];
        if(v == fa) continue;
        fd_mid(v,u);
    }
    tmp.pop_back();
}

void dfs(int u,int fa, int dep){
   if(u != fa && tree[u].size() == 1){
       if(dep > dia){
           dia = dep;
           rt1 = u;
       }
       return;
   }

   for(int i = 0;i < (int) tree[u].size(); i++){
       int v = tree[u][i];
       if(v == fa) continue;
       dfs(v, u, dep + 1);
   }
}

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    if(n == 1){
        cout<<1<<endl;
        exit(0);
    }

    dfs(1, 1, 0);
    swap(rt1, rt2);
    dia = 0;
    dfs(rt2, rt2, 0);

    flag = true;
    validate(rt1, 0, 0);
    memset(level,0,sizeof(level));
    if(flag){
        cout<<rt1<<endl;
        exit(0);
    }
    flag = true;
    validate(rt2, 0, 0);
    memset(level,0,sizeof(level));
    if(flag){
        cout<<rt2<<endl;
        exit(0);
    }
    flag = true;

    fd_mid(rt1, 0);
    int now = lis[(int) lis.size() / 2];
    validate(now, now, 0);
    memset(level,0,sizeof(level));
    if(flag){
        cout<<now<<endl;
        exit(0);
    }
    flag = true;

    md = INT_MAX;
    fd(now, now, 0);
    validate(ha, ha, 0);
    if(!ha) flag = false;
    if(flag){
        cout<<ha<<endl;
        exit(0);
    }
    cout<<-1<<endl;
    return 0;
}

