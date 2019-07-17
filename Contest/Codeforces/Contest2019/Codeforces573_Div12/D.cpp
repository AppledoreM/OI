#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v;

bool check(){
    if(n >= 2 && v[0] == v[1] && v[0] == 0){
        return true;
    }

    for(int i = 2; i < n; i++){
        if(v[i] == v[i - 1] && v[i - 1] == v[i - 2]) return true;
    }

    for(int i = 2; i < n; i++){
        if(v[i] == v[i - 1] && v[i - 1] == v[i - 2] + 1) return true;
    }

    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i - 1]) cnt++;
    }
    return cnt > 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    if(check()){
        cout<<"cslnb"<<endl;
        exit(0);
    }

    long long sum = 0;
    for(int x : v){
        sum += x;
    }

    if((sum - n * (n - 1) / 2) % 2){
        cout<<"sjfnb"<<endl;
    }
    else cout<<"cslnb"<<endl;

   


    return 0;
}