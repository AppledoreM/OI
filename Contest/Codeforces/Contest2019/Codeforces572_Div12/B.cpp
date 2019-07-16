#include <iostream>
#include <stdio.h> 
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
int n;
vector<int> v;
vector<int> ans_lis;



int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        v.emplace_back(x);
    }
    sort(v.begin(),v.end());
    for(int i = (int) v.size() - 1; i >= 0; i--){
        if(i % 2 == 0){
            ans_lis.insert(ans_lis.begin(), v[i]);
        }
        else ans_lis.emplace_back(v[i]);
    }
    bool flag = true;
    if(ans_lis[0] >= ans_lis.back() + ans_lis[1]) flag = false;
    if(ans_lis.back() >= ans_lis[0] + ans_lis[(int) ans_lis.size() - 2]) flag = false;
    for(int i = 1; i + 1 < (int) ans_lis.size() && flag; i++){
        if(ans_lis[i] >= ans_lis[i + 1] + ans_lis[i - 1]) flag = false;
    }
    if(!flag) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i < (int) ans_lis.size(); i++) cout<<ans_lis[i]<<" ";
        cout<<endl;
    }


    return 0;
}

