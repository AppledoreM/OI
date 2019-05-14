#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

vector<int> col;
map<int,int> mp;
int n;

int main()
{
    FAST_IO;
    cin>>n;
    col.resize(100005);
    int ans = 2;

    for(int i = 1; i <= n; i++){
        int c;
        cin>>c;
        if(col[c]) {
            mp[col[c]]--;
            if(mp[col[c]] == 0){
                mp.erase(mp.find(col[c]));
            }

        }
        col[c]++;
        mp[col[c]]++;
        int cnt = 0;
        
        int f = 0, s = 0;
        int c1 = 0, c2 = 0;
        for(auto it : mp){
            if(it.second != 0) {
                cnt++;
                if(cnt >= 3) break;
                if(!f) {
                    f = it.first;
                    c1 = it.second;
                }
                else{
                    s = it.first;
                    c2 = it.second;
                }
            }
        }
            if((cnt == 1 && f == 1) || (cnt == 1 && c1 == 1)) ans = i;
            else{
                if(cnt == 2){
                    if((f == 1 && c1 == 1)|| (s == 1 && c2 == 1)) {
                        ans = i;
                    }
                    else if((f -s == 1 && c1 == 1) || (s -f == 1 && c2 == 1)){
                        ans = i;
                    }
                }

            }

    }
    cout<<ans<<endl;

        


    return 0;
}
