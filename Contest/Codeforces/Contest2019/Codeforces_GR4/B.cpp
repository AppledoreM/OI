#include <bits/stdc++.h>
using namespace std;
string s, t;

constexpr int maxn = 1e6 + 10;
int sum_cnt[maxn];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>s;

    for(int i = 0; i < (int) s.size(); i++){
        if(i >= 1){
            if(s[i] == 'v' && s[i - 1] == 'v'){
                t.push_back('w');
                continue;
            }
        }
        t.push_back(s[i]);
    }

    for(int i = 0; i < (int) t.size(); i++){
        if(t[i] == 'w'){
            sum_cnt[i + 1] = 1;
        }
        sum_cnt[i + 1] += sum_cnt[i];
    }

    long long ans = 0;
    for(int i = 0; i < (int) t.size(); i++){
        if(t[i] == 'o'){
            ans += 1ll * sum_cnt[i] * (sum_cnt[(int) t.size()] - sum_cnt[i + 1]);
        }
    }
    cout<<ans<<endl;





    return 0;
}