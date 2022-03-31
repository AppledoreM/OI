#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int,int> mp;
int main(){

    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    int remain = (n + 1) / 2;
    int res = 0;
    for(auto it : mp){
        if(remain * 2 >= it.second){
            if(it.second % 2 == 1){
                remain -= it.second / 2;
                res += (it.second / 2) * 2;
                it.second = 1;
            }
            else{
                remain -= it.second / 2;
                res += (it.second / 2) * 2;
                it.second = 0;
            }
        }
        else{
           res += remain * 2; 
           remain = 0;
        }
    }
    if(remain){
        for(auto it : mp){
            if(it.second && remain > 0){
                remain--;
                res++;
            }
        }
    }
    cout<<res<<endl;




    return 0;
}