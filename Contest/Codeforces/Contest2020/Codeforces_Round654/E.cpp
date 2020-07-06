#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

int n, p;
vector<int> v, uni;
int sum[maxn];
int calculate_C(int i,int x){
    int b = upper_bound(v.begin(), v.end(), x + i) - v.begin();
    return b - i;
}

bool okay(int x){
    for(int i = 0; i < n; i++){
        int cnt = upper_bound(v.begin(), v.end(), x + i) - v.begin();
        if(cnt <= i) return false;
    } 
    return true;
}

int main(){
    cin>>n>>p;
    int t = 0;
    for(int i = 1; i <= n; ++i){
        int x;
        cin>>x;
        v.emplace_back(x);
        t = max(t, x);
    }

    sort(v.begin(), v.end());

    int lo = 0, hi = 1e9;
    int ans_small = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(okay(mid)){
            hi = mid - 1;
            ans_small = mid;
        }
        else lo = mid + 1;
    }

    int idx = 0;
    t = min(t, ans_small + 100000);

    while(idx < n && t >= ans_small){
        if(calculate_C(idx, t) < p) idx++;
        else t--;
    }
    if(t < ans_small){
        cout<<0<<endl;
        return 0;
    }
    cout<<t - ans_small + 1<<endl;
    for(int i = ans_small; i <= t; ++i) cout<<i<<" ";


    return 0;
}