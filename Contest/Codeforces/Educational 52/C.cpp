#include <bits/stdc++.h>
using namespace std;
int n,k,low_h;
vector<int> hei,BIT;
void add(int x,int delta){
    while(x <= 200000){
        BIT[x] += delta;
        x += x & -x;
    }
}

int query(int x){
    int re = 0;
    while(x > 0){
        re += BIT[x];
        x -= x & -x;
    }
    return re;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    hei.resize(n + 1);
    BIT.resize(200000 + 5);
    low_h = INT_MAX;
    for(int i = 1; i <= n; i++) {
        cin>>hei[i];
        add(1,1); add(hei[i] + 1,-1);
        low_h = min(low_h,hei[i]);
    }
    int sum = 0;
    int ans = 0;
    int add = 1;
    for(int i = 200000; i > low_h; i--){
        int cnt = query(i);
        if(sum + cnt <= k) sum += cnt;
        else{
            sum = cnt;
            ans++;
        }
    }
    cout<<ans + (sum != 0)<<endl;

    return 0;
}
