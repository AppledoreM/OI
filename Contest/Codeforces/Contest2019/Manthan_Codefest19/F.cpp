#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 2e6 + 10;
int n;

int a[maxn], vis[maxn], cnt[maxn];


void update(int x,int time){
    if(vis[x] == time || cnt[x] == 2) return;
    vis[x] = time;
    cnt[x]++;
    for(int j = 20; j >= 0; j--){
        if((x >> j) & 1){
            update(x ^ (1 << j), time);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int ans = 0;
    for(int i = n; i >= 1; i--){
        int s = 0;

        for(int j = 20; j >= 0; j--){
            if(((a[i] >> j) & 1) == 0){
                if(cnt[s | (1 << j)] == 2){
                    s |= (1 << j);
                }
            }
        }
        if(i <= n - 2) ans = max(ans, a[i] | s);
        update(a[i], i);
    }
    cout<<ans<<endl;

    return 0;
}
