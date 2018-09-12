#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
bool vis[maxn];
queue<int> q;
vector<int> G[maxn];
char str[maxn];
int n, ans;
int get_ans(int u){
    q.push(u);
    int re = 0;
    memset(vis,0,sizeof(vis));
    vis[u] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        re++;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return re;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        int len = strlen(str);
        for(int j = 0; j < len; j++){
            if(str[j] == '1') G[i].push_back(j + 1);
        }
    }
    for(int i = 1; i <= n; i++) ans += get_ans(i);
    printf("%d\n",ans);

    return 0;
}
