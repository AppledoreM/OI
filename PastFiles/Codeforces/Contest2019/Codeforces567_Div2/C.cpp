#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
#define DEBUG false
const int maxn = 1005;
int n,m;
char mp[maxn][maxn];
pair<int,int> dp[maxn][maxn];

int ind(char c){
    return c - 'a';
} 

bool check_ok(int i,int j, bool f = false){
    bool a = dp[i][j].first != dp[dp[i][j].second + i][j].first;
    bool b = dp[i][j].second == dp[dp[i][j].second + i][j].second;
    if(f) b = dp[i][j].second <= dp[dp[i][j].second + i][j].second;
    return a && b;
}


int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        for(int j = 0; j < (int) s.size(); j++){
            mp[i][j + 1] = s[j];
        }
    }

    for(int col = 1; col <= m; col++){
        for(int row = 1; row <= n; row++){
            int color = ind(mp[row][col]);
            int tmp_row = row;
            while(ind(mp[tmp_row + 1][col]) == color){
                tmp_row++;
            }
            for(int i = row; i <= tmp_row; i++) dp[i][col] = pair<int,int>(color,tmp_row - i + 1);
            row = tmp_row;
        }
    }

    if(DEBUG){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cerr<<dp[i][j].second<<" ";
            }
            cerr<<endl;
        }
    }
    

    int w = 0;
    long long ans = 0;
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            
            if(check_ok(row,col) && check_ok(row + dp[row][col].second, col, 1)){
                if(DEBUG) cerr<<row<<" "<<col<<" exist. Checking Further."<<endl;
                w = 1;
            }
            else{
                w = 0;
                continue;
            }
            int j = col + 1;
            while(j <= m){
                if(!(check_ok(row,j) && check_ok(row + dp[row][j].second, j, 1))){
                    break;
                }
                int len = dp[row][j].second;
                bool ok = true;
                if(dp[row][j].second != dp[row][j - 1].second) ok = false;
                for(int i = 0; i < 3; i++){
                    if(dp[row + i * len][j].first != dp[row + i * len][j - 1].first) ok = false;
                }
                if(!ok){
                    break;
                }
                else w++;
                if(DEBUG) cerr<<row<<" "<<j<<" is the same."<<endl;
                j++;
            }
            col = j - 1;
            ans += w * (w + 1) / 2;
            w = 0;
            if(DEBUG) cerr<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}

