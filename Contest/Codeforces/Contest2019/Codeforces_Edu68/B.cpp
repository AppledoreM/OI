#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e4 + 10;
string mp[maxn];
int row_cnt[maxn], col_cnt[maxn];
int q,n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>q;

    while(q--){
        cin>>n>>m;
        for(int i = 1; i <= n; i++) cin>>mp[i];

        for(int i = 1; i <= n; i++){
            int tot_cnt = 0;
            for(int j = 0; j < m; j++) {
               tot_cnt += (mp[i][j] == '*');
            }
            row_cnt[i] = tot_cnt;
        }

        for(int j = 0; j < m; j++){
            int tot_cnt = 0;
            for(int i = 1; i <= n; i++){
                tot_cnt += (mp[i][j] == '*');
            }
            col_cnt[j + 1] = tot_cnt;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                ans = min(ans, max(0, n + m - row_cnt[i] - col_cnt[j] - 1 + (mp[i][j - 1] == '*')));
            }
        }
        cout<<ans<<endl;
    }





    return 0;
}