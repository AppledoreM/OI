#include <bits/stdc++.h>
using namespace std;
int cnt[30];
string s,t,p;
int T;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>T;
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        cin>>s>>t>>p;
        int pos = 0;
        bool ok = true;

        for(char c : s){
            cnt[c - 'a']++;
        }

        for(char c : p){
            cnt[c - 'a']++;
        }

        for(char c : t){
            cnt[c - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(cnt[i] < 0) {
                ok = false;
                break;
            }
        }

        if(!ok) {
            cout<<"NO"<<endl;
            continue;
        }
        ok = false;
    
        for(int i = 0; i < (int) t.size(); i++){
            if(s[pos] == t[i]) pos++;
            if(pos == (int) s.size()){
                ok = true;
            }
        }
        if(!ok) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }

    return 0;
}