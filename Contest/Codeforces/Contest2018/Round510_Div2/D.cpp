#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long n, a[maxn], tot, BIT[maxn];
long long pre[maxn], b[maxn],t;

int lowbit(int x){ return x & -x;}
void add(int x){
    while(x <= tot){
        BIT[x]++;
        x += lowbit(x);
    }
}

long long query(int x){
    long long re = 0;
    while(x){
        re += BIT[x];
        x -= lowbit(x);
    }
    return re;
}



int main(){
    ios::sync_with_stdio(false);
    cin>>n>>t;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
        b[++tot] = pre[i];
    }
    b[++tot] = 0;
    sort(b + 1,b + 1 + tot);
    tot = unique(b + 1,b + 1 + tot) - b - 1;
    long long ans = 0;
    add(lower_bound(b + 1, b + 1 + tot,0) - b);
    for(int i = 1; i <= n; i++){
        int pos = upper_bound(b + 1,b + 1 + tot, pre[i] - t) - b;
        ans += (i - query(pos - 1));
        pos = lower_bound(b + 1,b + 1 + tot, pre[i]) - b;
        add(pos);
    }
    cout<<ans<<endl;
    return 0;
}
