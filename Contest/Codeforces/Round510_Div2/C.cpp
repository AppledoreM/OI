#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,a[maxn];
int zero_cnt,neg_cnt;
bool used[maxn];
int cnt = 0;
void print_rm(int x){
    used[x] = 1;
    cout<<2<<" "<<x<<endl;
}

void print_any(){
    int st = 0;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            st = i;
            break;
        }
    }
    if(!st) return;
    for(int i = st + 1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            cout<<1<<" "<<i<<" "<<st<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n; i++) {
        cin>>a[i];
        if(a[i] == 0) zero_cnt++;
        else if(a[i] < 0) neg_cnt++;
    }

    if(zero_cnt) {
        int st = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                st = i;
                break;
            }
        }
        for(int i = st + 1; i <= n; i++){
            if(a[i] == 0){
                cnt++;
                used[i] = 1;
                cout<<1<<" "<<i<<" "<<st<<endl;
            }
        }
        if(cnt == n - 1) return 0;
        if(neg_cnt % 2 == 0) print_rm(st);
        else{
            int val = INT_MAX,ch;
            for(int i = 1; i <= n; i++){
                if(a[i] < 0 && abs(a[i]) < abs(val)){
                    val = a[i];
                    ch = i;
                }
            }
            cout<<1<<" "<<ch<<" "<<st<<endl;
            used[ch] = 1;
            cnt++;
            if(cnt == n - 1) return 0;
            print_rm(st);
        }
        print_any();
    }
    else{
        if(neg_cnt & 1) {
            int val = INT_MAX,ch;
            for(int i = 1; i <= n; i++){
                if(a[i] < 0 && abs(a[i]) < abs(val)){
                    val = a[i];
                    ch = i;
                }
            }
            print_rm(ch);
        }
        print_any();
    }

    return 0;
}
