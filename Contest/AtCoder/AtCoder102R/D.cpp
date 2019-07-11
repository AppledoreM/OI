#include <bits/stdc++.h>
using namespace std;
struct ans{
    int a,b,c;
    ans(int _a,int _b,int _c):a(_a),b(_b),c(_c){};
};
vector<ans> v;
map<int,int> mp;
vector<pair<int,int>> G[25];
int way = 0;

int L;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>L;

    int k = log2(L);
    for(int i = 2; i <= k + 1; i++){
        v.emplace_back(ans(i - 1,i,0));
        v.emplace_back(ans(i - 1,i,pow(2,i - 2)));
    }
    int rest = L - pow(2, k);
    int wei = pow(2, k);
    for(int i = k; i >= 1; i--){
        if(rest >= pow(2, i - 1)){
            v.emplace_back(ans(i,k + 1, wei));
            rest -= pow(2, i - 1);
            wei += pow(2,i - 1);
        }
    }
    cout<<k + 1<<" "<<v.size()<<endl;
    for(int i = 0; i < (int) v.size(); i++){
        cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<endl;
    }



    return 0;
}


