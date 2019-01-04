#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,U,v[maxn];

int bin_search(int l,int r, int x){
    while(l <= r){
        int mid = (l + r) >> 1;
        if(v[mid] - x <= U) l = mid + 1;
        else r = mid - 1;
    }
    return v[r];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>U;
    for(int i = 1; i <= n; i++) cin>>v[i];
    double tmp_ans = 0;
    int a,b,c;
    a = b = c = 0;
    for(int i = 1; i + 2 <= n; i++){
        double tmpa = v[i];
        double tmpb = v[i + 1];
        double tmpc = bin_search(i + 2,n,v[i]);
        if((tmpc - tmpb) / (tmpc - tmpa) > tmp_ans) {
            a = tmpa;
            b = tmpb;
            c = tmpc;
            tmp_ans = (tmpc - tmpb) / (tmpc - tmpa);
        }
    }
    if(tmp_ans == 0) cout<<-1<<endl;
    else cout<<fixed<<setprecision(20)<<(double)(c - b) / (double)(c - a)<<endl;

    return 0;
}
