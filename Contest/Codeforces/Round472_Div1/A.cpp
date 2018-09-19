#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n,m,col[maxn],row[maxn];
char a[maxn][maxn];
vector<int> s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            if(a[i][j] == '#'){
                s[i].emplace_back(j);
            }
        }
    }
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(s[i] != s[j]){
                bool used[55];
                memset(used,0,sizeof(used));
                for(int k = 0; k < s[i].size(); k++) used[s[i][k]] = 1;
                for(int k = 0; k < s[j].size(); k++){
                    if(used[s[j][k]]){
                        flag = false;
                        break;
                    }
                    used[s[j][k]] = 1;
                }
            }
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
