#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,k,a[maxn];
string s;

bool check1(){
    int cnt0,cnt1;
    cnt0 = cnt1 = 0;
    for(int i = 1; i <= n; i++){
        cnt0 += (a[i] == 0);
        cnt1 += (a[i] == 1);
    }
    if(cnt0 == 0 || cnt1 == 0 || k >= n) return 1;


    int cnt0_left, cnt1_left,cnt0_right,cnt1_right;
    cnt0_left = cnt0_right = cnt1_left = cnt1_right = 0;

    for(int i = k + 1; i <= n; i++){
       cnt0_right += (a[i] == 0);
       cnt1_right += (a[i] == 1); 
    }

    for(int i = k; i <= n; i++){
        if(cnt0_left == 0 && cnt0_right == 0){
            return true;
        }
        if(cnt1_left == 0 && cnt1_right == 0){
            return true;
        }
        cnt0_right -= (a[i + 1] == 0);
        cnt1_right -= (a[i + 1] == 1);
        cnt0_left += (a[i - k + 1] == 0);
        cnt1_left += (a[i - k + 1] == 1);
    }

    return false;
}

bool check2(){

    int cnt0_left, cnt1_left,cnt0_right,cnt1_right;
    cnt0_left = cnt0_right = cnt1_left = cnt1_right = 0;

    for(int i = k + 1; i <= n; i++){
       cnt0_right += (a[i] == 0);
       cnt1_right += (a[i] == 1); 
    }

    for(int i = k; i <= n; i++){
        if(i == k || i == n){
            if(2 * k >= n){
                cnt0_right -= (a[i + 1] == 0);
                cnt1_right -= (a[i + 1] == 1);
                cnt0_left += (a[i - k + 1] == 0);
                cnt1_left += (a[i - k + 1] == 1);
                continue;

            } 
        }
        if(cnt0_left == 0 && cnt1_right == 0){
        }
        else if(cnt1_left == 0 && cnt0_right == 0){
        }
        else return false;
        cnt0_right -= (a[i + 1] == 0);
        cnt1_right -= (a[i + 1] == 1);
        cnt0_left += (a[i - k + 1] == 0);
        cnt1_left += (a[i - k + 1] == 1);
    }
    return true; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k>>s;
    for(int i = 0; i < n; i++){
        a[i + 1] = (s[i] - '0');
    }

    if(check1()){
        cout<<"tokitsukaze"<<endl;
    }
    else if(check2()){
        cout<<"quailty"<<endl;
    }
    else{
        cout<<"once again"<<endl;
    }

    return 0;
}