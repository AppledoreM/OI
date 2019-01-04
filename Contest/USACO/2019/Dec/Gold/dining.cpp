#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
const int maxn = 5e4 + 10;
vector<pii> G[maxn];
vector<int> y;
int N,M,K,yum[maxn],dis[maxn],stp[maxn],val[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;


void dijkstra(int s){
    memset(dis,127,sizeof(dis));
    dis[s] = 0;
    pii st = make_pair(0,s);
    q.push(st);
    while(!q.empty()){
        pii tp = q.top(); q.pop();
        int c = tp.first; int now = tp.second;
        if(c > dis[now]) continue;
        for(int i = 0; i < (int) G[now].size(); i++){
            int v = G[now][i].first;
            int t = G[now][i].second;
            if(dis[now] + t < dis[v]){
                dis[v] = dis[now] + t;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}

void bfs(){
    queue<pii> q;
    memset(stp,127,sizeof(stp));
    for(int i = 0; i < (int) y.size(); i++){
        q.push(pii(-yum[y[i]] - 1 + stp[y[i]],y[i]));
        stp[y[i]] = 0;
    }
    while(!q.empty()){
        pii tp = q.front(); q.pop();
        for(int i = 0; i < (int) G[tp.second].size(); i++){
            if(stp[tp.second] + G[tp.second][i].second < stp[G[tp.second][i].first]){
               stp[G[tp.second][i].first] = stp[tp.second] + G[tp.second][i].second < stp[G[tp.second][i].first];
               q.push(pii(stp[G[tp.second][i].first],G[tp.second][i].first));
            }
        }
    }
}

int main()
{
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    FAST_IO;
    cin>>N>>M>>K;
    for(int i = 1; i <= M; i++){
        int u,v,t;
        cin>>u>>v>>t;
        G[u].emplace_back(pii(v,t));
        G[v].emplace_back(pii(u,t));
    }
    for(int i = 1; i <= K; i++){
        int x,val;
        cin>>x>>val;
        y.emplace_back(x);
        yum[x] = max(yum[x],val);
    }
    dijkstra(N);
    bfs();
    for(int i = 1;  i< N; i++){
        cout<<(bool)(stp[i] < dis[i])<<endl;
    }


    return 0;
}

