#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
map<pii,int> mp;
int n;


int main()
{
    FAST_IO;
    cin>>n;
    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        int k = 0;
        int cntr = 0, cntl = 0;
        for(int j = 0; j < (int) s.size(); j++){
            if(s[j] == ')') k++;
            else k--;
            if(k > 0) {
                k = 0;
                cntr++;
            }
        }
        k = 0;
        for(int j = (int) s.size() - 1; j >= 0; j--){
            if(s[j] == '(') k++;
            else k--;
            if(k > 0){
                k = 0;
                cntl++;
            }
        }
        mp[make_pair(cntl,cntr)]++;        
    }
    int ans = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(!(it->first.first && it->first.second)){
            if(it->first.first == 0 && it->first.second == 0){
                ans += it->second / 2;
                continue;
            }
            if(it->first.first == 0){
                int x = 0;
                x = min(mp[make_pair(it->first.second,0)], it->second);
                ans += x;
                mp[make_pair(it->first.second,0)] -= x;
                it->second -= x;
                cout<<"add "<<x<<endl;
                
            }
            else{
                int x = 0;
                x = min(mp[make_pair(0,it->first.first)], it->second);
                ans += x;
                mp[make_pair(0,it->first.first)] -= x;
                it->second -= x;
                cout<<"add "<<x<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

