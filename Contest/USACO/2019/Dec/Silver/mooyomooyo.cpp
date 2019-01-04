#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
int N,K,cell[1005][15];
int xmv[] = {0,0,1,-1};
int ymv[] = {1,-1,0,0};

bool vis[1005][15];

bool bfs(int x,int y,int c){
    vector<pii> v;
    memset(vis,0,sizeof(vis));
    pii st = make_pair(x,y);
    queue<pii> q;
    q.push(st);
    vis[x][y] = 1;
    while(!q.empty()){
        pii tp = q.front(); q.pop();
        v.emplace_back(tp);
        for(int i = 0; i < 4; i++){
            int tx = tp.first + xmv[i];
            int ty = tp.second + ymv[i];
            if(1 <= tx && tx <= N && 1 <= ty && ty <= 10 && cell[tx][ty] == c && !vis[tx][ty]){
                q.push(pii(tx,ty));
                vis[tx][ty] = 1;
            }
        }
    }
    if((int) v.size() >= K){
        for(int i = 0; i < (int) v.size(); i++){
            cell[v[i].first][v[i].second] = 0;
        }
        return true;
    }
    return false;
}
int tmp[1005];

int main()
{
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    FAST_IO;
    cin>>N>>K;
    for(int i = N; i >= 1; i--){
        string s;
        cin>>s;
        for(int j = 0; j < (int) s.size(); j++){
            cell[i][j + 1] = s[j] - '0';
        }
    }
  
    bool flag = 1;
   while(flag){
        flag = false;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= 10; j++){
                if(cell[i][j]){
                    flag |= bfs(i,j,cell[i][j]);
                }
            }
        } 
        for(int j = 1; j <= 10; j++){
            memset(tmp,0,sizeof(tmp));
            int tot = 0;
            for(int i = 1; i <= N; i++){
                if(cell[i][j]){
                    tmp[++tot] = cell[i][j];
                    cell[i][j] = 0;
                }
            }
            for(int i = 1; i <= tot; i++){
                cell[i][j] = tmp[i];
            }
        }
    }
    for(int i = N; i >= 1; i--){
        for(int j = 1; j <= 10; j++){
            cout<<cell[i][j];
        }
        cout<<endl;
    }    
    return 0;
}


