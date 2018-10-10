#include <bits/stdc++.h>
using namespace std;
int n;
map<int,int>mp1,mp2;
vector<int> v;


tuple<int,int,int> fd_mx(map<int,int> mp){
    vector<int> tmp;
    int val = 0;
    int mx = 0;
    for(auto it : mp){
        if(mx < it.second){
            mx = it.second;
            val = it.first;
        }
        tmp.emplace_back(it.second);
    }
    sort(tmp.begin(),tmp.end(),[=](int x,int y){return x > y;});
    int f = tmp[0];
    int s = 0;
    if(tmp.size() > 1) s = tmp[1];

    return tuple<int,int,int>(val,f,s);
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    for(int i = 1; i <= n; i++){
        if(i & 1) mp1[v[i]]++;
        else mp2[v[i]]++;
    }
    int ans = n;
    auto re1 = fd_mx(mp1);
    auto re2 = fd_mx(mp2);
    if(get<0>(re1) != get<0>(re2)) ans -= get<1>(re1) + get<1>(re2);
    else ans -= max(get<1>(re1),get<1>(re2)) + max(get<2>(re1), get<2>(re2));
    cout<<ans<<endl;
    return 0;
}
