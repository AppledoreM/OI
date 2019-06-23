#include <iostream>
#include <stdio.h> 
#include <cstring> 
#include <math.h>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 1e5 + 10;
typedef pair<int,int> pii;
int n,m,ans_cnt;
int ing_person[maxn],ing_pizza[maxn];
vector<pii> price, min_cost[600];
int ans_cost,min_comb_cost[600],min_choice[600];
pii ans, comb_pair[600];

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    price.resize(m);
    for(int i = 1; i <= n; i++){
        int tot;
        cin>>tot;
        for(int j = 1; j <= tot; j++){
            int pref;
            cin>>pref;
            ing_person[i] |= (1 << (pref - 1));
        }
    }
    for(int i = 0; i < 600; i++) {
        min_comb_cost[i] = INT_MAX;
    }
    
    for(int i = 1; i <= m; i++){
        int num;
        cin>>price[i - 1].first>>num;
        price[i - 1].second = i;
        for(int j = 1; j <= num; j++){
            int pref;
            cin>>pref;
            ing_pizza[i] |= (1 << (pref - 1));
        }
        min_cost[ing_pizza[i]].emplace_back(price[i - 1]);
    }

    for(int i = 0; i < 600; i++){
        if(!min_cost[i].empty()){
            sort(min_cost[i].begin(),min_cost[i].end());
        }
    }
    
    for(int i = 0; i < (1 << 9); i++){
        for(int j = 0; j < (1 << 9); j++){
            for(int k = 0; k < (1 << 9); k++){
                if(i == (j | k)){
                    if(j != k){
                        if(min_cost[j].empty() || min_cost[k].empty()) continue;
                        if(min_cost[j][0].first + min_cost[k][0].first < min_comb_cost[i]){
                            min_comb_cost[i] = min_cost[j][0].first + min_cost[k][0].first;
                            comb_pair[i] = make_pair(min_cost[j][0].second, min_cost[k][0].second);
                        }
                    }
                    else if((int)min_cost[j].size() >= 2){
                        if(min_cost[j][0].first + min_cost[j][1].first < min_comb_cost[i]){
                            min_comb_cost[i] = min_cost[j][0].first + min_cost[j][1].first;
                            comb_pair[i] = make_pair(min_cost[j][0].second, min_cost[j][1].second);
                        }
                    }
                }
            }
        }
    }

    ans_cost = -1;
    for(int i = 0; i < (1 << 9); i++){
        if(min_comb_cost[i] != INT_MAX){
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                if((i | ing_person[j]) == i) {
                    cnt++;
                }
            }
            if(ans_cnt < cnt){
                ans_cnt = cnt;
                ans = comb_pair[i];
                ans_cost = min_comb_cost[i];
            }
            else if(ans_cnt == cnt && min_comb_cost[i] < ans_cost){
                ans = comb_pair[i];
                ans_cost = min_comb_cost[i];
            }
        }
    }

    if(ans.first){
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    else{
        sort(price.begin(), price.end());
        cout<<price[0].second<<" "<<price[1].second<<endl;
    }

    return 0;
}

