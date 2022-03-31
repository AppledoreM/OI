#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
constexpr int MAXN = 500005;
struct _data{
    ll sum;
    ll hei;
    int prev_ind = -1;
    _data(ll _sum = 0, ll _hei = -1):sum(_sum), hei(_hei){};
};

_data dp[MAXN][2];
ll mx_height[MAXN];
vector<ll> ans_lis;
vector<pll> que;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i) cin>>mx_height[i];

    for(int i = 1; i <= n; i++){
        if(que.empty()){
            dp[i][0].sum = mx_height[i];
            dp[i][0].hei = mx_height[i];
            dp[i][0].prev_ind = 0;
            que.emplace_back(pll(i,mx_height[i]));
        }
        while(!que.empty() && mx_height[i] <= que.back().second) que.pop_back();
        int prev_loc = -1;
        if(que.empty()) prev_loc = 0;
        else prev_loc = que.back().first;
        dp[i][0].sum = dp[prev_loc][0].sum + (i - prev_loc) * mx_height[i];
        dp[i][0].hei = mx_height[i];
        dp[i][0].prev_ind = prev_loc;
        que.emplace_back(pll(i, mx_height[i]));
    }
    que.clear();
    for(int i = n; i >= 1; --i){
        if(que.empty()){
            dp[i][1].sum = mx_height[i];
            dp[i][1].hei = mx_height[i];
            dp[i][1].prev_ind = n + 1;
            que.emplace_back(pll(i,mx_height[i]));
        }
        while(!que.empty() && mx_height[i] <= que.back().second) que.pop_back();
        int prev_loc = -1;
        if(que.empty()) prev_loc = n + 1;
        else prev_loc = que.back().first;
        dp[i][1].sum = dp[prev_loc][1].sum + (prev_loc - i) * mx_height[i];
        dp[i][1].hei = mx_height[i];
        dp[i][1].prev_ind = prev_loc;
        que.emplace_back(pll(i, mx_height[i]));
    }
    ll ans = 0;
    int choice = 0;
    for(int i = 1; i <= n; i++){
        if(ans < dp[i][0].sum + dp[i][1].sum - mx_height[i]){
            ans = dp[i][0].sum + dp[i][1].sum - mx_height[i];
            choice = i;
        }
    }

    int tmp = choice;
    while(tmp != 0){
        int st = dp[tmp][0].prev_ind;
        for(int i = st + 1; i <= tmp; ++i){
            ans_lis.emplace_back(mx_height[tmp]);
        }        
        tmp = st;
    }

    reverse(ans_lis.begin(), ans_lis.end());
    ans_lis.pop_back();

    tmp = choice;
    while(tmp != n + 1){
        int ed = dp[tmp][1].prev_ind;
        for(int i = tmp; i < ed; ++i){
            ans_lis.emplace_back(mx_height[tmp]);
        }
        tmp = ed;
    }
    for(auto& x : ans_lis){
        cout<<x<<" ";
    }




    return 0;
}
