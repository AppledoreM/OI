#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
char vowel[] = {'a', 'e', 'i', 'o', 'u'};
inline int ind(char c){
    return c - 'a';
}
typedef pair<int,int> pii;
typedef pair<string,string> pss;
vector<string> lis_ans;
vector<pss> v;
map<int, vector<string> > words[30];
map<int, int> mp[30];
map<int, vector<string>> exis;
map<int, vector<pss> > ok;
int n;


int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;

    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        int cnt = 0;
        int lst = -1;
        for(int j = 0; j < (int) s.size(); j++){
            for(int k = 0; k < 5 ; k++){
                if(s[j] == vowel[k]) {
                    cnt++;
                    lst = ind(vowel[k]);
                }
            }
        }
        words[lst][cnt].emplace_back(s);
        mp[lst][cnt]++;
    }

    for(int lst = 0; lst < 30; lst++){
        if(mp[lst].empty()) continue;
        for(auto it = words[lst].begin(); it != words[lst].end(); it++){
            if((int)(it->second.size()) % 2 == 1){
                exis[it->first].emplace_back(it->second[0]);
                it->second.erase(it->second.begin());
            }
            for(int i = 0; i * 2 + 1 < (int) it->second.size(); i++){
                 ok[it->first].emplace_back(pss(it->second[i * 2], it->second[i * 2 + 1]));
            }
        }
    } 
    int ans = 0;

    for(auto it = exis.begin(); it != exis.end(); it++){
        int j = 0;
        for(auto it2 = ok.begin(); it2 != ok.end() && j * 2 + 1 < (int) it->second.size();){
            if(it2->second.empty()) {
                it2++;
                continue;
            }
            ans++;
            lis_ans.emplace_back(it->second[j * 2] + " " + it2->second[0].first + "\n" + it->second[j * 2 + 1] + " "+ it2->second[0].second);
            it2->second.erase(it2->second.begin());
            j++;
        }
    }

    for(auto it = ok.begin(); it != ok.end(); it++){
        for(int i = 0; i < (int) it->second.size(); i++){
            v.emplace_back(it->second[i]);
        }        
    }

    for(int i = 0; i * 2 + 1 < (int) v.size(); i++){
        ans++;
        lis_ans.emplace_back(v[i * 2].first + " " + v[i * 2 + 1].first + "\n" + v[i * 2].second + " "+ v[i * 2 + 1].second);
    }
    cout<<ans<<endl;

    for(auto x : lis_ans){
        cout<<x<<endl;
    }



    return 0;
}

