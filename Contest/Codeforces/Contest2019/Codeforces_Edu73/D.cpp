#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
constexpr int maxn = 3e5 + 10;

typedef long long ll;
using namespace std;

ll dp[maxn][3];
int q,n;
ll leng[maxn],price[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>q;
    while(q--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>leng[i]>>price[i];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 3; j++){
                ll min_ans = 1e18;
                for(int k = 0; k < 3; k++){
                    if(leng[i - 1] + k != leng[i] + j){
                        min_ans = min(min_ans, dp[i - 1][k]);
                    }
                }
                dp[i][j] = min_ans + price[i] * j;
            }
        }
        cout<<min(min(dp[n][0],dp[n][1]),dp[n][2])<<endl;
    }





    return 0;
}