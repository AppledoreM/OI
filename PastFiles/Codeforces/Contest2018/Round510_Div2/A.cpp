#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,m, a[maxn],b[maxn];

int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int ans1 = 0;
    for(int i = 1; i <= n; i++){
        ans1 = max(ans1, a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        int tmp = 999999;
        int ch;
        for(int j = 1; j <= n; j++){
            if(tmp > a[j]){
                tmp = a[j];
                ch = j;
            }
        }
        a[ch]++;
    }

    for(int i = 1; i <= n; i++){
        ans = max(ans, a[i]);
    }
    cout<<ans<<" "<<ans1 + m<<endl;

    return 0;
}
