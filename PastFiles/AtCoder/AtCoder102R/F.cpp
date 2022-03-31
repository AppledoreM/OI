#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 10;
int n, a[maxn];

bool check(int l,int r){
    int mn = INT_MAX, mx = 0;
    for(int i = l; i <= r; i++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if(mn < l || mx > r){
        return 1;
    }
    int lasx = 0, lasy = 0;
    for(int i = l; i <= r; i++){
        if(a[i] != i){
            if(a[i] < i){
                if(lasx < a[i]) lasx = a[i];
                else return true;
            }
            else {
                if(lasy < a[i]) lasy = a[i];
                else return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1; i <= n; i++) cin >>a[i];

    for(int i = 1; i <= n; i++){
        if(a[i] != i){
            int x;
            for(x = i; a[x + 1] == x + 1 && a[x + 2] != x + 2;) x += 2;
            x = min(x,n);
            if(check(i, x)){
                cout<<"No"<<endl;
                exit(0);
            }
            i = x;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}