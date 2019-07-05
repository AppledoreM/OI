#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 2e5 + 10;
map<int,int> mp;
typedef long long ll;
int n,a[maxn],b[maxn];

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>b[i];
    for(int i = 1; i <= n; i++) cin>>a[i];
    int x = a[n];
    int lst_index = n;
    if(x){
        bool ok = true;
        while(lst_index >= 1){
            if(x - (n - lst_index) != a[lst_index]){
                ok = false;
                break;
            }
            if(a[lst_index] == 1) break;
            lst_index--;
        }
        if(a[lst_index] == 1 && ok){
            for(int i = lst_index; i <= n; i++) mp[a[i]] = 1;
            for(int i = 1; i <= n; i++) mp[b[i]] = 1;
            bool flag = true;
            for(int i = x + 1; i <= n; i++){
                mp[a[i - x - 1]] = 1;
                if(!mp[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<lst_index - 1<<endl;
                exit(0);
            }
        }

    }
    mp.clear();
    for(int i = 1; i <= n; i++) mp[b[i]] = 0;
    for(int i = 1; i <= n; i++) mp[a[i]] = i;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!mp[i]) continue;
        ans = max(ans, mp[i] - a[mp[i]] + 1);
    }
    cout<<ans + n<<endl;

    return 0;
}

