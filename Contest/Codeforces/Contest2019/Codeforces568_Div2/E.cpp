#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 2005;
typedef pair<int,int> pii;
int t,n,m;
char mp[maxn][maxn];
int ans[maxn][maxn];





int ind(char c){
    return c - 'a';
}

int abs(int x){
    return x < 0 ? -x : x;
}

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>t;
    while(t--){
        vector<pii> v[30];
        vector<pair<pii,pii> > output;
        cin>>n>>m;
        for(int i = 1; i <= n; i++){
            string s;
            cin>>s;
            for(int j = 0; j < (int) s.size(); j++){
                ans[i][j + 1] = 0;
                mp[i][j + 1] = s[j];
                if('a' <= s[j] && s[j] <= 'z'){
                    int idx = ind(s[j]);
                    v[idx].push_back(pii(i,j + 1));
                }
            }
        }
        for(int i = 0; i < 26; i++) sort(v[i].begin(),v[i].end());
        bool wrong = true;
        for(int i = 0; i < 26; i++){
            if((int) v[i].size() == 0) continue;
            int s_x,s_y,e_x,e_y;
            s_x = v[i][0].first;
            s_y = v[i][0].second;
            e_x = v[i][(int)v[i].size() - 1].first;
            e_y = v[i][(int)v[i].size() - 1].second;
            if(abs(s_x - e_x) >= 1 && abs(s_y - e_y) >= 1){
                wrong = false;
                break;
            }
            
            if(s_x == e_x){
                for(int j = s_y; j <= e_y; j++) ans[s_x][j] = i + 1; 
            }
            else{
                for(int j = s_x; j <= e_x; j++) ans[j][s_y] = i + 1;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!((mp[i][j] == '.' && ans[i][j] == 0) || (ans[i][j] - 1 == (int)(ind(mp[i][j]))))){
                    wrong = false;
                }
                if(!wrong) break;
            }
            if(!wrong) break;
        }
        if(!wrong) {
            cout<<"NO"<<endl;
            continue;

        }
        cout<<"YES"<<endl;
        bool flag = false;
        pair<pii,pii> prev;
        for(int i = 25; i >= 0; i--){
            if(flag && v[i].empty()){
                output.push_back(prev);
                continue;
            }
            else if(!flag && v[i].empty()) continue;
            flag = 1;
            prev = make_pair(pii(v[i][0].first,v[i][0].second),pii(v[i][(int)v[i].size() - 1].first,v[i][(int)v[i].size() - 1].second));
            output.push_back(prev);
        }
        cout<<(int)output.size()<<endl;
        for(int i = (int) output.size() - 1; i >= 0; i--){
            cout<<output[i].first.first<<" "<<output[i].first.second<<" "<<output[i].second.first<<" "<<output[i].second.second<<endl;
        }

    }

    return 0;
}

