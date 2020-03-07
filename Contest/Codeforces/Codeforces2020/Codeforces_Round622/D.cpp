#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
constexpr int MAXN = 100005;
constexpr int MAXK = 9;
typedef long long ll;
typedef pair<ll,ll> pll;

struct EVENT{
    ll x,type,id;
    EVENT(int a = 0, int b = 0, int c = 0):x(a),type(b),id(c){};
    bool operator<(const EVENT& other) const{
        return x < other.x || (x == other.x && type < other.type);
    }
};

ll dp[1<<MAXK];
bool used[MAXK];
int n,m,k, id2cnt[MAXN];
pll a[MAXN];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m>>k;
    vector<EVENT> temp;
    for(int i = 1; i <= n; i++){
        cin>>a[i].first>>a[i].second;
        temp.emplace_back(a[i].first, 1, i);
        temp.emplace_back(a[i].second + 1, -1, i);
    }
    vector<int> gMask;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < (1 << k); i++){
        dp[i] = LLONG_MIN;
        int curMask = i;
        int cnt = 0;
        while(curMask > 0){
            cnt += curMask % 2;
            curMask >>= 1;
        }
        if(cnt % 2){
            gMask.emplace_back(i); 
        }
    }
    dp[0] = 0;
    int last = 0;
    for(auto item : temp){
        for(auto val : gMask){
            if(dp[val] != LLONG_MIN){
                dp[val] += item.x - last;
            }
        }
        last = item.x;
        if(item.type > 0){
            int cur = 0;
            while(cur < k && used[cur]){
                cur++;
            }            
            used[cur] = true;
            id2cnt[item.id] = cur;
            for(int i = 0; i < (1 << k); ++i){
                if((i & (1 << cur)) == 0){
                    dp[i | (1 << cur)] = max(dp[i | (1 << cur)], dp[i]);
                }
            }
        }
        else{
            int cur = id2cnt[item.id];
            used[cur] = false;
            for(int i = (1 << k) - 1; i >= 0; --i){
                if(i & (1 << cur)){
                    dp[i ^ (1 << cur)] = max(dp[i ^ (1 << cur)], dp[i]);
                    dp[i] = LLONG_MIN;
                }
            }
        }
    }

    cout<<dp[0]<<endl;

    return 0;
}












