#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

struct node{
    int u,v,id;
    node(int _u,int _v,int _id):u(_u),v(_v),id(_id){};
};
const int maxn = 1e6 + 5;
vector<node> edge;
int deg[maxn], limit[maxn];
bool vis[maxn];


int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin>>u>>v;
        edge.emplace_back(node(u,v,i));
        deg[u]++; deg[v]++;
    }

    for(int i = 1; i <= n ;i++){
        limit[i] = (int)ceil(1.0 * deg[i] / 2);
    }

    random_shuffle(edge.begin(),edge.end());
    int edge_lim = ceil(1.0 * (n + m) / 2);
    for(int i = 0; i < (int) edge.size() && m > edge_lim; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int id = edge[i].id;
        if(deg[u] == limit[u]) continue;
        if(deg[v] == limit[v]) continue;

        deg[u]--;
        deg[v]--;
        vis[id] = 1;
        m--;    
    }
    cout<<m<<endl;
    for(int i = 0; i < (int)edge.size(); i++){
        if(!vis[edge[i].id]){
            cout<<edge[i].u<<" "<<edge[i].v<<endl;
        }
    }
    



    return 0;
}

