#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
constexpr int DEBUG = 1;

typedef pair<int,int> pii;
int t;
void debug(vector<int>& u){
        cerr<<"DEBUG: ";
        for(int x : u){
            cerr<<x<<" ";
        } 
        cerr<<endl;
}
void debug(vector<pii>& u){
    cerr<<"DEBUG: ";
    for(auto x : u){
        cerr<<x.first<<" ";
    }
    cerr<<endl;
}

int bfind(vector<int>& v, int x){
    int re = -1;
    for(int i = 0; i < (int) v.size(); i++){
        if(x <= v[i]) re = i;
    }
    return re;
}
map<int,int> mp;
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pii> v;
        for(int i = 1; i <= 2 * n; i++) mp[i] = false;
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            v.emplace_back(pii(x,i));
            mp[x] = true;
        }
        vector<int> u;
        for(auto& it : mp){
            if(it.second == false){
                u.emplace_back(it.first);
            }
        }
        sort(u.begin(),u.end(), greater<int>());
        mp.clear(); 
        bool re = true;
        for(int i = 0; i < (int) v.size(); ++i){
            int a = v[i].first;
            int pos = bfind(u, a);
            if(pos != -1){
                mp[a] = u[pos];
                u.erase(u.begin() + pos);
            }
            else{
                re = false;
                break;
            }
        }
        if(re){
            for(auto x : v){
                cout<<x.first<<" "<<mp[x.first]<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;

    }

    return 0;
}