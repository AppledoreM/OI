#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
struct pt{
    double x,y;
} a[maxn];

bool possible(double x){
    double l = -1e18, r = 1e18;
    for(int i = 1; i <= n; i++){
        if(a[i].y > 2.0 * x) return false;
        double t = sqrt(a[i].y * (2 * x - a[i].y));
        l = max(l, a[i].x - t);
        r = min(r, a[i].x + t);
    }
    return l < r;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    bool pos,neg;
    pos = neg = false;
    for(int i = 1; i <= n; i++) {
        cin>>a[i].x>>a[i].y;
        if(a[i].y > 0) pos = 1;
        if(a[i].y < 0) neg = 1;
    }
    if(pos && neg) {
        cout<<-1<<endl;
        exit(0);
    }
    for(int i = 1; i <= n; i++) a[i].y = abs(a[i].y);
    double l = 0;
    double r = 1e16;
    int cnt = 300;
    while(cnt--){
        double mid = (r + l) / 2.0;
        if(possible(mid)) r = mid;
        else l = mid;
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
    return 0;
}
